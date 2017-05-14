#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ostream>
#include <ctime>

using namespace std;

class Player
{
private:
	char name[10];
	double rating;
	int size_p;
	double time_p;
	time_t date;

public:

	Player() : name("---------"), rating(0), size_p(0), time_p(0.0000), date(0)
	{
	}

	~Player()
	{
	}

	void set(double r, int siz, double t)
	{
		gotoxy(3, 15);
		cout << "Enter you name: "; cin >> name;
		rating = r;
		size_p = siz;
		time_p = t;
		date = time(NULL);
	}

	void show()
	{
		cout << setw(10) << name
			<< setw(10) << fixed << setprecision(2) << rating
			<< setw(10) << size_p
			<< setw(10) << fixed << setprecision(2) << time_p
			<< setw(28) << ctime(&date);
	}

	bool operator()(const Player& a, const Player& b) const
	{
		return a.rating > b.rating;
	}

	void diskOut()
	{
		ofstream outfile;
		outfile.open("snake_top.dat", ios::app | ios::binary);
		outfile.write((char*)this, sizeof(*this));
		outfile.close();
	}

	void diskIn(int num)
	{
		ifstream infile;
		infile.open("snake_top.dat", ios::binary);
		infile.seekg(num * sizeof(Player));
		infile.read((char*)this, sizeof(*this));
		infile.close();
	}
};

