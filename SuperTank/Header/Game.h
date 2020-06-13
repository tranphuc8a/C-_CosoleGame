#ifndef GAME_H
#define GAME_H

#include "Header.h"

class Game : public Menu
{
private:
	Menu * menu1, * menu2, * menu3;
	Object * obj;
public:
	Game();
	~Game();
public:
	void Setlink();
	void Show();
	void LoopOption();
	
	void Init();
	void Start();
	void Quit();
	
	void Main();	
};

#endif
