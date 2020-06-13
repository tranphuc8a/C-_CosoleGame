#ifndef MAINOBJECT_H
#define MAINOBJECT_H

#include "Header.h"

class MainObject : public BaseObject
{
private:
	ListAmo * List;
public:
	MainObject();
	~MainObject();
public:
	void Ban(Map * map);
//	bool isBan(Events event, Object * obj);
	bool isBanTrung(BaseObject * obj);
	bool isBiBanTrung(Object * obj);
public:
	void UpGrade(TimeStart & Start, Object * obj);
	void RepEvent(Events event, Object * obj);
};

#endif
