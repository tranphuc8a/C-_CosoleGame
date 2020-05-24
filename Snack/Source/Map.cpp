#ifndef MAP_CPP
#define MAP_CPP

#include "../Header/Map.h"

Map::Map()
{
	Vitri = Toado(0, 0);
	Size = Toado(30, 20);
	Hinhdang = '*';
	string c[30] = {	"11111111111111111111\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"10000000000000000001\n",
						"11111111111111111111\n"};
	map = new bool*[this->Size.x];
	for (int i = 0; i<this->Size.x; i++)
	{
		map[i] = new bool[this->Size.y];
		for (int j = 0; j<this->Size.y; j++)
		{
			if(c[i][j] == '1') map[i][j] = true;
			else map[i][j] = false;
		}
	}
}	
Map::~Map(){};
void Map::SetMap(bool ** map)
{
	this->map = map;
}
void Map::SetHinhdang(char Hinhdang)
{
	this->Hinhdang = Hinhdang;
}
void Map::Show()
{
	for (int j = 0; j<this->Size.y; j++)
	{
		System.gotoXY(this->Vitri.x, this->Vitri.y + j);
		for (int i = 0; i<this->Size.x; i++)
		{
			if (this->map[i][j]) cout << this->Hinhdang;
			else cout << ' ';
		}
		cout << endl;
	}	
}
void Map::Init()
{
	
}


#endif
