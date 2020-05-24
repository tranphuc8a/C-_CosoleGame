#ifndef GAME_CPP
#define GAME_CPP

#include "../Header/Game.h"

Game::Game()
{	
	tocdo = 100;
	
	map = new Map;
	listMoi = new ListMoi;
	listSnack = new ListSnack;
	
	option = 1;
	menu1 = new Menu("Init", Toado(5, 3));
	menu2 = new Menu("Start", Toado(5, 4));
	menu3 = new Menu("Quit", Toado(5, 5));
	
	this->pNow = menu1;
	menu1->Next = menu3->Pri = menu2;
	menu2->Next = menu1->Pri = menu3;
	menu3->Next = menu2->Pri = menu1;
}
void Game::SetDefault()
{
	tocdo = 100;
	
	map = new Map;
	listMoi = new ListMoi;
	listSnack = new ListSnack;
}
Game::~Game(){}


void Game::LoopOption()
{
	while (1)
	{
		Events key = (Events) getch();
		switch (key)
		{
			case ESC:
				exit(0);
				break;
			case UP: case LEFT:
				pNow = pNow->Pri; break;
			case DOWN: case RIGHT:
				pNow = pNow->Next; break;
			case ENTER:
				if (pNow == menu1)
				{
					Init();
					this->Show();
				}
				else if (pNow == menu2)
				{
					Start();
					this->Show();
				}
				else return;
				break;
		}
		this->point->ShowBefore(pNow->GetToado());
	}
}
void Game::Init()
{
	SetDefault();
	
	Menu * M1, * M2, * M3, * M4, * M5, * Now;
	M1 = new Menu("Speed: ", Toado(5, 2));
	M2 = new Menu("Init Map", Toado(5, 3));
	M3 = new Menu("Init Snack", Toado(5, 4));
	M4 = new Menu("Init Food", Toado(5, 5));
	M5 = new Menu("OK", Toado(5, 6));
	
	Now = M1;
	M1->Next = M3->Pri = M2;
	M2->Next = M4->Pri = M3;
	M3->Next = M5->Pri = M4;
	M4->Next = M1->Pri = M5;
	M5->Next = M2->Pri = M1;
	
	Pointer * P = new Pointer;
	
	System.clrscr();
	System.Goto(Toado(5, 0)); cout << "Initialization" << endl;
	System.Goto(M1->GetToado()); cout << M1->GetName();
	System.Goto(M2->GetToado()); cout << M2->GetName();
	System.Goto(M3->GetToado()); cout << M3->GetName();
	System.Goto(M4->GetToado()); cout << M4->GetName();
	System.Goto(M5->GetToado()); cout << M5->GetName();
	P->ShowBefore(Now->GetToado());
	
	while (1)
	{
		Events key = (Events) getch();
		switch (key)
		{
			case ESC: exit(0);
			case UP: case LEFT: Now = Now->Pri; break;
			case DOWN: case RIGHT: Now = Now->Next; break;
			case ENTER:
				if (Now == M1)
				{
					if (tocdo == 500)
					{
						tocdo = 300;
						System.Goto(Toado(12, 2)); cout << "\t\t";
						System.Goto(Toado(12, 2)); cout << "Slow";
					}
					else if (tocdo == 300)
					{
						tocdo = 100;
						System.Goto(Toado(12, 2)); cout << "\t\t";
						System.Goto(Toado(12, 2)); cout << "Normal";
					}
					else if (tocdo == 100)
					{
						tocdo = 60;
						System.Goto(Toado(12, 2)); cout << "\t\t";
						System.Goto(Toado(12, 2)); cout << "Fast";
					}
					else if (tocdo == 60)
					{
						tocdo = 30;
						System.Goto(Toado(12, 2)); cout << "\t\t";
						System.Goto(Toado(12, 2)); cout << "Very Fast";
					}
					else
					{
						tocdo = 500;
						System.Goto(Toado(12, 2)); cout << "\t\t";
						System.Goto(Toado(12, 2)); cout << "Very Slow";
					}
					break;
				}
				else if (Now == M2)
				{
					map->Init();
				}
				else if (Now == M3)
				{
					listSnack->Init();
				}
				else if (Now == M4)
				{
					listMoi->Init();
				}
				else if (Now == M5)
				{
					return;
				}
				System.clrscr();
				System.Goto(Toado(5, 0)); cout << "Initalization" << endl;
				System.Goto(M1->GetToado()); cout << M1->GetName();
				System.Goto(M2->GetToado()); cout << M2->GetName();
				System.Goto(M3->GetToado()); cout << M3->GetName();
				System.Goto(M4->GetToado()); cout << M4->GetName();
				System.Goto(M5->GetToado()); cout << M5->GetName();
		}
		P->ShowBefore(Now->GetToado());
	}
}
bool Game::isEndGame()
{
	return this->listSnack->getSoluong() == 0;
}
void Game::Start()
{	
	// Show all the object of games
	System.clrscr();
	map->Show();
	listMoi->Show();
	listSnack->Show();
	
	getch();
	GameLoop();
	Result();
	SetDefault();
}
void Game::GameLoop()
{
	bool onetime = 0;
	int Start = clock();
	while (1)
	{
		if (isEndGame()) break;
		this->result = this->listSnack->getList()[0].getLen() - 3;
		int Now = clock();
		
		if (Now - Start >= tocdo)
		{
			if (!onetime)
			{
				listMoi->UpGrade(map, listSnack, listMoi);	
				listSnack->UpGrade(map, listSnack, listMoi);
			}
			
			onetime = 0;
			Start = clock();
		}
			
		if (kbhit())
		{
			Events event = (Events) getch();
			while (event == 224) event = (Events) getch();
			if (!(event == UP || event == DOWN || event == LEFT || event == RIGHT)) continue;
			listSnack->Rep(event);
			Sleep(tocdo);
			listSnack->UpGrade(map, listSnack, listMoi);
			onetime = 1;
		}
	}
}
void Game::Result()
{
	System.clrscr();
	cout << "Your score: " << this->result << endl;
	getch();
}
void Game::Show()
{
	System.clrscr();
	System.gotoXY(5, 0); cout << "GAME SNACKER" << endl;
	System.Goto(menu1->GetToado()); cout << menu1->GetName();
	System.Goto(menu2->GetToado()); cout << menu2->GetName();
	System.Goto(menu3->GetToado()); cout << menu3->GetName();
	point->ShowBefore(pNow->GetToado());
}
void Game::Main()
{
	System.HidePtr();
	this->Show();
	this->LoopOption();
}


#endif
