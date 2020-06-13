#ifndef LISTAMO_H
#define LISTAMO_H

#include "Header.h"

class ListAmo : public Menu
{
private:
	vector <Amo * > List;
	int Soluong;
	
	BaseObject * Owner;
	vector <Menu * > menu;
public:
	ListAmo();
	~ListAmo();
public:
	vector <Amo * > getList();
	int getSoluong();
	BaseObject * getOwner();
	
	void setOwner(BaseObject * bobj);
	
public:
	void Init();
	void ShowMenuInit();
	void LoopOption();
	void Setlink();
public:
	void Show();
	void Hide();
	
	void UpGrade(TimeStart & Start, Object * obj);
	
	void AddtoList(Amo * amo, Map * map);
	void AddtoList(Map * map);
	void PopAt(int index);
	
};


#endif
