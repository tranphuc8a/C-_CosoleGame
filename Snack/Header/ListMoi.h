#ifndef LISTMOI_H
#define LISTMOI_H

#include "Header.h"

class ListMoi
{
private:
	int soluong;
	vector <Moi> List;
public:
	ListMoi();
	~ListMoi();
public:
	void setSoluong(int soluong);
	int getSoluong();
	vector <Moi> getList();
public:
	void Init();
	void Show();
	void UpGrade(Map * map, ListSnack * listSnack, ListMoi * listMoi);
	void AddtoList(Moi * moi);
};

#endif
