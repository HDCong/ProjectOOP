#include "GAME.h"
#include "Ambulance.h"
#include <thread>
#include <iostream>
#include <conio.h>
using namespace std;

bool IS_RUNNING = true;
char MOVING;
CGAME *cg;

Ambulance *SOS = new Ambulance();
bool ambulance = false;
bool isSet = false;
bool way1 = false;
bool takePerson = false;
bool isPlay = false;

int getLaneForAmbulance(int b)
{
	if (abs(b - 36) == 1) return 36;
	if (abs(b - 28) == 1) return 28;
	if (abs(b - 20) == 1) return 20;
	if (abs(b - 12) == 1) return 12;
}

void SubThread()
{
	while (IS_RUNNING)
	{
		if (!cg->getPeople().isDead())
		{
			cg->updatePosPeople(MOVING);

			MOVING = ' ';
			cg->updatePosAnimals();

			if (cg->getTraff()->changeLight())
				cg->updatePosVehicles();

			cg->drawGame();

			if (cg->getPeople().isImpact(cg->getAnimal()) || cg->getPeople().isImpact(cg->getVehicle()))
			{
				cg->whenImpact();
				int a = cg->getPeople().getX();
				int b = cg->getPeople().getY();

				b = getLaneForAmbulance(b);


				TextForDraw(76);
				GotoXY(a, b);
				cout << "    ";
				GotoXY(a, b + 1);
				cout << "    ";
				TextForDraw(15);

				if (a > 60) {
					way1 = true;
					SOS->setXY(5, b);
				}
				else {
					way1 = false;
					SOS->setXY(115, b);
				}
				isSet = true;

				TextForDraw(15);
				for (int i = 7;i < 120;i++)
				{
					GotoXY(i, b);
					cout << " ";
					GotoXY(i, b + 1);
					cout << " ";

				}
				GotoXY(0, 0);
			}
			if (cg->getPeople().isFinish())
			{
				cg->whenFinish();

			}
			Sleep(cg->getSpeed());
		}

	}
}

void SubThread2()
{

	while (IS_RUNNING)
	{
		if (cg->getPeople().isDead() && !ambulance && isSet)
		{
			int a = cg->getPeople().getX(), b = cg->getPeople().getY();
			b = getLaneForAmbulance(b);

			int curX = SOS->getX();
			GotoXY(curX, b);

			TextForDraw(15);
			cout << "       ";

			GotoXY(curX, b + 1);

			TextForDraw(15);
			cout << "       ";

			if (way1)
			{
				if (curX + 3 >= a && !takePerson)
					takePerson = true;
				if (!takePerson)
				{
					SOS->MoveRight();
				}
				else {
					SOS->MoveLeft();
					if (curX < 8) {
						
						GotoXY(curX, b -1);
						cout << "       ";
						GotoXY(curX, b);
						cout << "       ";

						GotoXY(curX, b + 1);
						cout << "       ";
						GotoXY(128, 20);
						cout << "PRESS R TO RESET THIS LEVEL.     ";
						GotoXY(128, 24);
						cout << "PRESS Y TO START GAME";

						GotoXY(128, 28);
						cout << "PRESS L TO SAVE THEN EXIT";
						GotoXY(128, 32);
						cout << "PRESS ANYKEY ELSE TO EXIT";
						GotoXY(0, 0);

						ambulance = true;

					}
				}

			}
			else {

				if (SOS->getX() <= a && !takePerson) takePerson = true;
				if (!takePerson)
				{
					SOS->MoveLeft();
				}
				else {
					SOS->MoveRight();
					if (SOS->getX() > 110) {
						GotoXY(curX, b - 1);
						cout << "       ";
						GotoXY(curX, b);
						cout << "       ";

						GotoXY(curX, b + 1);
						cout << "       ";
						GotoXY(128, 20);
						cout << "PRESS R TO RESET THIS LEVEL.     ";
						GotoXY(128, 24);
						cout << "PRESS Y TO START GAME";

						GotoXY(128, 28);
						cout << "PRESS L TO SAVE THEN EXIT";
						GotoXY(128, 32);
						cout << "PRESS ANYKEY ELSE TO EXIT";
						GotoXY(0, 0);

						ambulance = true;

					}
				}

			}
			SOS->draw(takePerson);

			Sleep(50);
		}
	}
}


