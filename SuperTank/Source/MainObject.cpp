#ifndef MAINOBJECT_CPP
#define MAINOBJECT_CPP

#include "../Header/Header.h"

MainObject::MainObject()
{
	List = new ListAmo;
	List->setOwner(this);
	Vitri = Toado(1, 1);
	Size = Toado(3, 3);
	string hinhdang[3] = {	"101",
							"010",
							"101"	};
	Kitu = '*';
	this->Hinhdang = new bool * [Size.x + 1];
	for (int i = 0; i<Size.x; i++)
	{
		Hinhdang[i] = new bool[Size.y + 1];
		for (int j = 0; j<Size.y; j++)
		{
			if (hinhdang[i][j] == '1') Hinhdang[i][j] = 1;
			else Hinhdang[i][j] = 0;
		}
	}
	this->tocdo = 200;
};
MainObject::~MainObject()
{
	
};

void MainObject::Ban(Map * map)
{
	this->List->AddtoList(map);
};
bool MainObject::isBanTrung(BaseObject * obj)
{
	for (int i = 1; i<=List->getSoluong(); i++)
	{
		if (this->List->getList()[i]->isBanTrung(obj)) return true;
	}
	return false;
};
bool MainObject::isBiBanTrung(Object * obj)
{
	vector <Threat * > list = obj->listThreat->getList();
	for (int i = 1; i<list.size(); i++)
	{
		if (list[i]->isBanTrung(this)) return true;
	}
	return false;
}


void MainObject::UpGrade(TimeStart & Start, Object * obj)
{
	this->List->UpGrade(Start, obj);
	int Now = clock();
	if (Now - Start.MainObject < this->tocdo) return;
	if (this->isBiBanTrung(obj))
	{
		this->isDie = true;
		this->Hide();
		return;
	}
	Start.MainObject = clock();
	this->Show();
};

void MainObject::RepEvent(Events event, Object * obj)
{
	switch (event)
	{
		case ESC: exit(0);
		case LEFT: case RIGHT: case UP: case DOWN:
			this->Grad = event;
			if (!isChamMap(obj->map))
				GoStraight();
			break;
		case ENTER: case SPACE:
			this->Ban(obj->map);
			break;
	}
	
};




#endif
