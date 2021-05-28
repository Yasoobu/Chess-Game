#pragma once
#include "Header.h"
#include "Player.h"
//#include "Board.h"
class Board;

class Piece
{
protected:
	bool IsFirstTurn;
	Position Pos;
	Color C;
	Board* B;
public:
	bool isMyPiece(Player P, Piece* pc);
	bool isHorizontal(Position S, Position D);
	bool isVertical(Position S, Position D);
	bool isDiagonal(Position S, Position D);
	bool isHorizontalPathClear(Position S, Position D, void* B[8][8]);
	bool isVerticalPathClear(Position S, Position D, void* B[8][8]);
	bool isDiagonalPathClear(Position S, Position D, void* B[8][8]);
	Piece();
	Piece(Position P, Color c, Board* b);
	~Piece();
    bool IsLegal(Position Des, Player P);
	virtual bool IsLegal1(Position Des, Player P)=0;
	void Move(Position Des);
	bool AmIKing(Piece* p);
	bool isFirstTurn(Piece* p);
	void setFirstTurn(Piece* p);
	Color getColor(Piece* p);
	virtual void Print()=0;
};



