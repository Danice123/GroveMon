#ifndef _GROVEMON__
#define _GROVEMON__
#define WIN32_LEAN_AND_MEAN

#include "game.h"
#include "graphics.h"
#include "entity.h"
#include "textureManager.h"
#include "textDX.h"
#include "audio.h"
#include "BattleSystem.h"

class GroveMon : public Game {
public:
	GroveMon();

	virtual ~GroveMon();

    void initialize(HWND hwnd);
    void update();
    void ai();
    void collisions();
    void render();
    void releaseAll();
    void resetAll();
private:
	TextureManager* textures;
	TextDX text;
	BattleSystem* bs;
	std::string textbox;
	int index;
	bool selected;

	Image background;
	Image textBoxBack;
	Image liz;
	Image din;
	Image tur;
};
#endif