#ifndef CTRUCK_H
#define CTRUCK_H
#include "VEHICLE.h"

class CTRUCK:public CVEHICLE
{
public:
	CTRUCK();
	CTRUCK(int x, int y) :CVEHICLE(x, y) {};
	CTRUCK(int height);
	~CTRUCK();
//public:
	void Move(int width, int heigh);
	void Beep();
	void draw();
};
#endif // !CTRUCK_H


