#pragma once
#include "Piece.h"
class Highlighter : public Piece
{
public:
	void Print();
	bool IsLegal1(Position Des, Player P);
};