void inGameThread()
{
	drawLane(40, 120, 3, 5);

	int temp;

	thread t1(SubThread);

	thread t2(SubThread2);

	if (!t1.joinable())
	{
		t1.join();
	}
	if(!t2.joinable())
		t2.join();
	cg->pauseGame((HANDLE)t2.native_handle());

	while (1)
	{
		temp = toupper(_getch());

		if (!t1.joinable())
		{

			exit(1);
		}
		if (!cg->getPeople().isDead())
		{

			if (temp == 27)
			{
				t1.detach();
				t2.detach();
				cg->exitGame(t1.native_handle());
				cg->exitGame(t2.native_handle());
				exit(1);
			}
			else if (temp == 'P')
			{
				cg->pauseGame(t1.native_handle());
			}
			else if (temp == 'L')
			{
				cg->pauseGame(t1.native_handle());
				cg->saveGame();

				GotoXY(56, 26);
				cout << "RESUME GAME ? (type 'y')";
				char d;
				cin >> d;
				GotoXY(56, 26);
				cout << "                         ";
				d = toupper(d);
				if (d == 'Y')
				{
					system("cls");
					drawLane(40, 120, 3, 5);

					cg->resumeGame((HANDLE)t1.native_handle());
				}
				else {
					t1.detach();
					t2.detach();
					cg->exitGame(t1.native_handle());
					exit(1);
				}
			}
			else if (temp == 'T')
			{
				cg->pauseGame((HANDLE)t1.native_handle());
				cg->loadGame();
				GotoXY(125, 20);
				cout << "                         ";
				GotoXY(125, 22);
				cout << "                         ";
			}
			else if (temp == 'M')
			{
				cg->pauseGame((HANDLE)t1.native_handle());
				cg->settings();
				system("cls");
				drawLane(40, 120, 3, 5);
			}

			else if (temp == 'W' || temp == 'A' || temp == 'D' || temp == 'S')
			{
				cg->resumeGame((HANDLE)t1.native_handle());
				MOVING = temp;
			}
		}
		else {

			cg->resumeGame((HANDLE)t2.native_handle());
		
			if (!isPlay && cg->Sound)
			{
				PlaySound(TEXT("Sound/ambulance.wav"), NULL, SND_FILENAME | SND_ASYNC);
				isPlay = true;

			}
			if (ambulance)
			{
				PlaySound(TEXT("Sound/skip.wav"), NULL, SND_FILENAME | SND_ASYNC);
				// Reset
				ambulance = false;
				isSet = false;
				way1 = false;
				takePerson = false;
				isPlay = false;

				TextForDraw(15);
				GotoXY(128, 17);
				cout << "                            ";
				GotoXY(128, 19);
				cout << "                            ";

				GotoXY(128, 21);
				cout << "                            ";
				GotoXY(128, 23);
				cout << "                            ";
				system("cls");
				drawLane(40, 120, 3, 5);
				if (temp == 'Y') {
					cg->pauseGame((HANDLE)t2.native_handle());
					system("cls");
					cg->startGame();

				}
				else if (temp == 'R') {
					cg->pauseGame((HANDLE)t2.native_handle());

					cg->resetGame();

				}
				else if (temp == 'L') {
					cg->pauseGame((HANDLE)t2.native_handle());
					cg->saveGame();
					t1.detach();
					t2.detach();
					cg->exitGame(t1.native_handle());
					exit(1);
				}
				else {
					t2.detach();
					t1.detach();
					cg->exitGame(t2.native_handle());
					cg->exitGame(t1.native_handle());
					exit(1);
				}
			}
		}
	}

}

void printMenu(CGAME *t)
{
	PlaySound(TEXT("Sound/title.wav"), NULL, SND_FILENAME | SND_ASYNC);

	DrawLoadingBar(30, 30, 1);

	TextForDraw(2);

	system("cls");
	GotoXY(0, 0);
	drawBanner();

	drawBorder(20, 40, 72, 23);
	GotoXY(88, 26);
	cout << " NEW GAME";
	drawBorder(3, 30, 78, 25);

	GotoXY(88, 30);
	cout << " LOAD GAME";
	drawBorder(3, 30, 78, 29);

	GotoXY(88, 34);
	cout << " SETTINGS";
	drawBorder(3, 30, 78, 33);

	GotoXY(88, 38);
	cout << " EXIT GAME";
	drawBorder(3, 30, 78, 37);
	GotoXY(74, 38);
	while (1) {
		char c = NULL;
		c = _getch();
		if (c == -32) {
			c = _getch();
			if ((c == 72) && whereY() > 26) {
				GotoXY(74, whereY());
				cout << " ";
				GotoXY(74, whereY() - 4);
				cout << ">";
			}
			else if ((c == 80) && whereY() < 38) {
				GotoXY(74, whereY());
				cout << " ";
				GotoXY(74, whereY() + 4);
				cout << ">";
			}
		}
		else if (c == 'w' && whereY() > 27) {
			GotoXY(74, whereY());
			cout << " ";
			GotoXY(74, whereY() - 4);
			cout << ">";
		}
		else if (c == 's' && whereY() < 35) {
			GotoXY(74, whereY());
			cout << " ";
			GotoXY(74, whereY() + 4);
			cout << ">";
		}
		else if (c == 's' && whereY() < 38) {
			GotoXY(74, whereY());
			cout << " ";
			GotoXY(74, whereY() + 4);
			cout << ">";
		}
		else if (c == '\r') {
			PlaySound(TEXT("Sound/skip.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (whereY() == 26) { //Start
				DrawLoadingBar(30, 50, 1);
				system("cls");
				TextForDraw(15);
				inGameThread();
				system("cls");
			}
			else if (whereY() == 30) {//Load


				TextForDraw(15);
				cg->loadGame();
				
				system("cls");

				inGameThread();
				system("cls");
			}
			else if (whereY() == 34) // Settings
			{

				cg->settings();
				DrawLoadingBar(30, 50, 1);
				system("cls");
				inGameThread();
			}
			else if (whereY() == 38) //Exit
			{
				return;
			}
		}
	}

}

int main()
{

	resizeConsole(1400, 800);
	FixConsoleWindow();
	cg = new CGAME();
	printMenu(cg);

	return 0;
}
