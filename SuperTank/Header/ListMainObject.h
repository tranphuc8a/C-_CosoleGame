#ifndef LISTMAINOBJECT_H
#define LISTMAINOBJECT_H

#include "Header.h"

class ListMainObject : public Menu
{
private:
	vector <MainObject * > List;
	int Soluong;
	
	vector <Menu * > menu;
public:
	ListMainObject();
	~ListMainObject();
public:
	int getSoluong();
	vector <MainObject * > getList();
public:
	void Init();
public:
	void Hide();
	void Show();
	
	void UpGrade(TimeStart & Start, Object * obj);
	void RepEvent(Events event, Object * obj);
	
	void AddtoList(MainObject * mainObject);
	void PopAt(int index);
};

#endif
