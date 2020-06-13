#ifndef AMO_CPP
#define AMO_CPP

#include "../Header/Header.h"


Amo::Amo()
{
	Vitri = Size = Toado(1, 1);
	this->Hinhdang = new bool * [1];
	this->Hinhdang[0] = new bool[1];
	this->Hinhdang[0][0] = true;
	this->tocdo = 50;
	
	this->Kitu = 'o';
	this->isDie = 0;
}

Amo::~Amo(){};

bool Amo::isChamVao(Object * obj)
{
	if (this->isChamMap(obj->map)) return true;
	for (int i = 1; i<=obj->listThreat->getSoluong(); i++)
		if (this->isCham(obj->listThreat->getList()[i]))
		{
			obj->listThreat->getList()[i]->setIsDie(true);
			return true;
		}
	for (int i = 1; i<=obj->listMObj->getSoluong(); i++)
		if (this->isCham(obj->listMObj->getList()[i]))
		{
			obj->listMObj->getList()[i]->setIsDie(true);
			return true;
		}
	return false;
//	int count = 0;
//	for (int i = 1; i<=)	// cham vao amo khac??
}

bool Amo::isBanTrung(BaseObject * obj)
{
	return this->isCham(obj);
	obj->setIsDie(true);
};

void Amo::UpGrade(TimeStart & Start, Object * obj)
{
	if (isChamVao(obj))
	{
		this->isDie = true;
//		this->Hide();
	}
	else 
		GoStraight();
}


#endif
