#ifndef MOI_H
#define MOI_H

#include "Header.h"

class Moi
{
public:
	Toado Vitri;
	char Hinhdang;
public:
	Moi();
	~Moi();
public:
	Toado GetVitri()	;
public:
	void Hide();
	void Show();
	void Show(int x, int y);
	void Show(Toado Vitri);
	bool beEatenBy(ListSnack * listSnack);
	bool biTrung(ListMoi * listMoi, ListSnack * listSnack);
	void UpGrade(Map * map, ListSnack * listSnack, ListMoi * listMoi);
	void Ran(Map * map);		
};

#endif
