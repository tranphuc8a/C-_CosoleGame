#ifndef OBJECT_H
#define OBJECT_H

#include "Header.h"


class Object : public Menu
{
public:
	int result;
	ListMainObject * listMObj;
	ListThreat * listThreat;
	Map * map;
	
	vector <Menu * > menu;
	TimeStart start;
public:
	Object();
	~Object();
public:
	void Setlink();
	void ShowMenuInit();
	void LoopOption();
	
	void Init();
	
	void ShowObject();
	void UpGrade(TimeStart & Start, Object * obj);
	void RepEvent(Events event, Object * obj);
	bool isEndGame();
	void LoopGame();
	
	void Start();
	
	void Result();
};


#endif
