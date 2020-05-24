#ifndef LISTSNACK_H
#define LISTSNACK_H

#include "Header.h"

class ListSnack
{
private:
	int soluong;
	vector <Snack> List;
public:
	ListSnack();
	~ListSnack();
public:
	int getSoluong();
	vector <Snack> getList();
	Snack & operator [](int index);
	void setSoluong(int soluong);
public:
	void Init();
	void AddtoList(Snack * ran);
	void Show();
	void Rep(Events event);
	void UpGrade(Map * map, ListSnack * listSnack, ListMoi * listMoi);
	void PopSnackAt(int index);
};


#endif
