#pragma once
#include "Piece.h"
class Knight: public Piece
{
public:
	Knight();
	Knight(Position p, Color c, Board* b);
	bool IsLegal1(Position Des, Player P);
	~Knight();
	void Print();
};

