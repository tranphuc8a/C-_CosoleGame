#ifndef LISTTHREAT_CPP
#define LISTTHREAT_CPP

#include "../Header/Header.h"


ListThreat::ListThreat()
{
	this->Soluong = 2;
	this->countDie = 0;
	this->List.resize(3);
	List[1] = new Threat;
	List[2] = new Threat;
	
	menu.resize(8);
	menu[1] = new Menu("Amount: ", 		Toado(5, 3));
	menu[2] = new Menu("Speed: ", 		Toado(5, 4));
	menu[3] = new Menu("Hinh dang: ", 	Toado(5, 5));
	menu[4] = new Menu("Ki tu: ", 		Toado(5, 6));
	menu[5] = new Menu("Auto create:", 	Toado(5, 7));
	menu[6] = new Menu("OK", 			Toado(5, 9));
	menu[7] = new Menu("Cancel", 		Toado(5, 10));
	// Soluong, tocdo, hinhdang, kitu, ok, cancel
	
	isAdd = false;
	timeAdd = 10000;
};
ListThreat::~ListThreat(){};

vector <Threat * > ListThreat::getList()
{
	return this->List;
}
int ListThreat::getSoluong()
{
	return this->Soluong;
}
int ListThreat::getCountDie()
{
	return this->countDie;
};

void ListThreat::Setlink()
{
	pNow = menu[1];
	menu[1]->Next = menu[3]->Pri = menu[2];
	menu[2]->Next = menu[4]->Pri = menu[3];
	menu[3]->Next = menu[5]->Pri = menu[4];
	menu[4]->Next = menu[6]->Pri = menu[5];
	menu[5]->Next = menu[7]->Pri = menu[6];
	menu[6]->Next = menu[1]->Pri = menu[7];
	menu[7]->Next = menu[2]->Pri = menu[1];
};
void ListThreat::ShowMenuInit()
{
	System.clrscr();
	System.gotoXY(5, 0); cout << "Initialization Threats" << endl;
	for (int i = 1; i<=6; i++) System.Goto(menu[i]->GetToado()), cout << menu[i]->GetName();
	point->ShowBefore(pNow->GetToado());
};
void ListThreat::LoopOption()
{
	while (1)
	{
		Events key = (Events) getch();
		switch(key)
		{
			case ESC: exit(0);
			case UP: case LEFT: pNow = pNow->Pri; break;
			case RIGHT: case DOWN: pNow = pNow->Next; break;
			case ENTER:
				if (pNow == menu[1])	// Amount:
				{
					
				}
				else if (pNow == menu[2])	// Speed:
				{
					
				}
				else if (pNow == menu[3])	// Hinh dang
				{
					
				}
				else if (pNow == menu[4])	// Kitu
				{
					
				}
				else if (pNow == menu[5])	// Auto create
				{
					
				}
				else if (pNow == menu[6])	// OK
				{
					
					return;
				}
				else return;				// Back
				break;
		}
		point->ShowBefore(pNow->GetToado());
	}
};
void ListThreat::Init()
{
	this->Setlink();
	this->ShowMenuInit();
	this->LoopOption();
}

void ListThreat::Hide()
{
	for (int i = 1; i<=this->Soluong; i++)
		List[i]->Hide();
};
void ListThreat::Show()
{
	for (int i = 1; i<=this->Soluong; i++)
		List[i]->Show();
};

void ListThreat::UpGrade(TimeStart & Start, Object * obj)
{
	if (this->Soluong == 0) return;
	int Now = clock();
	if (Now - Start.Threat < List[1]->getTocdo()) return;
	Start.Threat = clock();
	for (int i = 1; i<=this->Soluong; i++)
	{
		List[i]->UpGrade(Start, obj);
	}
	int i = 1;
	while (i <= this->Soluong)
	{
		if (List[i]->getIsDie()) List[i]->Hide(), this->PopAt(i);
		else i++;
	}
	if (!isAdd) return;
	
//	if (Now - Start.Threat >= this->timeAdd) this->AddtoList(new Threat());
//	this->List[this->Soluong]->setVitri(obj->map->toadoThreat);
	// Set properties for Amo which be Inited
	
//	List[this->Soluong]->Show();
};

void ListThreat::AddtoList(Threat * threat)
{
	this->Soluong++;
	this->List.push_back(threat);
};
void ListThreat::PopAt(int index)
{
	delete List[index];
	this->Soluong--;
	vector <Threat * > list(Soluong + 1);
	for (int i = 1; i<= index - 1; i++) list[i] = List[i];
	for (int i = index; i<=this->Soluong; i++) list[i] = List[i + 1];
	List = list;
};

#endif
