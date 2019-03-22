#ifndef CVEHICLE_H
#define CVEHICLE_H
#include "console.h"
#include <iostream>
#include <Windows.h>

class CVEHICLE
{
private:
	int mX;
	int mY;
public:
	CVEHICLE() {};
	CVEHICLE(int x, int y) : mX(x), mY(y) {};
	CVEHICLE(int lane);
	~CVEHICLE();
public:
	virtual void Move(int, int) = 0;
	void MoveLeft(int width, int heigh) {
		mX--;
		if (mX < 6) {
			mX = 116;
		}
	};

	void MoveRight(int width, int heigh) {
		mX++;
		if (mX + 5 > 118) mX = 5;
	};
	int currentPosX() { return mX; };
	int currentPosY() { return mY; };
	void setPosX(int x) { mX = x; };
	void setPosY(int y) { mY = y; };

	virtual void Beep()=0;
};
#endif // !CVEHICLE_H



