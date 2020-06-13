#ifndef LISTTHREAT_H
#define LISTTHREAT_H

#include "Header.h"

class ListThreat : public Menu
{
private:
	vector <Threat * > List;
	int Soluong;
	
	int countDie;
	
	vector <Menu * > menu;
	
	bool isAdd;			// Check for auto add threat ???
	int timeAdd;		// time to add threat
public:
	ListThreat();
	~ListThreat();
public:
	vector <Threat * > getList();
	int getSoluong();
	int getCountDie();
public:
	void Setlink();
	void ShowMenuInit();
	void LoopOption();
	void Init();
public:
	void Hide();
	void Show();
	
	void UpGrade(TimeStart & Start, Object * obj);
	
	void AddtoList(Threat * threat);
	void PopAt(int index);
};

#endif
