#ifndef AMO_H
#define AMO_H

#include "Header.h"

class Amo : public BaseObject
{
private:
	
public:
	Amo();
	~Amo();
public:
//	bool isBanTrung(Map * map);
	bool isBanTrung(BaseObject * obj);

	bool isChamVao(Object * obj);
	
public:
	void UpGrade(TimeStart & Start, Object * obj);
};


#endif
