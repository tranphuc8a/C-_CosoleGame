#ifndef KHUC_CPP
#define KHUC_CPP

#include "../Header/Khuc.h"

Khuc::Khuc()
{
	this->Vitri = Toado(0, 0);
	this->Hinhdang = 'o';
	this->Next = this->Pri = NULL;	
}
Khuc::~Khuc(){}

char Khuc::getHinhdang()				{return this->Hinhdang;}
Toado Khuc::getVitri()					{return this->Vitri;}
void Khuc::setHinhdang(char Hinhdang)	{this->Hinhdang = Hinhdang;}
void Khuc::setToado(Toado Vitri)		{this->Vitri = Vitri;}
void Khuc::setToado(int x, int y)		{this->Vitri = Toado(x, y);}
void Khuc::Hide()
{
	System.Goto(this->Vitri);
	cout << " ";
}
void Khuc::Show()
{
	System.Goto(this->Vitri);
	cout << this->Hinhdang;
}


#endif
