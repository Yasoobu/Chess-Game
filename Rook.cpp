#include "Rook.h"
#include "Board.h"
#include<iostream>
using namespace std;

Rook::Rook()
{
}

Rook::Rook(Position p, Color c, Board* b) : Piece(p, c, b)
{
}

Rook::~Rook()
{
}

bool Rook::IsLegal(Position Des, Player P)
{
	void* BN[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			BN[i][j] = B->PieceAt(i, j);
		}
	}
	if (isVertical(Pos, Des))
	{
		return isVerticalPathClear(Pos, Des, BN);
	}
	else if(isHorizontal(Pos, Des))
	{
		return isHorizontalPathClear(Pos, Des, BN);
	}
	return false;
}

bool Rook::IsLegal1(Position Des, Player P)
{
	void* BN[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			BN[i][j] = B->PieceAt(i, j);
		}
	}
	if (isVertical(Pos, Des))
	{
		return isVerticalPathClear(Pos, Des, BN);
	}
	else if (isHorizontal(Pos, Des))
	{
		return isHorizontalPathClear(Pos, Des, BN);
	}
	return false;
}

void Rook::Print()
{
	if (this->C == BLACK)
	{
		cout << 'R';
	}
	else
		cout << 'r';
}
