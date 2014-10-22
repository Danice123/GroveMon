#include "GroveMon.h"
#include "TestMonster.h"

const std::string images[] = { "" };
const int nTextures = 0;

GroveMon::GroveMon() {
	textures = new TextureManager[nTextures];

	bs = new BattleSystem(new test(), new test());

	textbox = "";
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
		textbox = "Push an input key";
		if (input->wasKeyPressed(VK_SPACE) && !bs->accepted) {
			bs->playerInput = 1;
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

	text.print(textbox, 0, 300);
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