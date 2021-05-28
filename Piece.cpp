#include "Piece.h"
#include"Board.h"
#include"King.h"
#include<iostream>


Piece::Piece():Pos(), C()
{
	IsFirstTurn = true;
}

Piece::Piece(Position P, Color c, Board* b): Pos(P), C(c), B(b)
{
	IsFirstTurn = true;
}


Piece::~Piece()
{

}

bool Piece::isHorizontal(Position S, Position D)
{
	return S.ri==D.ri;
}

bool Piece::isVertical(Position S, Position D)
{
	return S.ci == D.ci;
}

bool Piece::isDiagonal(Position S, Position D)
{
	return abs(S.ri-D.ri) == abs(S.ci-D.ci);
}

bool Piece::isHorizontalPathClear(Position S, Position D, void* B[8][8])
{
	int start,end;
	if (D.ci > S.ci)
	{
		start = S.ci+1;
		end = D.ci-1;
	}
	else
	{
		start = D.ci+1;
		end = S.ci - 1;
	}
	for (int i = start; start <= end; i++)
	{
		if (B[S.ri][i] != nullptr)
			return false;
	}
	return true;
}

bool Piece::isVerticalPathClear(Position S, Position D, void* B[8][8])
{
	int start, end;
	if (D.ri > S.ri)
	{
		start = S.ri + 1;
		end = D.ri - 1;
	}
	else if(D.ri<S.ri)
	{
		start = D.ri + 1;
		end = S.ri - 1;
	}
	for (int i = start; start <= end; i++)
	{
		if (B[i][S.ci] != nullptr)
			return false;
	}
	return true;
}

bool Piece::isDiagonalPathClear(Position S, Position D, void* B[8][8])
{
	int startrow, endrow;
	if (D.ri > S.ri)
	{
		startrow = S.ri + 1;
		endrow = D.ri - 1;
	}
	else
	{
		startrow = D.ri + 1;
		endrow = S.ri - 1;
	}
	int startcol, endcol;
	if (D.ci > S.ci)
	{
		startcol = S.ci + 1;
		endcol = D.ci - 1;
	}
	else
	{
		startcol = D.ci + 1;
		endcol = S.ci - 1;
	}
	int j = startcol;
	for (int i = startrow ; startrow <= endrow; i++,j++)
	{
		if (B[i][j] != nullptr)
			return false;
	}
	return true;
}

bool Piece::isMyPiece(Player P, Piece* pc)
{
	return pc != nullptr && P.getColor() == pc->C;
}

bool Piece::IsLegal(Position Des, Player P)
{
	return P.getColor()==C && !isMyPiece(P, B->PieceAt(Des.ri,Des.ci));
}

void Piece::Move(Position Des)
{
	B->setPieceAt(Des.ri,Des.ci, this);
	B->Reset(this->Pos.ri, this->Pos.ci);
	this->Pos.ri = Des.ri;
	this->Pos.ci = Des.ci;
}

bool Piece::AmIKing(Piece* p)
{
	Piece* king = new King();
	if (typeid(p) == typeid(king)) { // Yes
		return true;
	}
	return false;
}

bool Piece::isFirstTurn(Piece* p)
{
	if (p->IsFirstTurn)
		return true;
	return false;
}

void Piece::setFirstTurn(Piece* p)
{
	p->IsFirstTurn = false;
}

Color Piece::getColor(Piece* p)
{
	return p->C;
}


