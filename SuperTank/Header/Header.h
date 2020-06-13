#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include <time.h>



#define MAX		1000

using namespace std;

enum Events
{
	NONE,
	
	number_0 = 48, 	number_1, number_2, number_3, number_4, 
	number_5, 		number_6, number_7, number_8, number_9,
	
	KEY_A = 97, KEY_B, KEY_C, KEY_D, KEY_E, KEY_F, KEY_G, 
				KEY_H, KEY_I, KEY_J, KEY_K, KEY_L, KEY_M, KEY_N, 		
				KEY_O, KEY_P, KEY_Q, KEY_R, KEY_S, KEY_T, KEY_U, 
				KEY_V, KEY_W, KEY_X, KEY_Y, KEY_Z,
				
	BACKSPACE 	= 	8,
	TAB			= 	9,
	ENTER 		= 	13,
	ESC 		= 	27,
	SPACE 		= 	32,
	UP 			= 	72,
	LEFT 		= 	75,
	RIGHT 		= 	77,
	DOWN 		= 	80
};

class Toado
{
public:
	int x;
	int y;
public:
	Toado(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}
	~Toado(){};
public:
	Toado operator + (const Toado & T)
	{
		return Toado(this->x + T.x, this->y + T.y);
	}
	bool operator == (const Toado & toado)
	{
		return this->x == toado.x && this->y == toado.y;
	}
	bool operator != (const Toado & toado)
	{
		return !(*this == toado);
	}
	bool operator > (const Toado & T)
	{
		return this->x > T.x && this->y > T.y;
	}
	bool operator < (const Toado & T)
	{
		return this->x < T.x && this->y < T.y;
	}
	bool operator >= (const Toado & T)
	{
		return this->x >= T.x && this->y >= T.y;
	}
	bool operator <= (const Toado & T)
	{
		return this->x <= T.x && this->y <= T.y;
	}
};

class TimeStart
{
public:
	int MainObject;
	int Threat;
	int Amo;
public:
	TimeStart()
	{
		this->ResetAll();
	}
	~TimeStart(){}
public:
	ResetAll()
	{
		this->Threat = this->Amo = this->MainObject = clock();
	}
	void ResetMainObject()
	{
		this->MainObject = clock();
	}
	void ResetThreat()
	{
		this->MainObject = clock();
	}
	void ResetAmo()
	{
		this->MainObject = clock();
	}
};



#include "System.h"
#include "Pointer.h"
#include "Menu.h"


class BaseObject;
//class Game;


class Map;

class Amo;
class ListAmo;

class MainObject;
class ListMainObject;


class Threat;
class ListThreat;


class Object;

#include "BaseObject.h"
#include "Map.h"
#include "Amo.h"
#include "ListAmo.h"
#include "MainObject.h"
#include "ListMainObject.h"
#include "Threat.h"
#include "ListThreat.h"
#include "Object.h"
#include "Game.h"

#include "../Source/Threat.cpp"
#include "../Source/ListThreat.cpp"
#include "../Source/Map.cpp"
#include "../Source/BaseObject.cpp"
#include "../Source/Amo.cpp"
#include "../Source/ListAmo.cpp"
#include "../Source/MainObject.cpp"
#include "../Source/ListMainObject.cpp"
#include "../Source/Game.cpp"
#include "../Source/Object.cpp"

#endif
