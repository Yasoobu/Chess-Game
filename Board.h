#pragma once
#include "Piece.h"
class Peice;

class Board
{
	Piece* Ps[8][8];
public:
	Board();
	~Board();
	void Init();
	Piece* PieceAt(int ri, int ci);
	void Reset(int ri, int ci);
	void setPieceAt(int ri, int ci, Piece* p);
};

