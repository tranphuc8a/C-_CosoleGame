#ifndef SYSTEM_CPP
#define SYSTEM_CPP

#include "../Header/Header.h"


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
