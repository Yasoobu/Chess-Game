#pragma once
#include "Piece.h"
class Rook: public Piece
{
public:
	Rook();
	Rook(Position p, Color c, Board* b);
	~Rook();
	bool IsLegal(Position Des, Player P);
	bool IsLegal1(Position Des, Player P);
	void Print();
};

