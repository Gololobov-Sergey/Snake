#include <iostream>
#include <windows.h>
#include "Snake.h"
#include <conio.h>
#include <vector>
#include "Menu.h"
#include "Player.h"
#include <algorithm>
#include <ctime>


void top10show()
{
	system("cls");
	gotoxy(29, 2);
	SetColor(12, 15);
	cout << "-=::  T O P  1 0  ::=-";
	SetColor(7, 0);
	gotoxy(5, 4);
	cout << setw(10) << "Name" << setw(10) << "Rating" << setw(10) << "Length" << setw(10) << "Time" << setw(28) << "Date";
	gotoxy(5, 5);
	cout << "---------------------------------------------------------------------";
}

string map[24] = {
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" };

string map1[24] = {
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" };

string map2[24] = {
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                 sssssss   s     s     s     s    s   sssssss                b",
	"b                 s         ss    s    sсs    sсссs    s                      b",
	"b                 s         sсs   s   sсссs   sссs     s                      b",
	"b                 sssssss   sссsссs  sсссссs  ssss     sssssss                b",
	"b                       s   s   sсs  sssssss  sсссs    s                      b",
	"b                       s   s    ss  s     s  s    s   s                      b",
	"b                 sssssss   s     s  s     s  s     s  sssssss                b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"b                                                                             b",
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" };

void map_set(string *ma_)
{
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			map[i][j] = ma_[i][j];
		}
	}
}

void mapshow(string *m_)

{
	gotoxy(0, 0);
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			setlocale(LC_ALL, "C");
			if (m_[i][j] == 'b') { SetColor(15, 0); cout << static_cast <char> (178); }
			if (m_[i][j] == 's') { SetColor(13, 0); cout << static_cast <char> (177); }
			if (m_[i][j] == 'с') { SetColor(15, 0); cout << " "; }
			if (m_[i][j] == ' ') { SetColor(15, 0); cout << " "; }
			setlocale(LC_ALL, "Russian");
		}
		cout << endl;
	}
}

using namespace std;

