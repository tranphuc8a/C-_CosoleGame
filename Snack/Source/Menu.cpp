#ifndef MENU_CPP
#define MENU_CPP

#include "../Header/Menu.h"

Menu::Menu()
{
	this->Name = "New Menu";
	this->toado = Toado(0, 0);
	pNow = Pri = Next = Left = Right = Ver = NULL;
}
Menu::Menu(string Name, Toado toado)
{
	this->Name = Name;
	this->toado = toado;
	pNow = Pri = Next = Left = Right = Ver = NULL;
}
Menu::~Menu(){}


void 	Menu::SetName(string Name) 			{this->Name = Name;}
string 	Menu::GetName() 					{return this->Name;}
void 	Menu::SetToado(Toado toado) 		{this->toado = toado;}
void 	Menu::SetToado(int x, int y) 		{this->toado = Toado(x, y);}
Toado 	Menu::GetToado() 					{return this->toado;}
void 	Menu::SetpNow(Menu * menu) 			{pNow = menu;}
Menu * 	Menu::GetpNow() 					{return this->pNow;}
void 	Menu::SetPri(Menu * Pri) 			{this->Pri = Pri;}
Menu * 	Menu::GetPri() 						{return this->Pri;}
void 	Menu::SetNext(Menu * Next) 			{this->Next = Next;}
void 	Menu::SetPointer(int x, int y) 		{*this->point = Pointer(x, y);}
Pointer Menu::GetPoiter() 					{return *this->point;}

Events Menu::Getevent()
{
	if (kbhit()) return (Events) getch();
	else return NONE;
}
void Menu::Loop()
{
	for(;;)
	switch (Getevent())
	{
		case ESC:
			return;
		case UP:
			cout << "up" << endl;
			break;
		case DOWN:
			cout << "down" << endl;
			break;
		case LEFT:
			cout << "left" << endl;
			break;
		case RIGHT:
			cout << "right" << endl;
			break;
		case ENTER:
			cout << "enter" << endl;
			break;
		default:
			break;
	}
}
void Menu::Show(){}
void Menu::Main(){}


#endif
