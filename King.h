#pragma once
#include "Piece.h"
class King : public Piece
{
public:
	King();
	King(Position p, Color c, Board* b);
	bool IsLegal1(Position Des, Player P);
	~King();
	void Print();
};

