#pragma once
#include <windows.h>
#include <iostream>

using namespace std;

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

enum ConsoleColor
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
	LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void ramka()
{
	setlocale(LC_ALL, "C");
	cout << static_cast <char> (201);
	for (int i = 0; i < 78; i++)
		cout << static_cast <char> (205);
	cout << static_cast <char> (187);

	for (int j = 0; j < 22; j++)
	{
		cout << static_cast <char> (186);
		for (int i = 0; i < 78; i++)
			cout << " ";
		cout << static_cast <char> (186);
	}

	cout << static_cast <char> (200);
	for (int i = 0; i < 78; i++)
		cout << static_cast <char> (205);
	cout << static_cast <char> (188);
	setlocale(LC_ALL, "Russian");
}

void ramka2()
{
	setlocale(LC_ALL, "C");
	cout << static_cast <char> (201);
	for (int i = 0; i < 78; i++)
		cout << static_cast <char> (205);
	cout << static_cast <char> (187);

	for (int j = 0; j < 22; j++)
	{
		gotoxy(0, 1 + j);
		cout << static_cast <char> (186);
		gotoxy(79, 1 + j);
		cout << static_cast <char> (186);
	}

	cout << static_cast <char> (200);
	for (int i = 0; i < 78; i++)
		cout << static_cast <char> (205);
	cout << static_cast <char> (188);
	setlocale(LC_ALL, "Russian");
}