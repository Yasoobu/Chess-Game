#include "King.h"
#include"Board.h"
#include<iostream>
using namespace std;

King::King()
{
}

King::King(Position p, Color c, Board* b) : Piece(p, c, b)
{
}

bool King::IsLegal1(Position Des, Player P)
{
	return false;
}

King::~King()
{
}


void King::Print()
{
	if (this->C == BLACK)
	{
		cout << 'K';
	}
	else
		cout << 'k';
}
