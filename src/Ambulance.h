#pragma once
#include "VEHICLE.h"

class Ambulance
{
private:
	int mX;
	int mY;
public:
	Ambulance():mX(0),mY(0) {};
	Ambulance(int x, int y) : mX(x), mY(y) {};
	~Ambulance() {};
	void MoveLeft();
	void MoveRight();
	void draw(bool hasPerson);
	int getX() { return mX; };
	int getY() { return mY; };
	void setXY(int x, int y) { mX = x, mY = y; };
};

