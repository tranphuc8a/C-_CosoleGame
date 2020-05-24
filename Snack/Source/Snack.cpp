#ifndef SNACK_CPP
#define SNACK_CPP

#include "../Header/Snack.h"

Snack::Snack()
{
	this->len = 3;
	this->isDie = false;
	this->Grad = RIGHT;
	this->Head = Toado(3, 1);
	this->Hinhdang = 'o';
	this->Ran.push_back(Khuc());
	this->Ran.push_back(Khuc());
	this->Ran.push_back(Khuc());
	this->Ran[0].setToado(3, 1);
	this->Ran[1].setToado(2, 1);
	this->Ran[2].setToado(1, 1);
	Last = Ran[2].Vitri;
	this->Last = this->Ran[3].Vitri;
}
Snack::~Snack(){}

int Snack::getLen()	{return this->len;}
bool Snack::getIsDie()	{return this->isDie;}
Events Snack::getGrad()	{return this->Grad;}
Toado Snack::getHead()		{return this->Head;}
vector <Khuc> Snack::getList()		{return this->Ran;}
void Snack::setGrad(Events Grad)	{this->Grad = Grad;}

void Snack::Hide()
{
	for (int i = 0; i<this->len; i++) this->Ran[i].Hide();
}
void Snack::ShowHead()
{
	System.Goto(this->Head);
	cout << (Grad == UP ? '^' : (Grad == DOWN ? 'v' : (Grad == LEFT ? '<' : '>')));
}
void Snack::ShowAll()
{
	for (int i = 0; i<this->len; i++) if (i == 0) ShowHead(); else Ran[i].Show();
}
void Snack::Show()
{
//	for (int i = 0; i<this->len; i++) if (i == 0) System.Goto(this->Ran[0].Vitri), cout << 'h'; else Ran[i].Show();
	ShowHead();
	System.Goto((Ran.begin() + 1)->getVitri()); cout << (Ran.begin() + 1)->getHinhdang();
	System.Goto(this->Last); cout << ' ';
}
void Snack::AddtoList(Khuc * khuc)
{
	this->len++;
	this->Ran.push_back(*khuc);
	khuc->Pri = &Ran[this->Ran.size() - 1];
	Ran[this->Ran.size() - 1].Next = khuc;
	khuc->Vitri = this->Last;
	System.Goto(khuc->getVitri()); cout << this->Hinhdang;
	System.Goto((Ran.begin() + 1)->getVitri()); cout << (Ran.begin() + 1)->getHinhdang();
}
bool Snack::isEat(ListMoi * list)
{
	for (int i = 0; i<list->getSoluong(); i++)
	{
		if (this->Head == list->getList()[i].Vitri) return true;
	}
	return false;
}
bool Snack::isDam(Snack * snack)
{
	for (int i = 1; i<snack->getLen(); i++)
	{
		if (this->Head == snack->getList()[i].Vitri) return true;
	}
	return false;
}
bool Snack::isDam(ListSnack * list)
{
	for (int i = 0; i<list->getSoluong(); i++)
	{
		if (this->isDam(&list->getList()[i])) return true;
	}
	return false;
}
bool Snack::isDam(Map * map)
{
	return map->map[this->Head.x - map->Vitri.x][this->Head.y - map->Vitri.y];
}
void Snack::UpGrade(Map * map, ListSnack * listSnack, ListMoi * listMoi)
{
	this->Last = (this->Ran.end() - 1)->getVitri();
	for (int i = this->len - 1; i>0; i--)
	{
		this->Ran[i].Vitri = this->Ran[i - 1].Vitri;
	}
	switch(this->Grad)
	{
		case UP:
			this->Head.y--;
			this->Ran[0].Vitri.y--;
			break;
		case DOWN:
			this->Head.y++;
			this->Ran[0].Vitri.y++;
			break;
		case LEFT:
			this->Head.x--;
			this->Ran[0].Vitri.x--;
			break;
		case RIGHT:
			this->Head.x++;
			this->Ran[0].Vitri.x++;
			break;
	}
	if (this->isDam(map))
	{
		switch(this->Grad)
		{
			case UP:
				this->Head.y = map->Vitri.y + map->Size.y - 2;
				break;
			case DOWN:
				this->Head.y = map->Vitri.y + 1;
				break;
			case LEFT:
				this->Head.x = map->Vitri.x + map->Size.x - 2;
				break;
			case RIGHT:
				this->Head.x = map->Vitri.x + 1;
				break;
		}
		this->Ran[0].Vitri = this->Head;
	}
	if (this->isDam(listSnack))
	{
		this->isDie = true;
		this->Hide();
	}
	if (this->isEat(listMoi))
	{
		this->AddtoList(new Khuc());
		System.gotoXY(map->Vitri.x + map->Size.x + 1, map->Vitri.y + map->Size.y); cout << this->len - 3;
	}
	this->Show();
}
void Snack::Rep(Events event)
{
	if (this->Grad == LEFT && event == RIGHT) return;
	if (this->Grad == RIGHT && event == LEFT) return;
	if (this->Grad == UP && event == DOWN) return;
	if (this->Grad == DOWN && event == UP) return;
	this->Grad = event;
}


#endif
