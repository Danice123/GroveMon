#include "GroveMon.h"
#include "lizard.h"
#include "turtle.h"
#include "dinosaur.h"

#include "fireball.h"
#include "leafcut.h"
#include "wave.h"
#include "AxeTwerk.h"
#include "leer.h"
#include "restore.h"

const std::string images[] = { "pics/blastoise.png", "pics/ven.png", "pics/charizard.png", "pics/background.png", "pics/box.png" };
const int nTextures = 5;

Lizard* lizard;
Turtle* turtle;
Dinosaur* dino;

GroveMon::GroveMon() {
	textures = new TextureManager[nTextures];

	lizard = new Lizard();
	lizard->addSkill(new Fireball());
	lizard->addSkill(new AxeTwerk());

	turtle = new Turtle();
	turtle->addSkill(new Wave());
	turtle->addSkill(new leer());


	dino = new Dinosaur();
	dino->addSkill(new LeafCut());
	dino->addSkill(new Restore());


	
	selected = false;
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

	background.initialize(graphics, 0, 0, 0, &textures[3]);
	background.setX(0);
	background.setY(0);

	textBoxBack.initialize(graphics, 0, 0, 0, &textures[4]);
	textBoxBack.setX(0);
	textBoxBack.setY(290);
	textBoxBack.setScale(GAME_WIDTH / textBoxBack.getWidth());

	liz.initialize(graphics, 0, 0, 0, &textures[2]);
	liz.setScale(0.5);
	lizard->image = &liz;

	tur.initialize(graphics, 0, 0, 0, &textures[0]);
	tur.setScale(0.5);
	turtle->image = &tur;

	din.initialize(graphics, 0, 0, 0, &textures[1]);
	din.setScale(0.5);
	dino->image = &din;
}

int manaOutTimer = 0;
//=============================================================================
// Update all game items
//=============================================================================
void GroveMon::update() {
	if(!selected)
	{
		if (input->wasKeyPressed(VK_UP) && index > 0) index--;
		if (input->wasKeyPressed(VK_DOWN) && index < 2) index++;

		if (input->wasKeyPressed(VK_SPACE) ) {
			if (index == 0)
			{
				bs = new BattleSystem(lizard, dino);
			}
			else if (index == 1)
			{
				bs = new BattleSystem(dino, turtle);
			}
			else if (index == 2)
			{
				bs = new BattleSystem(turtle, lizard);
			}	
			index = 0;
			selected = true;
			bs->start();
			bs->getPlayer()->image->setX(10);
			bs->getPlayer()->image->setY(140);

			bs->getEnemy()->image->setX(340);
			bs->getEnemy()->image->setY(20);
		}
		return;
	}
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
	if (!selected) {
		graphics->spriteBegin(); 
		text.print("Choose Lizard", 40, 100);
		text.print("Choose Dinosaur", 40, 124);
		text.print("Choose Turtle", 40, 148);
		text.print("-", 20, 100 + index * 24);
		graphics->spriteEnd();
		return;
	}

	std::stringstream s;
    graphics->spriteBegin();                // begin drawing sprites
	background.draw();

	bs->getEnemy()->image->draw();
	bs->getPlayer()->image->draw();

	textBoxBack.draw();

	text.print(bs->getEnemy()->getName(), 0, 0);
	s << "HP: " << bs->getEnemy()->getCurrentHealth() << '/' << bs->getEnemy()->getHealth();
	text.print(s.str(), 0, 36);

	text.print(bs->getPlayer()->getName(), 300, 200);
	s.str("");
	s << "HP: " << bs->getPlayer()->getCurrentHealth() << '/' << bs->getPlayer()->getHealth();
	text.print(s.str(), 350, 236);
	s.str("");
	s << "Mana: " << bs->getPlayer()->getCurrentMana() << '/' << bs->getPlayer()->getMana();
	text.print(s.str(), 350, 265);

	text.print(textbox, 40, 300);

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