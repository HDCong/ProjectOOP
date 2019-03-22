#include "GAME.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <conio.h>

using namespace std;

void clrscrObject(int x, int y)
{
	GotoXY(x, y);
	cout << "      ";
	GotoXY(x, y + 1);
	cout << "      ";

}
void clrscrObjectP(int x, int y)
{
	if (y == 16 || y == 24 || y == 32)
		TextForDraw(226);
	else TextForDraw(15);
	GotoXY(x, y);
	cout << "    ";
	GotoXY(x, y + 1);
	cout << "    ";
	TextForDraw(15);

}
void CGAME::clearObject()
{
	while (!truck.empty())
	{
		CTRUCK *a = truck.back();
		truck.pop_back();
		delete a;
	}
	while (!car.empty())
	{
		CCAR *b = car.back();
		car.pop_back();
		delete b;
	}
	while (!dinaus.empty())
	{
		CDINAUSOR *c = dinaus.back();
		dinaus.pop_back();
		delete c;
	}
	while (!bird.empty())
	{
		CBIRD *d = bird.back();
		bird.pop_back();
		delete d;
	}

}

void CGAME::addObject()
{
	CTRUCK *a = new CTRUCK(5, 36);
	truck.push_back(a);

	CCAR *b = new CCAR(96, 12);//
	car.push_back(b);

	CDINAUSOR *c = new CDINAUSOR(5, 20);
	dinaus.push_back(c);

	CBIRD *d = new CBIRD(96, 28);
	bird.push_back(d);
}

void CGAME::reArrange()
{
	truck[0]->setPosX(5);
	int d = 115 / truck.size();
	int t = 5;
	for (int i = 1;i < truck.size();i++)
	{
		t += d;
		truck[i]->setPosX(t);
	}
	car[0]->setPosX(116);
	t = 116;
	for (int i = 1;i < car.size();i++)
	{
		t -= d;
		car[i]->setPosX(t);
	}

	dinaus[0]->setPosX(5);
	t = 5;
	for (int i = 1;i < dinaus.size();i++)
	{
		t += d;
		dinaus[i]->setPosX(t);
	}
	bird[0]->setPosX(116);
	t = 116;
	for (int i = 1;i < bird.size();i++)
	{
		t -= d;
		bird[i]->setPosX(t);
	}
}


CGAME::CGAME()
{
	speed = 100;
	Sound = true;
	traff = new CTRAFFICLIGHT;
	//	for (int i = 0;i < 10;i++)
	addObject();
	reArrange();
	player.setXY(55, 40);
}

CGAME::~CGAME()
{
	clearObject();
}

void CGAME::drawGame()
{
	GotoXY(130, 4);
	cout << "PLAYER NAME: " << player.getName();
	GotoXY(130, 6);
	cout << "SOUND: ";
	GotoXY(138, 6);
	if (Sound) cout << "ON";
	else cout << "OFF";

	GotoXY(130, 8);
	cout << "LEVEL: " << truck.size();
	if (truck.size() == MAX_LEVEL) cout << " (MAX LEVEL)";

	GotoXY(130, 10);
	int t = 200 - speed;
	cout << "SPEED: " <<t <<" KM/H";
	if (t == 175) cout << " (MAXIMUM SPEED)";
	if (t == 25) cout << " (MINIMUM SPEED)";

	if (player.isDead())
	{

	}
	else {
		TextForDraw(15);
		GotoXY(128, 16);
		cout << "PRESS P TO PAUSE";
		GotoXY(128, 20);
		cout << "PRESS L TO SAVE GAME";

		GotoXY(128, 24);
		cout << "PRESS T TO LOAD GAME";
		GotoXY(128, 28);
		cout << "PRESS M TO SETTING";
		GotoXY(128, 32);
		cout << "PRESS ESC TO EXIT";
	}
	srand(time(NULL));
	for (int i = 0;i < truck.size();i++)
	{
		//TextForDraw(78);
		truck[i]->draw();

		car[i]->draw();

		dinaus[i]->draw();

		bird[i]->draw();
	}
	GotoXY(player.getX(), player.getY());
	player.draw();

}

CPEOPLE CGAME::getPeople()
{
	return player;
}

vector<CVEHICLE*> CGAME::getVehicle()
{
	vector<CVEHICLE*> res;
	for (int i = 0;i < truck.size();i++)
		res.push_back(truck[i]);
	for (int i = 0;i < car.size();i++)
		res.push_back(car[i]);
	return res;
}

vector<CANIMAL*> CGAME::getAnimal()
{
	vector<CANIMAL*> res;
	for (int i = 0;i < dinaus.size();i++)
		res.push_back(dinaus[i]);
	for (int i = 0;i < bird.size();i++)
		res.push_back(bird[i]);
	return res;
}

