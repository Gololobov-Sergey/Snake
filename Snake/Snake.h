#pragma once
#include <windows.h>
#include <ctime>
#include<vector>
#include"myFunction.h"

using namespace std;

class Snake
{
private:
	int posx;
	int posy;
	int color;

public:
	Snake()
	{
		posx = 0;
		posy = 0;
		color = 7;
	}

	Snake(int x, int y, int col)
	{
		posx = x;
		posy = y;
		color = col;
	}

	~Snake()
	{
	}

	void food_set(vector <Snake> snake, string *map)
	{
		bool set = true;
		do
		{
			set = true;
			srand(time(NULL));
			posx = rand() % 78 + 1;
			posy = rand() % 22 + 1;
			if (map[posy][posx] == 's' || map[posy][posx] == 'c' || map[posy][posx] == 'b')
			{
				set = false;
			}
		
			for (int i = 0; i < snake.size(); i++)
			{
				if (posx == snake[i].posx && posy == snake[i].posy)
				{
					set = false;
					break;
				}
				else
					continue;		
			}
		} while (!set);
	}

	void setpos(int x, int y, int col)
	{
		posx = x;
		posy = y;
		color = col;
	}

	void show(char z, int col)
	{
		int x = posx;
		int y = posy;
		SetColor(col, 0);
		gotoxy(x, y);
		cout << z;
		SetColor(7, 0);
	}

	bool wall(string *mapp)
	{
		if (mapp[posy][posx] == 'b' || mapp[posy][posx] == 's' || mapp[posy][posx] == 'c')
			return true;
		else
			return false;
	}

	bool operator== (Snake S) 
	{
		if (posx == S.posx && posy == S.posy)
			return true;
		else
			return false;
	}

	bool cannibal(vector <Snake> snake)
	{
		bool can = false;
		for (int i = 1; i < snake.size(); i++)
		{
			if (snake.front() == snake[i])
			{
				gotoxy(snake.front().posx, snake.front().posy);
				SetColor(12, 0);
				cout << "#";
				SetColor(7, 0);
				can = true;
				break;
			}
			else
				can = false;
		}
		return can;
	}
};

