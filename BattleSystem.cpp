#include "BattleSystem.h"
#include <sstream>
#include "Skill.h"

BattleSystem::~BattleSystem() {
	CloseHandle(handle);
}

void BattleSystem::start() {
	unsigned tid;
	handle = (HANDLE) _beginthreadex(0, 0, run, this, CREATE_SUSPENDED, &tid);
	ResumeThread(handle);
}

void textOut(BattleSystem* bs, std::unique_lock<std::mutex>& lk, std::string text) {
	bs->accepted = false;
	bs->state = 1;
	bs->output = text;
	
	bs->cv.wait(lk, [bs] { return bs->accepted; } );
	bs->state = 0;
}

int getPlayerInput(BattleSystem* bs, std::unique_lock<std::mutex>& lk) {
	bs->playerInput = 0;
	bs->accepted = false;
	bs->state = 2;
	bs->cv.wait(lk, [bs] { return bs->accepted; } );
	bs->state = 0;
	return bs->playerInput;
}

unsigned __stdcall run(void* args) {
	BattleSystem* bs = (BattleSystem*) args;
	std::unique_lock<std::mutex> lk(bs->mutex);
	std::stringstream s;
	int damage = 0;
	int turn = -1;

	textOut(bs, lk, "Battle Start!");
	do {
		if (turn == -1) {
			turn = bs->player->getSpeed() >= bs->enemy->getSpeed();
		}

		if (turn != 0) {
			int c = getPlayerInput(bs, lk);
			switch(c) {
			case 1:
				s.str("");
				s << "The Player's " << bs->player->getName() << " attacks!";
				textOut(bs, lk, s.str());
	
				damage = bs->player->getAttack() - bs->enemy->getDefense();
				bs->enemy->damageMonster(damage, bs->player->getType());

				s.str("");
				s << "The Enemy's " << bs->enemy->getName() << " takes " << damage << " damage!";
				textOut(bs, lk, s.str());
				break;
			default:
				Skill* skill = bs->player->getSkills()[c - 2];
				s.str("");
				s << "The Player's " << bs->player->getName() << " uses " << skill->getName() << "!";
				textOut(bs, lk, s.str());

				skill->apply(bs->enemy);

				textOut(bs, lk, skill->describe(bs->player));

				bs->player->modifyCurrentMana(-skill->getManaCost());
				break;
			}

			if (bs->enemy->getCurrentHealth() == 0) {
				s.str("");
				s << "The Enemy's " << bs->enemy->getName() << " is defeated!";
				textOut(bs, lk, s.str());
				break;
			}

			turn = 0;
			if (bs->player->getSpeed() < bs->enemy->getSpeed()) turn = -1;
		} else {
			s.str("");
			s << "The Enemy's " << bs->enemy->getName() << " attacks!";
			textOut(bs, lk, s.str());

			damage = bs->enemy->getAttack() - bs->player->getDefense();
			bs->player->damageMonster(damage, bs->enemy->getType());

			s.str("");
			s << "The Player's " << bs->player->getName() << " takes " << damage << " damage!";
			textOut(bs, lk, s.str());

			if (bs->player->getCurrentHealth() == 0) {
				textOut(bs, lk, "You are defeated!");
				break;
			}

			turn = 1;
			if (bs->player->getSpeed() >= bs->enemy->getSpeed()) turn = -1;
		}

	} while(true);
	return 0;
}