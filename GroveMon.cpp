#include "GroveMon.h"
#include "lizard.h"
#include "turtle.h"
#include "fireball.h"

const std::string images[] = { "" };
const int nTextures = 0;

GroveMon::GroveMon() {
	textures = new TextureManager[nTextures];

	Lizard* player = new Lizard();
	player->addSkill(new Fireball());

	bs = new BattleSystem(player, new Turtle());

	textbox = "";
	index = 0;
}

GroveMon::~GroveMon() {
    releaseAll();
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void GroveMon::initialize(HWND hwnd) {
    Game::initialize(hwnd);
	for (int i = 0; i < nTextures; i++) {
		if (!textures[i].initialize(graphics, images[i].c_str())) 
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing texture"));
	}
	text.initialize(graphics, 24, false, false, "Cambria");

	bs->start();
}

int manaOutTimer = 0;
//=============================================================================
// Update all game items
//=============================================================================
void GroveMon::update() {
	switch(bs->getState()) {
	case 0:
		textbox = "";
		break;
	case 1:
		textbox = bs->getOutput();
		if (input->wasKeyPressed(VK_SPACE) && !bs->accepted) {
			bs->accepted = true;
			bs->cv.notify_one();
		}
		break;
	case 2:
		if (manaOutTimer > 0) {
			textbox = "Your Monster doesn't have the mana for that!";
			manaOutTimer--;
		} else textbox = "Push an input key";

		if (input->wasKeyPressed(VK_UP) && index > 0) index--;
		if (input->wasKeyPressed(VK_DOWN) && index < bs->getPlayer()->getSkills().size()) index++;

		if (input->wasKeyPressed(VK_SPACE) && !bs->accepted) {
			if (index > 0 && bs->getPlayer()->getSkills()[index - 1]->getManaCost() > bs->getPlayer()->getCurrentMana()) {
				manaOutTimer = 100;
				break;
			}

			bs->playerInput = index + 1;
			bs->accepted = true;
			bs->cv.notify_one();
		}
		break;
	}
}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void GroveMon::ai()
{}

//=============================================================================
// Handle collisions
//=============================================================================
void GroveMon::collisions() {

}

#include <sstream>
#include "Skill.h"
//=============================================================================
// Render game items
//=============================================================================
void GroveMon::render()
{
	std::stringstream s;
    graphics->spriteBegin();                // begin drawing sprites
	text.print(bs->getEnemy()->getName(), 0, 0);
	s << "HP: " << bs->getEnemy()->getCurrentHealth() << '/' << bs->getEnemy()->getHealth();
	text.print(s.str(), 0, 36);

	text.print(bs->getPlayer()->getName(), 300, 200);
	s.str("");
	s << "HP: " << bs->getPlayer()->getCurrentHealth() << '/' << bs->getPlayer()->getHealth();
	text.print(s.str(), 350, 236);
	s.str("");
	s << "Mana: " << bs->getPlayer()->getCurrentMana() << '/' << bs->getPlayer()->getMana();
	text.print(s.str(), 350, 272);

	text.print(textbox, 0, 300);

	if (bs->getState() == 2) {
		std::vector<Skill*> skills = bs->getPlayer()->getSkills();
		text.print("Attack", 40, 340);
		for (int i = 0; i < skills.size(); i++) {
			text.print("Use " + skills[i]->getName(), 40, 364 + i * 24);
		}
		text.print("-", 10, 340 + index * 24);
	}
    graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void GroveMon::releaseAll()
{
    Game::releaseAll();
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void GroveMon::resetAll()
{
    Game::resetAll();
    return;
}