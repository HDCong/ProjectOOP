#ifndef CANIMAL_H
#define CANIMAL_H
#include "console.h"
#include <iostream>
#include <Windows.h>
class CANIMAL
{
private:
	int mX, mY;
public:
	CANIMAL();
	CANIMAL(int x, int y) : mX(x), mY(y) {};
	~CANIMAL();

public:
	virtual void Move(int, int) = 0;
	void MoveLeft(int width, int heigh);
	void MoveRight(int width, int heigh);
	virtual void Tell()=0;
	int currentPosX()const { return mX; };
	int currentPosY() const { return mY; };
	void setPosX(int x) { mX = x; };
	void setPosY(int y) { mY = y; };
};


#endif // !CANIMAL_H

