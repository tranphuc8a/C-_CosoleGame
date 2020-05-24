#ifndef MOI_CPP
#define MOI_CPP

#include "../Header/Moi.h"

Moi::Moi()
{
	System.Srand();
	Hinhdang = '+';
	Vitri.x = System.Random() % 7 + 2;
	Vitri.y = System.Random() % 7 + 2;
}
Moi::~Moi(){}

Toado Moi::GetVitri()	{return this->Vitri;}

void Moi::Hide()
{
	System.Goto(this->Vitri);
	cout << " ";
}
void Moi::Show()
{
	System.Goto(this->Vitri);
	cout << Hinhdang;
}
void Moi::Show(int x, int y)
{
	this->Hide();
	this->Vitri = Toado(x, y);
	this->Show();
}
void Moi::Show(Toado Vitri)
{
	this->Hide();
	this->Vitri = Vitri;
	this->Show();
}
bool Moi::beEatenBy(ListSnack * list)
{
	for (int i = 0; i < list->getSoluong(); i++)
	{
		if (this->Vitri == list->getList()[i].getHead()) return true;
	}
}
bool Moi::biTrung(ListMoi * listMoi, ListSnack * listSnack)
{
	for (int i = 0; i<listSnack->getSoluong(); i++)
	{
		for (int j = 1; j<listSnack->getList()[i].getLen(); j++)
		{
			if (this->Vitri == listSnack->getList()[i].getList()[j].getVitri()) return true;
		}
	}
	int count = 0;
	for (int i = 0; i < listMoi->getSoluong(); i++)
	{
		if (this->Vitri == listMoi->getList().begin()->Vitri) count++;
	}
	return count >= 2;
}
void Moi::UpGrade(Map * map, ListSnack * listSnack, ListMoi * listMoi)
{
	while (this->beEatenBy(listSnack) || this->biTrung(listMoi, listSnack))
	{
		System.Goto(this->Vitri);
		cout << listSnack->getList()[0].getList()[0].getHinhdang();
		this->Ran(map);
		this->Show();
	}
}
void Moi::Ran(Map * map)
{
	srand((int) clock());
	this->Vitri.x = rand() % (map->Size.x - 2) + map->Vitri.x + 1;
	this->Vitri.y = rand() % (map->Size.y - 2) + map->Vitri.y + 1;
}

#endif
