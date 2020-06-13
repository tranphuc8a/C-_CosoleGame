#ifndef LISTMAINOBJECT_CPP
#define LISTMAINOBJECT_CPP

#include "../Header/Header.h"


ListMainObject::ListMainObject()
{
	this->Soluong = 1;
	this->List.resize(2);
	List[1] = new MainObject;
	
};
ListMainObject::~ListMainObject(){};

int ListMainObject::getSoluong()
{
	return this->Soluong;
};
vector <MainObject * > ListMainObject::getList()
{
	return this->List;
};

void ListMainObject::Init()
{
	
};

void ListMainObject::Hide()
{
	for (int i = 1; i<=Soluong; i++)
	{
		List[i]->Hide();
	}
};
void ListMainObject::Show()
{
	for (int i = 1; i<=Soluong; i++)
	{
		this->List[i]->Show();
	}
};

void ListMainObject::UpGrade(TimeStart & Start, Object * obj)
{
	for (int i = 1; i<=Soluong; i++)
	{
		List[i]->UpGrade(Start, obj);
	}
	
};
void ListMainObject::RepEvent(Events event, Object * obj)
{
	for (int i = 1; i<=this->Soluong; i++)
	{
		List[i]->RepEvent(event, obj);
	}
	int i = 1;
	while (i <= Soluong)
	{
		if (List[i]->getIsDie()) 
		{
			this->PopAt(i);
			List[i]->Hide();
		}
		else i++;
	}
};

void ListMainObject::AddtoList(MainObject * mainObject)
{
	this->Soluong++;
	this->List.push_back(mainObject);
	// Set data for mainObject
};
void ListMainObject::PopAt(int index)
{
	this->Soluong--;
	int i = 1;
	vector <MainObject * > list;
	for (int i = 1; i<index; i++) list[i] = List[i];
	for (int i = index; i<=Soluong; i++) list[i] = List[i + 1];
	delete List[index];
	List = list;
};

#endif
