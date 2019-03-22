#include "CTRAFFICLIGHT.h"
#include <Windows.h>
#include <iostream>
using namespace std;


CTRAFFICLIGHT::CTRAFFICLIGHT()
{
	isGreen = true;
	begin = clock();
}

CTRAFFICLIGHT::~CTRAFFICLIGHT()
{
}

bool CTRAFFICLIGHT::changeLight()
{
	if ((((int)(clock() - begin)) / 3000) % 2)
	{
		isGreen = false;
		GotoXY(4, 12);
		cout << " ";
		GotoXY(121, 36);
		cout << " ";
		GotoXY(4, 11);
		TextForDraw(196);
		cout << (char)219;
		GotoXY(121, 35);
		cout << (char)219;

	}
	else {
		isGreen = true;

		GotoXY(4, 11);
		cout << " ";
		GotoXY(121, 35);
		cout << " ";
		GotoXY(4, 12);
		TextForDraw(2);
		cout << (char)219;
		GotoXY(121, 36);
		cout << (char)219;
	}
	TextForDraw(15);
	return isGreen;
} 