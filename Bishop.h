#pragma once
#include "Piece.h"
class Bishop : public Piece
{
public:
	Bishop();
	Bishop(Position p, Color c, Board* b);
	~Bishop();
	bool IsLegal(Position Des, Player P);
	bool IsLegal1(Position Des, Player P);
	void Print();
};

