#include "BIRD.h"

using namespace std;


CBIRD::CBIRD()
{
}


CBIRD::~CBIRD()
{
}

void CBIRD::Move(int width, int height)
{
	CANIMAL::MoveLeft(width, height);
}

void CBIRD::Tell()
{
	PlaySound(TEXT("Sound/bird.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void CBIRD::draw()
{
	int a = currentPosX(), b = currentPosY();
	GotoXY(a, b);
	TextForDraw(rand() % 250 + 16);
	cout << " ";
	GotoXY(a + 2, b);
	cout << " ";
	GotoXY(a + 1, b + 1);
	cout << " ";

	TextForDraw(15);

	//cout << (char)220 << " " << (char)220 ;
	//GotoXY(a+1, b + 1);
	//cout  << (char)223 << endl;
}
