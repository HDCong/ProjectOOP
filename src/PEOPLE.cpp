#include "PEOPLE.h"
#include <iostream>


using namespace std;

CPEOPLE::CPEOPLE()
{
	mName = "Road Crossing";
	mX = 45;
	mY = 26;
	mState = true;
}

CPEOPLE::CPEOPLE(int x, int y)
{
	mName = "Road Crossing";
	mX = x;
	mY = y;
	mState = true;

}

CPEOPLE::~CPEOPLE()
{
}

void CPEOPLE::Up()
{
	if (mY == 8)
		return;
	else {
		if (mY == 37 || mY == 29 || mY == 21 || mY == 13)
			mY -= 2;
		else mY -= 3;
	}
}

void CPEOPLE::Left()
{
	mX -= 3;
	if (mX < 5) mX = 118;
}

void CPEOPLE::Right()
{
	mX += 3;
	if (mX > 118)
		mX = 5;
}

void CPEOPLE::Down()
{
	if (mY == 40) return;
	else {
		if (mY == 35 || mY == 27 || mY == 19 || mY == 11)
			mY += 2;
		else mY += 3;
	}
}

bool CPEOPLE::isImpact(const vector<CVEHICLE*>& list)
{
	for (int i = 0; i < list.size(); i++)
	{
		int a = list[i]->currentPosX() , b = list[i]->currentPosY();
		if (mX + 3 <= a || mX >= a + 5) continue;
		else {
			if (mY == b - 1 || mY == b + 1) return true;
		}
	}	
	return false;
}

bool CPEOPLE::isImpact(const vector<CANIMAL *>&list)
{
	for (int i = 0; i < list.size(); i++)
	{
		int a = list[i]->currentPosX(), b = list[i]->currentPosY();
		if (mX + 3 <= a || mX >= a + 3) continue;
		else {
			if (mY == b - 1 || mY == b + 1) return true;
		}
	}
	return false;
}

bool CPEOPLE::isFinish()
{
	return mY == 8;
}

bool CPEOPLE::isDead()
{
	return mState == false;
}

void CPEOPLE::draw()
{
	if (mY == 16 || mY == 24 || mY == 32)
		TextForDraw(226);
	else TextForDraw(2);
	GotoXY(mX, mY);
	cout << " " << (char)219 << " " ;
	GotoXY(mX, mY + 1);
	cout << (char)201 << (char)193 << (char)187;
	TextForDraw(15);
	GotoXY(0, 0);

}

void CPEOPLE::setName(const string & name)
{
	mName = name;
}
