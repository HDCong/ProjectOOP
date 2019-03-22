#ifndef CBIRD_H
#define CBIRD_H
#include "ANIMAL.h"
class CBIRD:public CANIMAL
{
public:
	CBIRD();
	CBIRD(int x, int y) :CANIMAL(x, y) {};

	~CBIRD();
public:
	void Move(int, int);
	void Tell();
	void draw();
};

#endif // !CBIRD_H


