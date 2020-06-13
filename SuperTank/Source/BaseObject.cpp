#ifndef BASEOBJECT_CPP
#define BASEOBJECT_CPP

#include "../Header/Header.h"

BaseObject::BaseObject()
{
	Vitri = Size = Toado(1, 1);
	this->Hinhdang = new bool * [1];
	this->Hinhdang[0] = new bool[1];
	this->Hinhdang[0][0] = 1;
	this->tocdo = 200;
	
	this->Kitu = '*';
	this->isDie = 0;
	srand(time(0));
	switch (rand() % 4)
	{
		case 0: Grad = UP; break;
		case 1: Grad = DOWN; break;
		case 2: Grad = LEFT; break;
		case 3: Grad = RIGHT; break;
	}
}

BaseObject::~BaseObject(){}

Toado BaseObject::getVitri()
{
	return this->Vitri;
}
Toado BaseObject::getSize()
{
	return this->Size;
}
bool ** BaseObject::getHinhdang()
{
	return this->Hinhdang;
}
char BaseObject::getKitu()
{
	return this->Kitu;
}
bool BaseObject::getIsDie()
{
	return this->isDie;
}
bool BaseObject::Die()
{
	return this->isDie;
}
int BaseObject::getTocdo()
{
	return this->tocdo;
}
Events BaseObject::getGrad()
{
	return this->Grad;
}

void BaseObject::setVitri(int x, int y)
{
	this->Vitri = Toado(x, y);
}
void BaseObject::setVitri(Toado Vitri)
{
	this->Vitri = Vitri;
}
void BaseObject::setSize(int x, int y)
{
	this->Size = Toado(x, y);
}
void BaseObject::setSize(Toado Size)
{
	this->Size = Size;
}
void BaseObject::setHinhdang(bool ** Hinhdang)
{
	this->Hinhdang = Hinhdang;
}
void BaseObject::setKitu(char Kitu)
{
	this->Kitu = Kitu;
}
void BaseObject::setTocdo(int tocdo)
{
	this->tocdo = tocdo;
}
void BaseObject::setGrad(Events Grad)
{
	this->Grad = Grad;
}
void BaseObject::setIsDie(bool isDie)
{
	this->isDie = isDie;
}

void BaseObject::Hide()
{
	for (int i = 0; i<Size.x; i++)
	{
		System.gotoXY(this->Vitri.y, this->Vitri.x + i);
		for (int j = 0; j<Size.y; j++)
		{
			cout << " ";
		}
	}
}
void BaseObject::Show()
{
	for (int i = 0; i<Size.x; i++)
	{
		System.gotoXY(this->Vitri.y, this->Vitri.x + i);
		for (int j = 0; j<Size.y; j++)
		{
			if (this->Hinhdang[i][j]) cout << this->Kitu;
			else cout << " ";
		}
	}
}
void BaseObject::Show(int x, int y)
{
	this->Hide();
	this->setVitri(x, y);
	this->Show();
}
void BaseObject::Show(Toado Vitri)
{
	this->Show(Vitri.x, Vitri.y);
}

bool BaseObject::isCham(BaseObject * obj)
{
	Toado A1 = this->Vitri, A2 = this->Vitri + this->Size + Toado(-1, -1);
	Toado A3 = Toado(this->Vitri.x, this->Vitri.y + this->Size.y - 1),
		  A4 = Toado(this->Vitri.x + this->Size.x - 1, this->Vitri.y);
	Toado M = obj->getVitri(), N = obj->getVitri() + obj->getSize() + Toado(-1, -1);
	Toado 	P = Toado(obj->getVitri().x, obj->getVitri().y + obj->getSize().y - 1),
			Q = Toado(obj->getVitri().x + obj->getSize().x - 1, obj->getVitri().y);
	return  (A1 <= M && M <= A2) || (A1 <= N && N <= A2) || (A1 <= P && P <= A2) || (A1 <= Q && Q <= A2) ||
			(M <= A1 && A1 <= N) || (M <= A2 && A2 <= N) || (M <= A3 && A3 <= N) || (M <= A4 && A4 <= N);
}
bool BaseObject::isChamMap(Map * map)
{
	switch (this->Grad)
	{
		case UP:
			for (int i = 0; i<this->Size.y; i++)
			{
				if (map->getHinhdang()[this->Vitri.x - 1 - map->getVitri().x][this->Vitri.y - map->getVitri().y + i])
					return true;
			}
			return false;
			break;
		case DOWN:
			for (int i = 0; i<this->Size.y; i++)
			{
				if (map->getHinhdang()[this->Vitri.x + this->Size.x - map->getVitri().x][this->Vitri.y - map->getVitri().y + i])
					return true;
			}
			return false;
			break;
		case LEFT:
			for (int i = 0; i<this->Size.x; i++)
			{
				if (map->getHinhdang()[this->Vitri.x - map->getVitri().x + i][this->Vitri.y - 1 - map->getVitri().y])
					return true;
			}
			return false;
			break;
		case RIGHT:
			for (int i = 0; i<this->Size.x; i++)
			{
				if (map->getHinhdang()[this->Vitri.x - map->getVitri().x + i][this->Vitri.y + this->Size.y - map->getVitri().y])
					return true;
			}
			return false;
			break;
	}
	return false;
}




void BaseObject::TurnLeft()
{
	switch(Grad)
	{
		case UP: Grad = LEFT; break;
		case DOWN: Grad = RIGHT; break;
		case LEFT: Grad = DOWN; break;
		case RIGHT: Grad = UP; break;
	}
}
void BaseObject::TurnRight()
{
	switch(Grad)
	{
		case UP: Grad = RIGHT; break;
		case DOWN: Grad = LEFT; break;
		case LEFT: Grad = UP; break;
		case RIGHT: Grad = DOWN; break;
	}
}
void BaseObject::TurnBack()
{
	switch(Grad)
	{
		case UP: Grad = DOWN; break;
		case DOWN: Grad = UP; break;
		case LEFT: Grad = RIGHT; break;
		case RIGHT: Grad = LEFT; break;
	}
}
void BaseObject::GoStraight()
{
	this->Hide();
	switch (Grad)
	{
		case UP: this->Vitri.x--; break;
		case DOWN: this->Vitri.x++; break;
		case LEFT: this->Vitri.y--; break;
		case RIGHT: this->Vitri.y++; break;
	}
	this->Show();
}

#endif
