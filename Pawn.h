#pragma once
#include "Piece.h"
class Pawn : public Piece
{
public:
	Pawn();
	Pawn(Position p, Color c, Board* b);
	~Pawn();
	bool IsLegal(Position Des, Player P);
	bool IsLegal1(Position Des, Player P);
	void Move(Position Des);
	void Print();
};

