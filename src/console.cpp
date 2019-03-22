#include "console.h"
#include <string>
#include <iostream>
using namespace std;


void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

int whereX(void)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.X;
}

int whereY(void)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.Y;
}

void TextColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void TextForDraw(int k)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, k);

}
void drawWalkSide(int height, int width, int x, int y)
{
	TextForDraw(226);
	for (int i = 6;i < 8;i++)
	{
		GotoXY(x + 1, i);
		for (int j = 0;j < width - x + 1;j++)
			cout << " ";
	}
	for (int i = 16;i < 18;i++)
	{
		GotoXY(x + 1, i);
		for (int j = 0;j < width - x + 1;j++)
			cout << " ";
	}
	for (int i = 24;i < 26;i++)
	{
		GotoXY(x + 1, i);
		for (int j = 0;j < width - x + 1;j++)
			cout << " ";
	}
	for (int i = 32;i < 34;i++)
	{
		GotoXY(x + 1, i);
		for (int j = 0;j < width - x + 1;j++)
			cout << " ";
	}
	TextForDraw(15);

}

void drawBorder(int height, int width, int x, int y) {
	GotoXY(x, y);
	cout << (char)218;
	for (int i = 0; i < width - 2; i++)
		cout << (char)196;
	cout << (char)191;
	for (int i = 1; i < height - 1; i++) {
		GotoXY(x, y + i);
		cout << (char)179;
		GotoXY(x + width - 1, y + i);
		cout << (char)179;
	}
	GotoXY(x, y + height - 1);
	cout << (char)192;
	for (int i = 0; i < width - 2; i++)
		cout << (char)196;
	cout << (char)217;
	//TextForDraw(15);

}
void drawLane(int height, int width, int x, int y) {

	drawBorder(height, width, x, y);
	GotoXY(x + 1, 39);
	for (int i = 0;i < width - x + 1;i++)
		cout << (char)196;
	GotoXY(x + 1, 34);
	for (int i = 0;i < width - x + 1;i++)
		cout << (char)196;
	GotoXY(x + 1, 31);
	for (int i = 0;i < width - x + 1;i++)
		cout << (char)196;
	GotoXY(x + 1, 26);
	for (int i = 0;i < width - x + 1;i++)
		cout << (char)196;
	GotoXY(x + 1, 23);
	for (int i = 0;i < width - x + 1;i++)
		cout << (char)196;
	GotoXY(x + 1, 18);
	for (int i = 0;i < width - x + 1;i++)
		cout << (char)196;
	GotoXY(x + 1, 15);
	for (int i = 0;i < width - x + 1;i++)
		cout << (char)196;
	GotoXY(x + 1, 10);
	for (int i = 0;i < width - x + 1;i++)
		cout << (char)196;
	TextForDraw(226);

	drawBorder(20, 40, 125, 15); // Menu box ingame
	drawBorder(12, 40, 125, 2); // Information box ingame
	TextForDraw(15);

	drawWalkSide(height, width, x, y);

}



void clrscr() {
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

void SetText(const string &text, const int &x, const int &y) {
	GotoXY(x, y), cout << text;
}
void SettingMenu() {
	drawBorder(60, 20, 29, 4);

	TextForDraw(2);
	string text = "SETTINGS";
	SetText(text, 60 - text.length() / 2, 2);

	SetText("New player name:", 33, 6);
	drawBorder(32, 1, 53, 5);

	SetText("Change level:", 33, 10);
	drawBorder(32, 1, 53, 9);

	SetText("Sound", 33, 14);
	drawBorder(32, 1, 53, 9);

}
void drawBanner()
{
	cout << endl << endl << endl;
	cout << "\t\t\t\t\t\t\t\t         _______  _______  _______  ______ " << endl;
	cout << "\t\t\t\t\t\t\t\t        (  ____ )(  ___  )(  ___  )(  __  \\" << endl;
	cout << "\t\t\t\t\t\t\t\t        | (    )|| (   ) || (   ) || (  \\  )" << endl;
	cout << "\t\t\t\t\t\t\t\t        | (____)|| |   | || (___) || |   ) |" << endl;
	cout << "\t\t\t\t\t\t\t\t        |     __)| |   | ||  ___  || |   | |" << endl;
	cout << "\t\t\t\t\t\t\t\t        | (\\ (   | |   | || (   ) || |   ) |" << endl;
	cout << "\t\t\t\t\t\t\t\t        | ) \\ \\__| (___) || )   ( || (__/  )" << endl;
	cout << "\t\t\t\t\t\t\t\t        |/   \\__/(_______)|/     \\|(______/" << endl << endl;
	cout << "\t\t\t\t\t\t\t _______  _______  _______  _______  _______ _________ _        _______ " << endl;
	cout << "\t\t\t\t\t\t\t(  ____ \\(  ____ )(  ___  )(  ____ \\(  ____ \\\\__   __/( (    /|(  ____ \\" << endl;
	cout << "\t\t\t\t\t\t\t| (    \\/| (    )|| (   ) || (    \\/| (    \\/   ) (   |  \\  ( || (    \\/" << endl;
	cout << "\t\t\t\t\t\t\t| |      | (____)|| |   | || (_____ | (_____    | |   |   \\ | || |      " << endl;
	cout << "\t\t\t\t\t\t\t| |      |     __)| |   | |(_____  )(_____  )   | |   | (\\ \\) || | ____ " << endl;
	cout << "\t\t\t\t\t\t\t| |      | (\\ (   | |   | |      ) |      ) |   | |   | | \\   || | \\_  )" << endl;
	cout << "\t\t\t\t\t\t\t| (____/\\| ) \\ \\__| (___) |/\\____) |/\\____) |___) (___| )  \\  || (___) |" << endl;
	cout << "\t\t\t\t\t\t\t(_______/|/   \\__/(_______)\\_______)\\_______)\\_______/|/    )_)(_______) " << endl;


}
void DrawLoadingBar(int x, int y, int time)
{
	TextForDraw(178);
	GotoXY(x, y);

	for (int i = 0;i < 100;i++)
		cout << (char)177;
	Sleep(150);
	TextForDraw(15);

	cout << "LOADING...";
	GotoXY(x, y);
	
	TextForDraw(178);
	for (int i = 0;i < 100;i++)
	{
		cout << (char)219;
		Sleep(time*10);
	}
	TextForDraw(15);
	cout << "COMPLETE!!!";

}