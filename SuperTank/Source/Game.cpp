#ifndef GAME_CPP
#define GAME_CPP

#include "../Header/Header.h"

Game::Game()
{
	menu1 = new Menu("Init", Toado(5, 3));
	menu2 = new Menu("Start", Toado(5, 4));
	menu3 = new Menu("Quit", Toado(5, 5));
	
	obj = new Object;
}
Game::~Game(){};

void Game::Setlink()
{
	menu1->Next = menu3->Pri = menu2;
	menu2->Next = menu1->Pri = menu3;
	menu3->Next = menu2->Pri = menu1;
	
	pNow = menu1;
}

void Game::Show()
{
	System.clrscr();
	System.gotoXY(5, 0); cout << "GAME SUPER TANK" << endl;
	System.Goto(menu1->GetToado()); cout << menu1->GetName() << endl;
	System.Goto(menu2->GetToado()); cout << menu2->GetName() << endl;
	System.Goto(menu3->GetToado()); cout << menu3->GetName() << endl;
	point->ShowBefore(pNow->GetToado());
}

void Game::LoopOption()
{
	while (1)
	{
		Events key = (Events) getch();
		switch (key)
		{
			case ESC: return;
			case UP: case LEFT: pNow = pNow->Pri; break;
			case DOWN: case RIGHT: pNow = pNow->Next; break;
			case ENTER:
				if (pNow == menu1) this->Init();
				else if (pNow == menu2) this->Start();
				else this->Quit();
				this->Show();
				break;
		}
		point->ShowBefore(pNow->GetToado());
	}
}

void Game::Init()
{
	obj->Init();	
}

void Game::Start()
{
	obj = new Object;
	obj->Start();
}

void Game::Quit()
{
	exit(0);
}

void Game::Main()
{
	Setlink();
	Show();
	LoopOption();
}




#endif
