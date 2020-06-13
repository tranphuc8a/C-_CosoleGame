#ifndef POINTER_H
#define POINTER_H

#include "Header.h"

class Pointer
{
private:
	string Hinhdang;
	Toado toado;
public:
	Pointer();
	Pointer(int x, int y);
	~Pointer();
public:
	void SetHinhdang(string Hinhdang) ;
	string GetHinhdang() ;
	void SetToado(Toado toado) ;
	void SetToado(int x, int y) ;
	Toado GetToado() ;
public:
	void Show();
	void Show(int x, int y);
	void Show(Toado toado);
	void ShowBefore(Toado toado);
	void Hide();
};


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
