#ifndef CCAR_H
#define CCAR_H
#include "VEHICLE.h"

class CCAR :public CVEHICLE
{
public:
	CCAR() {};
	CCAR(int x, int y) : CVEHICLE(x, y) {};
	CCAR(int lane);
	~CCAR();
public:
	void Move(int width, int heigh);
	void Beep();
	void draw();
};
#endif // !CCAR_H



