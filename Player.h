#pragma once
#include <String>
#include "Header.h"
using namespace std;

class Player
{
	string name;
	Color C;
public:
	Player();
	~Player();
	void setName(string n)
	{
		name = n;
	}
	void setColor(Color c)
	{
		C = c;
	}
	string getName(){return name;}
	Color getColor(){return C;	}
};

