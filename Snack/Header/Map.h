#ifndef MAP_H
#define MAP_H

#include "Header.h"

class Map
{
public:
	Toado Vitri;
	Toado Size;
	char Hinhdang;
	bool ** map;
public:
	Map();	
	~Map();
public:
	void SetMap(bool ** map);
	void SetHinhdang(char Hinhdang);
	void Show();
	void Init();
};



#endif
