#pragma once
#include "Piece.h"
class Queen : public Piece
{
public:
	Queen();
	Queen(Position p, Color c, Board* b);
	~Queen();
	bool IsLegal(Position Des, Player P);
	bool IsLegal1(Position Des, Player P);
	void Print();
};

