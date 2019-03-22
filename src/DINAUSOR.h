#ifndef CDINAUSOR_H
#define CDINAUSOR_H
#include "ANIMAL.h"
class CDINAUSOR:public CANIMAL
{
public:
	CDINAUSOR();
	CDINAUSOR(int x, int y) : CANIMAL(x, y) {};
	~CDINAUSOR();
public:
	void Move(int, int);
	void Tell();
	void draw();

};

#endif // !CDINAUSOR_H


