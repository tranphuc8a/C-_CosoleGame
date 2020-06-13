#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include "Header.h"

class BaseObject : public Menu
{
protected:
	Toado Vitri;
	Toado Size;
	bool ** Hinhdang;
	char Kitu;
	vector <Menu * > menu;
	bool isDie;
	Events Grad;
	int tocdo;
public:
	BaseObject();
	~BaseObject();
public:
	Toado getVitri();
	Toado getSize();
	bool ** getHinhdang();
	char getKitu();
	bool getIsDie();
	bool Die();
	int getTocdo();
	Events getGrad();
	
	void setVitri(int x, int y);
	void setVitri(Toado Vitri);
	void setSize(int x, int y);
	void setSize(Toado Size);
	void setHinhdang(bool ** Hinhdang);
	void setKitu(char Kitu);
	void setTocdo(int tocdo);
	void setGrad(Events Grad);
	void setIsDie(bool isDie);
public:
	void Setlink(){};
	void ShowMenuInit(){};
	void LoopOption(){};
	void Init(){};
	
public:
	void Hide();
	void Show();
	void Show(int x, int y);
	void Show(Toado Vitri);
	
	void UpGrade(TimeStart & Start, Object * obj){};
	void RepEvent(Events event, Object * obj){};
	
	bool isCham(BaseObject * obj);
	bool isChamMap(Map * map);
	
//	virtual bool IsDie(Object * obj) = 0;
	
public:		// Go
	void GoStraight();
	void TurnBack();
	void TurnLeft();
	void TurnRight();
};

#endif
