#pragma once
#include "PEOPLE.h"
#include "CTRAFFICLIGHT.h"
#include "TRUCK.h"
#include "CAR.h"
#include "DINAUSOR.h"
#include "BIRD.h"
#include <Windows.h>
#include <vector>
using namespace std;

#define MAX_LEVEL 5
class CGAME
{
private:
	vector<CTRUCK*> truck;
	vector<CCAR*> car;
	vector<CDINAUSOR*> dinaus;
	vector<CBIRD*> bird;
	CTRAFFICLIGHT *traff;
	CPEOPLE player;
	int speed;
private:
	void clearObject();
	void addObject();
	void reArrange();
public:
	CGAME();
	~CGAME();
	bool Sound;
	void drawGame();
	CPEOPLE getPeople();
	vector<CVEHICLE*> getVehicle();
	vector<CANIMAL*> getAnimal();
	CTRAFFICLIGHT *getTraff() { return traff; };
	int getSpeed() { return speed; };
	void startGame();
	void resetGame();
	void exitGame(HANDLE);
	void loadGame();
	void saveGame();
	void pauseGame(HANDLE );
	void resumeGame(HANDLE);
	void updatePosPeople(char);
	void updatePosVehicles();
	void updatePosAnimals();
	void updateLevel();
	void whenImpact();
	void whenFinish();
	void settings();

};

