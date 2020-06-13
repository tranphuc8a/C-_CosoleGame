#ifndef THREAT_H
#define THREAT_H

#include "Header.h"

class Threat : public BaseObject
{
private:
	ListAmo * List;
public:
	Threat();
	~Threat();
public:
//	ListAmo * getList();
	vector <Amo * > getList();
public:
	bool Ban(Map * map);
	bool isBanTrung(BaseObject * obj);
	bool isBiBanTrung(Object * obj);
	
	void UpGrade(TimeStart & Start, Object * obj);
public: // Go
	void RandomGrad(Map * map);
	
};

#endif
