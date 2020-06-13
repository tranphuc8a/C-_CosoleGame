#ifndef THREAT_CPP
#define THREAT_CPP

#include "../Header/Header.h"

Threat::Threat()
{
	List = new ListAmo;
	List->setOwner(this);
	Vitri = Toado(5, 5);
	Size = Toado(3, 3);
	string hinhdang[3] = {	"010",
							"111",
							"010"	};
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
	this->tocdo = 1000;
};
Threat::~Threat(){};

//ListAmo * Threat::getListAmo()
//{
//	return this->List;
//};
vector <Amo * > Threat::getList()
{
	return this->List->getList();
};

bool Threat::Ban(Map * map)
{
	srand(time(0));
	if (!rand() % 5)
	{
		this->List->AddtoList(map);
		return true;
	}
	return false;
};
bool Threat::isBanTrung(BaseObject * obj)
{
	for (int i = 1; i<=List->getSoluong(); i++)
	{
		if (this->List->getList()[i]->isBanTrung(obj)) return true;
	}
	return false;
};
void Threat::UpGrade(TimeStart & Start, Object * obj)
{
	this->List->UpGrade(Start, obj);
	if (isBiBanTrung(obj)) 
	{
		this->isDie = true;
		this->Hide();
		return;
	}
	if (!Ban(obj->map)) RandomGrad(obj->map);
	if (!isChamMap(obj->map)) GoStraight();
	this->Show();
};

bool Threat::isBiBanTrung(Object * obj)
{
	vector <MainObject * > list = obj->listMObj->getList();
	for (int i = 1; i<list.size(); i++)
	{
		if (list[i]->isBanTrung(this)) return true;
	}
	return false;
}

void Threat::RandomGrad(Map * map)
{
	srand(clock());
	int r = rand() % 10;
	if (r == 0)
	{
		r = rand() % 11;
		if (!r)	TurnBack();
		else if (r < 6) TurnLeft();
		else TurnRight();
	}
	while (isChamMap(map))
	{
		switch(rand() % 3 + 1)
		{
			case 1: TurnLeft(); break;
			case 2: TurnRight(); break;
			case 3: TurnBack(); break;
		}
	}
}



#endif
