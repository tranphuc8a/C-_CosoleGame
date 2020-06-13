#ifndef LISTAMO_CPP
#define LISTAMO_CPP

#include "../Header/Header.h"


ListAmo::ListAmo()
{
	this->Soluong = 0;
	this->List.push_back(new Amo);
	this->Owner = NULL;
};
ListAmo::~ListAmo(){};

vector <Amo * > ListAmo::getList()
{
	return this->List;
};
int ListAmo::getSoluong()
{
	return this->Soluong;
};
BaseObject * ListAmo::getOwner()
{
	return this->Owner;
};
	
void ListAmo::setOwner(BaseObject * bobj)
{
	this->Owner = bobj;
};


void ListAmo::Init()
{
	Setlink();
	ShowMenuInit();
	LoopOption();
};
void ListAmo::ShowMenuInit()
{
	System.clrscr();
	System.gotoXY(5, 0); cout << "Initialization Amo";
	for (int i = 1; i<=4; i++)
	{
		System.Goto(menu[i]->GetToado()); cout << menu[i]->GetName();
	}
	point->ShowBefore(pNow->GetToado());
};
void ListAmo::LoopOption()
{
	while (1)
	{
		Events key = (Events) getch();
		switch (key)
		{
			case ESC: exit(0);
			case UP: case LEFT: pNow = pNow->Pri; break;
			case RIGHT: case DOWN: pNow = pNow->Next; break;
			case ENTER:
				// Set
				return;
		}
		point->ShowBefore(pNow->GetToado());
	}
};
void ListAmo::Setlink()
{
	// amo1, amo2, amo3, amo4,
	menu.resize(5);
	for (int i = 1; i<=4; i++) menu[i] = new Menu("Amo" + (char) i + '0', Toado(5, 2 + i));
	
	pNow = menu[1];
	menu[1]->Next = menu[3]->Pri = menu[2];
	menu[2]->Next = menu[4]->Pri = menu[3];
	menu[3]->Next = menu[1]->Pri = menu[4];
	menu[4]->Next = menu[2]->Pri = menu[1];
	
};

void ListAmo::Show()
{
	for (int i = 1; i<=Soluong; i++) List[i]->Show();
};
void ListAmo::Hide()
{
	for (int i = 1; i<=Soluong; i++) List[i]->Hide();
};

void ListAmo::UpGrade(TimeStart & Start, Object * obj)
{
	if (this->Soluong == 0) return;
	int Now = clock();
	if (Now - Start.Amo < List[1]->getTocdo()) return;
	for (int i = 1; i<=Soluong; i++)
	{
		List[i]->UpGrade(Start, obj);
	}
	int i = 1;
	while (i <= Soluong)
	{
		if (List[i]->isChamVao(obj))
		{
			List[i]->Hide();
			this->PopAt(i);
		}
		else i++;
	}
	Start.Amo = clock();
};

void ListAmo::AddtoList(Amo * amo, Map * map)
{
	if (this->Owner->isChamMap(map)) return;
	this->Soluong++;
	this->List.push_back(amo);
	switch (this->Owner->getGrad())
	{
		case UP:
			List[Soluong]->setVitri(Owner->getVitri().x - 1, Owner->getVitri().y + Owner->getSize().y/2);
			break;
		case DOWN:
			List[Soluong]->setVitri(Owner->getVitri().x + Owner->getSize().x, Owner->getVitri().y + Owner->getSize().y/2);
			break;
		case LEFT:
			List[Soluong]->setVitri(Owner->getVitri().x + Owner->getSize().x/2, Owner->getVitri().y - 1);
			break;
		case RIGHT:
			List[Soluong]->setVitri(Owner->getVitri().x + Owner->getSize().x/2, Owner->getVitri().y + Owner->getSize().y);
			break;
	}
	List[Soluong]->setGrad(this->Owner->getGrad());
	List[Soluong]->Show();
};
void ListAmo::AddtoList(Map * map)
{
	this->AddtoList(new Amo(), map);
};
void ListAmo::PopAt(int index)
{
	this->Soluong--;
	vector <Amo * > list(Soluong + 1);
	for (int i = 0; i<index; i++)
	{
		list[i] = List[i];
	}
	for (int i = index; i<=this->Soluong; i++)
	{
		list[i] = List[i + 1];
	}
	delete List[index];
	List = list;
};


#endif
