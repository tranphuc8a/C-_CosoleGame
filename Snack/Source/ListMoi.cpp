#ifndef LISTMOI_CPP
#define LISTMOI_CPP

#include "../Header/ListMoi.h"

ListMoi::ListMoi()
{
	soluong = 1;
	List.push_back(Moi());
}
ListMoi::~ListMoi(){}
void ListMoi::setSoluong(int soluong)
{
	this->soluong = soluong;
	if (this->soluong > this->List.size())
	{
		for (int i = 1; i<=this->soluong - this->List.size(); i++) this->List.push_back(Moi());
	}
	else for(int i = 1; i<=this->List.size() - this->soluong; i++) this->List.pop_back();
}
int ListMoi::getSoluong()
{
	return this->soluong;
}
vector <Moi> ListMoi::getList() 	
{
	return this->List;
}
void ListMoi::Init()
{
	
}
void ListMoi::Show()
{
	for (int i = 0; i<this->soluong; i++)
		this->List[i].Show();
}
void ListMoi::UpGrade(Map * map, ListSnack * listSnack, ListMoi * listMoi)
{
	for (int i = 0; i<this->soluong; i++)
	{
		List[i].UpGrade(map, listSnack, this);
	}
}
void ListMoi::AddtoList(Moi * moi)
{
	this->soluong++;
	this->List.push_back(*moi);
}

#endif
