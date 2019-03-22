#include "CAR.h"
using namespace std;


CCAR::CCAR(int lane): CVEHICLE(lane)
{
}


CCAR::~CCAR()
{
}

void CCAR::Move(int width, int heigh) 
{
	CVEHICLE::MoveLeft(width, heigh);
}

void CCAR::Beep()
{
	PlaySound(TEXT("Sound/car.wav"), NULL, SND_FILENAME | SND_ASYNC);
	//	Sleep(100);
}

void CCAR::draw()
{
	int a = currentPosX(), b = currentPosY();
	//TextForDraw(rand() % 250 + 16);
	TextForDraw(250);
	GotoXY(a + 1, b);
	cout << "   ";
	GotoXY(a, b + 1);
	cout << "     ";
	TextForDraw(15);
}
