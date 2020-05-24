#ifndef SNACK_H
#define SNACK_H

#include "Header.h"

class Snack
{
private:
	Toado Head;
	Toado Last;
	int len;
	char Hinhdang;
	bool isDie;
	Events Grad;
	vector <Khuc> Ran;
public:
	Snack();
	~Snack();
public:
	int getLen()	;
	bool getIsDie()	;
	Events getGrad()	;
	Toado getHead()		;
	vector <Khuc> getList()		;
	void setGrad(Events Grad)	;
public:
	void Hide();
	void Show();
	void ShowHead();
	void ShowAll();
	void AddtoList(Khuc * khuc);
	bool isEat(ListMoi * list);
	bool isDam(Snack * snack);
	bool isDam(ListSnack * list);
	bool isDam(Map * map);
	void UpGrade(Map * map, ListSnack * listSnack, ListMoi * listMoi);
	void Rep(Events event);
};


#endif