int main() {

	SetColor(14, 0);
	cout << "                      __     " << endl;
	cout << "        ---_ ...... _/_ -    " << endl;
	cout << "      /  .      ./ .'*\\ \\   " << endl;
	cout << "       : '         /__-'   \\." << endl;
	cout << "      /                      )" << endl;
	cout << "    _/                 >   .''" << endl;
	cout << "  /   .   .       _.-  '/ .'  " << endl;
	cout << "  \\           __/`     / .'/| " << endl;
	cout << "    \\ '--  .-` /     //'  |\\| " << endl;
	cout << "     \\|  \\ | /      //_ _ |/| " << endl;
	cout << "      `.  \\:      //|_ _ _|\\| " << endl;
	cout << "      | \\/.     //  | _ _ |/| " << endl;
	cout << "       \\_ | \\/ /     \\ _ _ \\\\\\ " << endl;
	cout << "           \\__/       \\\ _ _ \\|\\" << endl;
	SetColor(7, 0);
	gotoxy(45, 5); SetColor(15, 12);
	cout << "-= S N A K E =-";
	gotoxy(42, 8); SetColor(13, 0);
	cout << "IT STEP   GololobovSA";
	gotoxy(49, 10);
	cout << "Ver 3.14";
	gotoxy(30, 17);
	system("pause");
	setlocale(LC_ALL, "Russian");
	char c, head, body = '#';
	int size;
	int x_start = 37, y_start = 17, x, y, sel, nap, lev, pause, pause0=200, food_color=7, color=7;
	bool foood;
	double time_s, time_p, rating = 0;
	Snake food;
	vector <string> textmenu1 = { "Новая игра" , "Таблица рекордов" , "Выход" };
	vector <string> textmenu2 = { "Уровень 1" , "Уровень 2" , "Уровень 3", "Уровень 4", "Уровень 5", "Уровень 6" };
	Menu start, level;
	vector <Player> top(10);
	for (int i = 0; i < 10; i++)
		top[i].diskIn(i);
	do
	{
		system("cls");
		sel = start.select_vertical(textmenu1);
		switch (sel)
		{
		case 0: {
			system("cls");
			lev = level.select_vertical(textmenu2);
			switch (lev)
			{
			case 0:
				pause = 200;
				map_set(map1);
				break;
			case 1:
				pause = 150;
				map_set(map1);
				break;
			case 2:
				pause = 100;
				map_set(map1);
				break;
			case 3:
				pause = 100;
				map_set(map1);
				break;
			case 4:
				pause = 100;
				map_set(map2);
				break;
			case 5:
				map_set(map2);
				break;
			default:
				break;
			}
			system("cls");
			gotoxy(0, 0);
			mapshow(map);
			size = 3;
			vector <Snake> snake(size);
			c = 0, head = static_cast<char>(16);
			time_s = clock();
			foood = false;
			x = x_start;
			y = y_start;
			nap = 0;
			snake.front().setpos(x, y, color);
			snake.front().show(head, color);
			for (int i = 1; i < snake.size(); i++)
			{
				snake[i].setpos(x - i, y, color);
				snake[i].show(body, color);
			}

			do
			{
				if (!foood)
				{
					food_color = rand() % 14 + 1;
					food.food_set(snake, map);
					food.show('*', food_color);
					SetColor(7, 0);
					foood = true;
				}

l1:			if (_kbhit())
				c = _getch();

			switch (c)
			{
			case 77:
				if (nap == 2)
				{
					x -= 1;
					head = static_cast<char>(17);
					break;
				}
				else
				{
					x += 1;
					nap = 1;
					head = static_cast<char>(16);
					break;
				}
			case 75:
				if (nap == 1)
				{
					x += 1;
					head = static_cast<char>(16);
					break;
				}
				else
				{
					x -= 1;
					nap = 2;
					head = static_cast<char>(17);
					break;
				}
			case 80:
				if (nap == 4)
				{
					y -= 1;
					head = static_cast<char>(30);
					break;
				}
				else
				{
					y += 1;
					nap = 3;
					head = static_cast<char>(31);
					break;
				}
			case 72:
				if (nap == 3)
				{
					y += 1;
					head = static_cast<char>(31);
					break;
				}
				else
				{
					y -= 1;
					nap = 4;
					head = static_cast<char>(30);
					break;
				}
			default:
				goto l1;
				break;
			}
			Snake T(x, y, 0);
			for (int i = 0; i < snake.size(); i++)
			{
				Snake T2 = T;
				T = snake[i];
				snake[i] = T2;
			}
			snake.front().show(head, color);
			for (int i = 1; i < snake.size(); i++)
			{
				snake[i].show(body, color);
			}
			if (snake.front() == food)
			{
				snake.insert(snake.end(), T);
				color = food_color;
				foood = false;
			}
			else
			{
				T.show(' ', 0);
				T.~Snake();
			}
			gotoxy(0, 24);
			time_p = (clock() - time_s) / CLOCKS_PER_SEC;
			rating = snake.size()*(0.5 + static_cast <double> (lev+1)/2);
			if (lev == 3 || lev == 5)
				pause = pause0 - snake.size() * 5;
			cout << " Length: " << setw(3) << snake.size() << setw(9) << "  Time: " << fixed << setprecision(2) << setw(6) << time_p << "  Rating: " << setw(7) <<  fixed << setprecision(2) << rating << "  Speed: " << 40000/pause << setw(10) << "  Level: " << setw(2) << lev+1;
			Sleep(pause);
			} while (!snake.front().wall(map) && !snake.front().cannibal(snake));
			gotoxy(32, 8);
			cout << "G A M E  O V E R";
			Player temp;
			temp.set(rating, snake.size(), time_p);
			top.insert(top.end(), temp);
			sort(top.begin(), top.end(), Player());
			top10show();
			for (int i = 0; i < 10; i++)
			{
				top[i].diskOut();
				gotoxy(5, 6 + i);
				top[i].show();
			}
			gotoxy(0, 20);
			system("pause");
			break;
		}
		case 1:
			top10show();
			for (int i = 0; i < 10; i++)
			{
				gotoxy(5, 6 + i);
				top[i].show();
			}
			gotoxy(0, 20);
			system("pause");
			break;
		case 2:
			exit(0);
		default:
			break;
		}
	} while (sel != 3);
	gotoxy(0, 24);
	system("pause");
}