void CGAME::startGame()
{
	//clrscr();
	drawLane(40, 120, 3, 5);
	player.setXY(55, 40);
	player.setState(true);
	clearObject();
	traff = new CTRAFFICLIGHT;
	addObject();



}

void CGAME::resetGame()
{
	int x = player.getX(), y = player.getY();
	clrscrObjectP(x, y);
	//GotoXY(x - 1, y - 1); 
	//cout << "      ";
	//for (int i = -1;i < 3;i++)
	//{
	//	GotoXY(x + i, y + i);
	//	cout << " ";
	//	GotoXY(x - i, y + i);
	//	cout << " ";
	//}
	player.setState(true);
	player.setXY(55, 40);

}

void CGAME::exitGame(HANDLE t)
{

	TerminateThread(t, 1);
}

void CGAME::loadGame()
{
	system("cls");
	TextForDraw(242);
	drawBorder(20, 60, 55, 15);

	TextForDraw(15);
	string text;
	GotoXY(78, 18);
	cout << "LOAD GAME";
	drawBorder(3, 40, 68, 21);


	string a;
	GotoXY(56, 22);
	cout << "FILENAME: ";
	GotoXY(69, 22);

	rewind(stdin);
	getline(cin, a);
	string temp = "Data/" + a;
	//	ifstream in;

		//in.open(temp, ios::binary | ios::in);
		//if (in.fail()) {
		//	in.close();
		//	addObject();
		//	return;
		//	//	startGame();
		//}
		////	CGAME s;
		//	in.read(reinterpret_cast<char *>(this), sizeof(CGAME));

	FILE *f = fopen(temp.c_str(), "rb");
	if (!f) {
		clearObject();
		addObject();
		player.setXY(55, 40);
	}
	else {
		clearObject();

		int x, y;
		fread(&x, sizeof(int), 1, f);
		fread(&y, sizeof(int), 1, f);
		player.setXY(x, y);

		//in >> x >> y;
		//player.setXY(x, y);

		int n;
		fread(&n, sizeof(int), 1, f);

		//in >> n;

		for (int i = 0;i < n;i++)
		{

			fread(&x, sizeof(int), 1, f);
			fread(&y, sizeof(int), 1, f);
			CTRUCK *p = new CTRUCK(x, y);
			truck.push_back(p);

		}
		for (int i = 0;i < n;i++)
		{

			fread(&x, sizeof(int), 1, f);
			fread(&y, sizeof(int), 1, f);

			CCAR *p = new CCAR(x, y);
			car.push_back(p);

		}
		for (int i = 0;i < n;i++)
		{
			fread(&x, sizeof(int), 1, f);
			fread(&y, sizeof(int), 1, f);

			CBIRD *p = new CBIRD(x, y);
			bird.push_back(p);

		}
		for (int i = 0;i < n;i++)
		{
			fread(&x, sizeof(int), 1, f);
			fread(&y, sizeof(int), 1, f);
			CDINAUSOR *p = new CDINAUSOR(x, y);
			dinaus.push_back(p);

		}
		fread(&x, sizeof(int), 1, f);
		//fread(&y, sizeof(int), 1, f);
		traff->isGreen = x;
		fread(&x, 1, 1, f);
		Sound = x;

		string newname = "";
		fread(&x, 4/*sizeof(int)*/, 1, f);

		char c;
		for (int i = 0;i < x;i++)
		{
			fread(&c, 1, 1, f);
			newname.push_back(c);

		}

		player.setName(newname);
		fread(&x, 4/*sizeof(int)*/, 1, f);
		speed = x;
		fclose(f);

	}
	system("cls");
	drawLane(40, 120, 3, 5);
	drawGame();
}

