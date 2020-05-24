#ifndef LISTSNACK_CPP
#define LISTSNACK_CPP

#include "../Header/ListSnack.h"

ListSnack::ListSnack()
{
	this->soluong = 1;
	List.push_back(Snack());
}
ListSnack::~ListSnack(){}
int ListSnack::getSoluong()			{return this->soluong;}
vector <Snack> ListSnack::getList()	{return this->List;}
Snack & ListSnack::operator [](int index)
{
	return this->List[index];
}
void ListSnack::setSoluong(int soluong)
{
	this->soluong = soluong;
	if (this->soluong > this->List.size())
	{
		for (int i = 1; i<=this->soluong - this->List.size(); i++) this->List.push_back(Snack());
	}
	else for(int i = 1; i<=this->List.size() - this->soluong; i++) this->List.pop_back();
}
void ListSnack::Init()
{
	
}
void ListSnack::AddtoList(Snack * ran)
{
	this->soluong++;
	this->List.push_back(*ran);
}
void ListSnack::Show()
{
	for (int i = 0; i<this->soluong; i++)
		List[i].ShowAll();
}
void ListSnack::Rep(Events event)
{
	for (int i = 0; i<this->soluong; i++)
	{
		this->List[i].Rep(event);
	}
}
void ListSnack::UpGrade(Map * map, ListSnack * listSnack, ListMoi * listMoi)
{
	for (int i = 0; i<this->soluong; i++)
	{
		this->List[i].UpGrade(map, listSnack, listMoi);
	}

	int i = 0;
	while (i < this->soluong)
	{
		if (List[i].getIsDie())
		{
			List[i].Hide();
			this->PopSnackAt(i);
		}
		else i++;
	}
}
void ListSnack::PopSnackAt(int index)
{
	vector <Snack> L;
	for (int i = 0; i<this->soluong; i++)
	{
		if (i != index) L.push_back(this->List[i]);
	}
	this->soluong--;
	this->List = L;
}

#endif
