#ifndef GAME_H
#define GAME_H

#include "Header.h"

class Game : public Menu
{
public:
	int tocdo;
	
	int result;
	Map * map;
	ListMoi * listMoi;
	ListSnack * listSnack;
	int option;
	
	Menu * menu1;
	Menu * menu2;
	Menu * menu3;
public:
	Game();
	~Game();
public:
	void LoopOption();
	void Init();
	void SetDefault();
	bool isEndGame();
	void Start();
	void GameLoop();
	void Result();
	void Show();
	void Main();
};


#endif