void CGAME::saveGame()
{
	system("cls");
	TextForDraw(242);
	drawBorder(20, 60, 55, 15);

	TextForDraw(15);
	string text;
	GotoXY(78, 18);
	cout << " SAVE GAME";
	drawBorder(3, 40, 68, 21);


	string a;
	GotoXY(56, 22);
	cout << "FILENAME: ";
	GotoXY(69, 22);

	rewind(stdin);

	getline(cin, a);
	a = "Data/" + a;
	/*	//ofstream out;

		//out.open(a,ios::binary| ios::out);
		//out.write(reinterpret_cast<const char *> (this), sizeof(this));


		//out << player.getX() << " " << player.getY() << endl;

		//out << truck.size() << endl;

		//for (int i = 0;i < truck.size();i++)
		//	out << truck[i]->currentPosX() << " " << truck[i]->currentPosY() << endl;

		//for (int i = 0;i < car.size();i++)
		//	out << car[i]->currentPosX() << " " << car[i]->currentPosY() << endl;

		//for (int i = 0;i < bird.size();i++)
		//	out << bird[i]->currentPosX() << " " << bird[i]->currentPosY() << endl;

		//for (int i = 0;i < dinaus.size();i++)
		//	out << dinaus[i]->currentPosX() << " " << dinaus[i]->currentPosY() << endl;

		//out << traff->isGreen << endl;

		//out.close();*/

	FILE *f = fopen(a.c_str(), "wb");

	int x, y;
	x = player.getX(), y = player.getY();
	fwrite(&x, sizeof(int), 1, f);
	fwrite(&y, sizeof(int), 1, f);

	x = truck.size();
	fwrite(&x, sizeof(int), 1, f);
	for (int i = 0;i < truck.size();i++)
	{
		x = truck[i]->currentPosX();
		y = truck[i]->currentPosY();
		fwrite(&x, sizeof(int), 1, f);
		fwrite(&y, sizeof(int), 1, f);
	}

	for (int i = 0;i < car.size();i++)
	{
		x = car[i]->currentPosX();
		y = car[i]->currentPosY();
		fwrite(&x, sizeof(int), 1, f);
		fwrite(&y, sizeof(int), 1, f);
	}
	for (int i = 0;i < bird.size();i++)
	{
		x = bird[i]->currentPosX();
		y = bird[i]->currentPosY();
		fwrite(&x, sizeof(int), 1, f);
		fwrite(&y, sizeof(int), 1, f);
	}
	for (int i = 0;i < dinaus.size();i++)
	{
		x = dinaus[i]->currentPosX();
		y = dinaus[i]->currentPosY();
		fwrite(&x, sizeof(int), 1, f);
		fwrite(&y, sizeof(int), 1, f);
	}
	x = traff->isGreen;
	fwrite(&x, sizeof(int), 1, f);
	x = Sound;
	fwrite(&x, 1, 1, f);


	a = player.getName();

	x = a.length();

	fwrite(&x, sizeof(int), 1, f);

	for (int i = 0;i < x;i++)
	{
		char c = a[i];
		fwrite(&c, 1, 1, f);

	}
	x = speed;
	fwrite(&x, sizeof(int), 1, f);


	fclose(f);
}

void CGAME::pauseGame(HANDLE t)
{
	SuspendThread(t);
}

void CGAME::resumeGame(HANDLE t)
{
	ResumeThread(t);
}

void CGAME::updatePosPeople(char MOVING)
{
	clrscrObjectP(player.getX(), player.getY());
	if (MOVING == 'W')
		player.Up();
	if (MOVING == 'S')
		player.Down();
	if (MOVING == 'A')
		player.Left();
	if (MOVING == 'D')
		player.Right();
}

void CGAME::updatePosVehicles()
{
	vector<CVEHICLE*> list = getVehicle();

	for (int i = 0;i < list.size();i++)
	{
		int a = list[i]->currentPosX(), b = list[i]->currentPosY();
		clrscrObject(a, b);
		list[i]->Move(120, 28);
		if (a < 8 && (player.getY() == b - 1 || player.getY() == b + 1) && Sound)
			list[i]->Beep();
	}
}

void CGAME::updatePosAnimals()
{
	vector<CANIMAL*> list = getAnimal();

	for (int i = 0;i < list.size();i++)
	{
		int a = list[i]->currentPosX(), b = list[i]->currentPosY();
		clrscrObject(a, b);
		list[i]->Move(120, 28);
		if (a < 8 && (player.getY() == b - 1 || player.getY() == b + 1) && Sound)
			list[i]->Tell();
	}
}

void CGAME::updateLevel()
{
	clrscrObjectP(player.getX(), player.getY());
	if (truck.size() == MAX_LEVEL)
	{
		GotoXY(55, 3);
		cout << "YOU PASSED ALL LEVEL OF THIS GAME";
		GotoXY(55, 4);
		cout << "RESET TO LEVEL 1";
		clearObject();
	}
	addObject();

	reArrange();

	player.setXY(55, 40);
}

void CGAME::whenImpact()
{

	int x = player.getX(), y = player.getY();
	TextForDraw(76);
	GotoXY(x, y);
	cout << "    ";
	GotoXY(x, y + 1);
	cout << "    ";
	if (Sound)
	{
		PlaySound(TEXT("Sound/crash.wav"), NULL, SND_FILENAME | SND_ASYNC);
		Sleep(3000);
	}


	player.setState(false);
	TextForDraw(15);
	GotoXY(128, 20);
	cout << "PRESS ANYKEY TO CALL AN AMBULANCE";
	GotoXY(0, 0);

	/*GotoXY(128, 20);
	cout << "                                 ";*/
	GotoXY(128, 24);
	cout << "                                 ";

	GotoXY(128, 28);
	cout << "                                 ";
	GotoXY(128, 32);
	cout << "                                 ";
	GotoXY(128, 16);
	cout << "                                 ";
	GotoXY(0, 0);

	TextForDraw(15);

	//GotoXY(105, 15);
	//cout << "TO RESTART, PRESS 'R', IF NO PRESS ANYKEY";
	//char c = toupper(getchar());
	//if(c=='R')
	//resetGame();
	//else {
	//}
}

