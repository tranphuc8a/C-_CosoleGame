#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <Windows.h>
#include <time.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <sstream>
#include "Header.h"

#define MAX 1000

using namespace std;

class SYSTEM
{
public:
	void clrscr();
	void SetColor(int x);
	void gotoXY(int, int);
	void Goto(Toado);
	void Srand();
	int Random();
	void HidePtr();
	void ShowPtr();
	
	class CONVERT
	{
	private:
	public:
		int toInt(char * num, int len);
		int toInt(string num);
		int toInt(double num);
		char * toChar(int num);
		char * toChar(string num);
		char * toChar(double num);
		string toString(int num);
		string toString(char * num, int len);
		string toString(double num);	
	} Convert;

} System;


void SYSTEM::clrscr()
{
	for (int i = 0; i<=20; i++)
	{
		gotoXY(0, i);
		for (int j = 1; j<=10; j++)
		{
			cout << "\t";
		}
		cout << endl;
	}
	gotoXY(0, 0);
	// system("cls");
}	
void SYSTEM::SetColor(int x)
{ 
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleColor, x);
}
void SYSTEM::gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void SYSTEM::Goto(Toado T)
{
	this->gotoXY(T.x, T.y);
}
void SYSTEM::Srand()
{
	srand((int) time(0));
}
int SYSTEM::Random()
{
	return rand();
}
void SYSTEM::HidePtr()
{
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;
    SetConsoleCursorInfo(hOut,&ConCurInf);
}
void SYSTEM::ShowPtr()
{
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = TRUE;
    SetConsoleCursorInfo(hOut,&ConCurInf);
} 


int SYSTEM::CONVERT::toInt(char * num, int sochuso)
{
	int Return = 0;
	bool duong = true;
	if (num[0] == '-')
	{
		duong = false;
		for (int i = 1; i<=sochuso; i++)
		{
			Return += ((int) num[i] - 48) * pow(10, sochuso - i);
		}
	}
	else
	{
		duong = true;
		for (int i = 0; i<sochuso; i++)
		{
			Return += ((int) num[i] - 48) * pow(10, sochuso - 1 - i); 
		}
	}
	if (duong)	return Return;
	else return -Return;
};
int SYSTEM::CONVERT::toInt(string num)
{
	int l = num.length();
	int Return = 0;
	bool duong = true;
	if (num[0] == '-')
	{
		duong = false;
		for (int i = 1; i<=l-1; i++)
		{
			Return += ((int) num[i] - 48) * pow(10, l - i - 1);
		}
	}
	else
	{
		duong = true;
		for (int i = 0; i<l; i++)
		{
			Return += ((int) num[i] - 48) * pow(10, l - 1 - i); 
		}
	}
	if (duong)	return Return;
	else return -Return;
};
int SYSTEM::CONVERT::toInt(double num)
{
	return (int) num;
};
char * SYSTEM::CONVERT::toChar(int num)
{
	char * x = new char[MAX];
	sprintf(x, "%d", num);
	return x;
};
char * SYSTEM::CONVERT::toChar(string num)
{

};
char * SYSTEM::CONVERT::toChar(double num)
{
	
};
string SYSTEM::CONVERT::toString(int num)
{
	char * x = new char[MAX];
	sprintf(x, "%d", num);
	return x;
/*
	Cach 2:
	streamstring f; f << num;
	return f.str();
*/
};
string SYSTEM::CONVERT::toString(char * num, int len)
{
	return num;
};
string SYSTEM::CONVERT::toString(double num)
{
	int t = this->CONVERT::toInt(num);
	return this->CONVERT::toString(t);
};	

#endif
