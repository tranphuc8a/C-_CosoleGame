#ifndef MAP_H
#define MAP_H

#include "Header.h"

class Map : public BaseObject
{
public:
	int type;
	
	Toado toadoMainObject;
	Toado toadoThreat;
public:
	Map();
	~Map();
public:
	void Setlink();
	void ShowMenuInit();
	void LoopOption();
	void Init();
public:
	int getType();
	Toado getToadoMainObject();
	Toado getToadoThreat();
	
	void setType(int type);
	void setToadoMainObject(Toado toadoMainObject);
	void setToadoThreat(Toado toadoThreat);
};


#endif
