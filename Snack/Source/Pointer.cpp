#ifndef POINTER_CPP
#define POINTER_CPP

#include "../Header/Pointer.h"

Pointer::Pointer()
{
	this->Hinhdang = "->";
	this->toado = Toado(0,0);
}
Pointer::Pointer(int x, int y)
{
	this->Hinhdang = "->";
	this->toado = Toado(x, y);
}
Pointer::~Pointer(){}

void Pointer::SetHinhdang(string Hinhdang) {this->Hinhdang = Hinhdang;}
string Pointer::GetHinhdang() {return this->Hinhdang;}
void Pointer::SetToado(Toado toado) {this->toado = toado;}
void Pointer::SetToado(int x, int y) {this->toado = Toado(x, y);}
Toado Pointer::GetToado() {return this->toado;}

void Pointer::Show()
{
	System.gotoXY(this->toado.x, this->toado.y);
	cout << this->Hinhdang;
}
void Pointer::Show(int x, int y)
{
	this->Hide();
	this->toado = Toado(x, y);
	this->Show();
}
void Pointer::Show(Toado toado)
{
	this->Show(toado.x, toado.y);
}
void Pointer::ShowBefore(Toado toado)
{
	this->Show(toado.x - 3, toado.y);
}
void Pointer::Hide()
{
	System.gotoXY(this->toado.x, this->toado.y);
	for (int i = 1; i<=this->Hinhdang.length(); i++) cout << " ";
}

#endif
