#ifndef __BattleSystem_
#define __BattleSystem_

#include <windows.h>
#include <process.h>
#include <mutex>
#include <condition_variable>
#include <string>
#include "Monster.h"

class BattleSystem {
public:
	BattleSystem(Monster* p, Monster* e): player(p), enemy(e), state(0), output("") {}
	~BattleSystem();

	void start();

	int getState() { return state; }
	std::string getOutput() { return output; }
	Monster* getPlayer() { return player; }
	Monster* getEnemy() { return enemy; }

	bool accepted;
	int playerInput;
	std::condition_variable cv;
private:
	Monster* player;
	Monster* enemy;

	int state;

	std::string output;

	bool needsInput;
	int input;

	HANDLE handle;
	std::mutex mutex;
	
	friend unsigned __stdcall run(void* args);
	friend void textOut(BattleSystem* bs, std::unique_lock<std::mutex>& lk, std::string text);
	friend int getPlayerInput(BattleSystem* bs, std::unique_lock<std::mutex>& lk);
};
#endif