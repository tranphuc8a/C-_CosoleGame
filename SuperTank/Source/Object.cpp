#ifndef OBJECT_CPP
#define OBJECT_CPP

#include "../Header/Header.h"


Object::Object()
{
	this->result = 0;
	this->listMObj = new ListMainObject;
	this->listThreat = new ListThreat;
	this->map = new Map;
	
	menu.resize(6);
	menu[1] = new Menu("Init Map", Toado(5, 3));
	menu[2] = new Menu("Init Tank", Toado(5, 4));
	menu[3] = new Menu("Init Threat", Toado(5, 5));
	menu[4] = new Menu("Back", Toado(5, 6));
	
	this->start.ResetAll();
}
Object::~Object(){};

void Object::Setlink()
{
	pNow = menu[1];
	menu[1]->Next = menu[3]->Pri = menu[2];
	menu[2]->Next = menu[4]->Pri = menu[3];
	menu[3]->Next = menu[1]->Pri = menu[4];
	menu[4]->Next = menu[2]->Pri = menu[1];
}
void Object::ShowMenuInit()
{
	System.clrscr();
	System.gotoXY(5, 0); cout << "Initialization" << endl;
	for (int i = 1; i<=4; i++)	System.Goto(menu[i]->GetToado()), cout << menu[i]->GetName();
	point->ShowBefore(pNow->GetToado());
	
	System.Goto(menu[1]->GetToado() + Toado(menu[1]->GetName().length() + 1, 0)); cout << map->getType();
}
void Object::LoopOption()
{
	while (1)
	{
		Events (key) = (Events) getch();
		switch (key)
		{
			case ESC: return;
			case UP: case LEFT: pNow = pNow->Pri; break;
			case DOWN: case RIGHT: pNow = pNow->Next; break;
			case ENTER:
				if (pNow == menu[1]) map->Init();
				else if (pNow == menu[2]) listMObj->Init();
				else if (pNow == menu[3]) listThreat->Init();
				else return;
				ShowMenuInit();
		}
		point->ShowBefore(pNow->GetToado());
	}
}

void Object::Init()
{
	this->Setlink();
	this->ShowMenuInit();
	LoopOption();
};

void Object::ShowObject()
{
	System.clrscr();
	map->Show();
	listMObj->Show();
	listThreat->Show();
	System.gotoXY(map->getVitri().y + map->getSize().y + 1, map->getVitri().x + map->getSize().x + 1); cout << result;
};
void Object::UpGrade(TimeStart & Start, Object * obj)
{
	listMObj->UpGrade(Start, obj);
	listThreat->UpGrade(Start, obj);
};
void Object::RepEvent(Events event, Object * obj)
{
	listMObj->RepEvent(event, obj);
}
void Object::LoopGame()
{
	while (1)
	{
		if (isEndGame()) break;
		int countThreat = this->listThreat->getSoluong();
		this->UpGrade(this->start, this);
		if (kbhit())
			this->RepEvent((Events) getch(), this);
		// How to get and upgrade score???
		// We will create a property of ListThreat class: countDie 
		// -> count the threats which be died and this property is score of users
		result = listThreat->getCountDie();
	}
}

bool Object::isEndGame()
{
	return this->listThreat->getSoluong() == 0;
}

void Object::Start()
{
	this->ShowObject();
	getch();
	LoopGame();
	Result();
	Sleep(5000);
	getch();
}

void Object::Result()
{
	System.gotoXY(5, 3);
	cout << "Your score: " << this->result << endl;
}

#endif
