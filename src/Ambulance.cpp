#include "Ambulance.h"

void Ambulance::MoveLeft()
{
	mX--;
}

void Ambulance::MoveRight()
{
	mX++;
}

void Ambulance::draw(bool hasPerson)
{
	if (!hasPerson)
	{
		TextForDraw(250);
		GotoXY(mX, mY);
		cout << "     ";
		GotoXY(mX, mY + 1);
		cout << "      ";
		TextForDraw(15);
		GotoXY(0, 0);

	}
	else {

		TextForDraw(204);
		GotoXY(mX, mY);
		cout << " ";
		TextForDraw(204);
		GotoXY(mX, mY + 1);
		cout << " ";
		TextForDraw(250);
		GotoXY(mX+1, mY);
		cout << "    ";
		GotoXY(mX+1, mY + 1);
		cout << "     ";
		TextForDraw(15);
		GotoXY(0, 0);
	}
}
