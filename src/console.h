#pragma once
#include <Windows.h>
#include <iostream>
using namespace std;

void FixConsoleWindow();
void GotoXY(int x, int y);
void resizeConsole(int width, int height);
int whereX(void);
int whereY(void);
//void TextColor(WORD color);
void TextForDraw(int color);
void drawBorder(int height, int width, int x, int y);
void drawLane(int height, int width, int x, int y);
void clrscr();
void SettingMenu();
void drawBanner();
void DrawLoadingBar(int x, int y, int time);
