#include "ANIMAL.h"



CANIMAL::CANIMAL()
{
}


CANIMAL::~CANIMAL()
{
}


void CANIMAL::MoveLeft(int width, int heigh)
{
	mX--;
	if (mX < 6) {
		mX = 116;
	}
}

void CANIMAL::MoveRight(int width, int heigh)
{
	mX++;
	if (mX + 4 > 119)
	{
		mX = 5;
	}
}

void CANIMAL::Tell()
{
	// Do nothing
}
