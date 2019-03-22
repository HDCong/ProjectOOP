#include "TRUCK.h"

using namespace std;

CTRUCK::CTRUCK()
{

}

CTRUCK::CTRUCK(int height) : CVEHICLE(height)
{
}


CTRUCK::~CTRUCK()
{
}

void CTRUCK::Move(int width, int heigh)
{
	CVEHICLE::MoveRight(width, heigh);
}

void CTRUCK::Beep()
{
	PlaySound(TEXT("Sound/truck.wav"), NULL, SND_FILENAME | SND_ASYNC);

}

void CTRUCK::draw()
{
	int a = currentPosX(), b = currentPosY();
	GotoXY(a, b);
	TextForDraw(250);
	cout << "    ";
	GotoXY(a, b + 1);
	cout << "     ";
	TextForDraw(15);
}
