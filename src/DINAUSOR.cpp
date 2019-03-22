#include "DINAUSOR.h"

using namespace std;


CDINAUSOR::CDINAUSOR()
{
}


CDINAUSOR::~CDINAUSOR()
{
}

void CDINAUSOR::Move(int w, int h)
{
	CANIMAL::MoveRight(w, h);
}

void CDINAUSOR::Tell()
{
	PlaySound(TEXT("Sound/dinausor.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void CDINAUSOR::draw()
{
	int a = currentPosX(), b = currentPosY();

	TextForDraw(rand() % 250 + 16);
	GotoXY(a + 3, b);
	cout << " ";
	GotoXY(a + 1, b + 1);
	cout << "   ";
	//GotoXY(a, b + 2);
	//cout << "   ";
	TextForDraw(15);

}
