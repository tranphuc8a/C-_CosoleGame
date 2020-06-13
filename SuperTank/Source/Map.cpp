#ifndef MAP_CPP
#define MAP_CPP

#include "../Header/Header.h"


Map::Map()
{
	this->type = 1;
	this->Vitri = Toado(0, 0);
	this->Size = Toado(20, 40);
	this->Hinhdang = new bool * [Size.x];
	for (int i = 0; i<this->Size.x; i++)
	{
		Hinhdang[i] = new bool[Size.y];
		for (int j = 0; j<Size.y; j++)
		{
			if (i == 0 || j == 0 || i == Size.x - 1 || j == Size.y - 1)
			{
				Hinhdang[i][j] = 1;
			}
			else Hinhdang[i][j] = 0;
		}
	}
	this->toadoMainObject = Toado(Vitri.x + 1, Vitri.y + 1);
	this->toadoThreat = Toado(Vitri.x + Size.x - 5, Vitri.y + Size.y - 5);
	
	menu.resize(5);
	string Name = "Map ";
	char index = '0';
	for (int i = 1; i<=4; i++)
	{
		index ++;
		menu[i] = new Menu(Name + index, Toado(5, 2 + i));
	}
	
};
Map::~Map(){};

int Map::getType()
{
	return this->type;
};
Toado Map::getToadoMainObject()
{
	return this->toadoMainObject;
};
Toado Map::getToadoThreat()
{
	return this->toadoThreat;
};

void Map::setType(int type)
{
	this->type = type;
};
void Map::setToadoMainObject(Toado toadoMainObject)
{
	this->toadoMainObject = toadoMainObject;
};
void Map::setToadoThreat(Toado toadoThreat)
{
	this->toadoThreat = toadoThreat;
};

void Map::Setlink()
{
	pNow = menu[1];
	menu[1]->Next = menu[3]->Pri = menu[2];
	menu[2]->Next = menu[4]->Pri = menu[3];
	menu[3]->Next = menu[1]->Pri = menu[4];
	menu[4]->Next = menu[2]->Pri = menu[1];
};
void Map::ShowMenuInit()
{
	System.clrscr();
	System.gotoXY(5, 0); cout << "Initialization Map" << endl;
	for (int i = 1; i<=4; i++)
	{
		System.Goto(menu[i]->GetToado()); cout << menu[i]->GetName();
	}
	point->ShowBefore(pNow->GetToado());
};
void Map::LoopOption()
{
	while (1)
	{
		Events key = (Events) getch();
		switch (key)
		{
			case ESC: exit(0);
			case UP: case LEFT: pNow = pNow->Pri; break;
			case DOWN: case RIGHT: pNow = pNow->Next; break;
			case ENTER:
				for (int i = 1; i<=4; i++)
				{
					if (pNow == menu[i])
					{
						type = i;
						// Set map i for default map
					}
				}
				return;
		}
		point->ShowBefore(pNow->GetToado());
	}
};
void Map::Init()
{
	Setlink();
	ShowMenuInit();
	LoopOption();
};


#endif
