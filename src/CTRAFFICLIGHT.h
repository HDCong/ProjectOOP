#pragma once
#include <ctime>
#include "console.h"

class CTRAFFICLIGHT
{
private:
	clock_t begin;

public:
	bool isGreen;
	CTRAFFICLIGHT();
	~CTRAFFICLIGHT();
	bool changeLight();
};