void CGAME::whenFinish()
{
	TextForDraw(178);
	GotoXY(57, 3);
	cout << "CONGRATULATIONS";
	GotoXY(60, 4);
	cout << "LEVEL UP";
	TextForDraw(15);

	if (Sound)
	{
		PlaySound(TEXT("Sound/levelUp.wav"), NULL, SND_FILENAME | SND_ASYNC);
		Sleep(6000);
	}
	system("cls");
	drawLane(40, 120, 3, 5);
	updateLevel();

}

void CGAME::settings() // Setting menu
{
	system("cls");
	TextForDraw(242);
	drawBorder(35, 65, 50, 10);

	TextForDraw(15);
	string text;
	TextForDraw(2);
	GotoXY(78,12);
	cout << "SETTINGS";


	GotoXY(56, 17);
	cout << "PLAYER NAME:";
	drawBorder(3, 40, 70, 16);

	GotoXY(56,21);
	cout << "CHOOSE LEVEL:";
	drawBorder(3, 40, 70, 20);

	GotoXY(56, 25);
	cout << "SOUND ENABLE:";
	drawBorder(3, 5, 70, 24);
	GotoXY(56, 29);
	cout << "HIGHER SPEED:";
	drawBorder(3, 5, 70, 28);
	GotoXY(56, 33);
	cout << "LOWER SPEED:";
	drawBorder(3, 5, 70, 32);
	GotoXY(78, 37);
	cout << "LET'S GO";
	drawBorder(3, 15, 75, 36);
	GotoXY(78, 37);

	if (Sound)
	{
		GotoXY(71, 25);
		cout << (char)219 << (char)219 << (char)219;
	}
	bool higher = false;
	bool lower = false;
	while (1) {
		char c = NULL;
		c = _getch();
		if (c == -32) {
			c = _getch();
			if ((c == 72) && whereY() > 17) {
				GotoXY(52, whereY());
				cout << " ";
				GotoXY(52, whereY() - 4);
				cout << ">";
			}
			else if ((c == 80) && whereY() < 37) {
				GotoXY(52, whereY());
				cout << " ";
				GotoXY(52, whereY() + 4);
				cout << ">";
			}
		}
		else if (c == 'w' && whereY() > 18) {
			GotoXY(52, whereY());
			cout << " ";
			GotoXY(52, whereY() - 4);
			cout << ">";
		}
		else if (c == 's' && whereY() < 33) {
			GotoXY(52, whereY());
			cout << " ";
			GotoXY(52, whereY() + 4);
			cout << ">";
		}
		else if (c == 's' && whereY() < 37) {
			GotoXY(52, whereY());
			cout << " ";
			GotoXY(52, whereY() + 4);
			cout << ">";
		}
		else if (c == '\r') {

			if (whereY() == 17) {
				GotoXY(71, 17);
				rewind(stdin);
				getline(cin, text);
				GotoXY(52,17); cout << " ";
				GotoXY(52, 21);
				player.setName(text);
			}
			else if (whereY() == 21) {
				GotoXY(71, 21);
				rewind(stdin);
				int d;
				cin >> d;
				if (d < 0) d = 1;
				if (d > MAX_LEVEL) d = MAX_LEVEL;
				clearObject();
				for (int i = 0;i < d;i++)
					addObject();
				reArrange();
				GotoXY(52, 21); cout << " ";
				GotoXY(52, 25);
				player.setXY(55, 40);
			}
			else if (whereY() == 25)
			{
				GotoXY(71, 25);
				if (!Sound)
				{
					cout << (char)219 << (char)219 << (char)219;
					Sound = true;
				}
				else
				{
					cout << "   ";
					Sound = false;
				}
				GotoXY(52, 25); cout << " ";

				GotoXY(52, 29);

			}
			else if (whereY() == 29)
			{
				GotoXY(71, 29);
				cout << (char)219 << (char)219 << (char)219;
				GotoXY(71, 33);
				cout << "   ";
				higher = true;
				lower = false;
				GotoXY(52, 29); cout << " ";
				GotoXY(52, 37);

			}
			else if (whereY() == 33)
			{
				GotoXY(71, 29);
				cout << "   ";

				GotoXY(71, 33);
				cout << (char)219 << (char)219 << (char)219;

				higher = false;
				lower = true;
				GotoXY(52, 33); cout << " ";
				GotoXY(52, 37);
			}
			else if (whereY() == 37)
			{
				if (higher) {
					if (speed > 25) speed -= 25;
				}
				else if (lower) {
					if (175 - speed < 0) return;
					speed += 25; 
				}
				return;
			}
		}
	}
}

