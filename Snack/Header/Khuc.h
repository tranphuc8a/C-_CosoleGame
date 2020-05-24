#ifndef KHUC_H
#define KHUC_H

#include "Header.h"

class Khuc
{
public:
	Toado Vitri;
	char Hinhdang;
	Khuc * Next;
	Khuc * Pri;
public:
	Khuc();
	~Khuc();
public:
	char getHinhdang();
	Toado getVitri();
	void setHinhdang(char Hinhdang);
	void setToado(Toado Vitri);
	void setToado(int x, int y);
public:
	void Hide();
	void Show();
};


#endif
