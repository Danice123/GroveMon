#include "GroveMon.h"

const std::string images[] = { "" };
const int nTextures = 0;

GroveMon::GroveMon() {
	textures = new TextureManager[nTextures];
}

GroveMon::~GroveMon() {
    releaseAll();
}

//=============================================================================
// Initializes the game
// Throws GameError on errorim
//=============================================================================
void GroveMon::initialize(HWND hwnd) {
    Game::initialize(hwnd);
	for (int i = 0; i < nTextures; i++) {
		if (!textures[i].initialize(graphics, images[i].c_str())) 
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing texture"));
	}
	text.initialize(graphics, 12, false, false, "Cambria");
}

//=============================================================================
// Update all game items
//=============================================================================
void GroveMon::update() {

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
    graphics->spriteBegin();                // begin drawing sprites
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