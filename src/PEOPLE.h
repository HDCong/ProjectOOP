#ifndef CPEOPLE_H
#define CPEOPLE_H
#include "console.h"
#include "VEHICLE.h"
#include "ANIMAL.h"
#include <vector>
using namespace std;


class CPEOPLE
{
	int mX;
	int mY;
	bool mState;
	string mName;
public:

	CPEOPLE();
	CPEOPLE(int width, int height);
	~CPEOPLE();

public:
	void Up();
	void Left();
	void Right();
	void Down();
	bool isImpact(const vector< CVEHICLE*> &list);
	bool isImpact(const vector<CANIMAL*> &list);
	bool isFinish();
	bool isDead();
	void draw();
	int getX() const { return mX; };
	int getY() const { return mY; };
	string getName() { return mName; };
	void setXY(const int &x, const int &y) { mX = x; 	mY = y; };
	void setState(bool state) { mState = state; }
	void setName(const string &name);

};



#endif // !CPEOPLE_H

