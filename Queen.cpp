#include "Queen.h"
#include "Board.h"
#include<iostream>
using namespace std;

Queen::Queen()
{
}

Queen::Queen(Position p, Color c, Board* b) : Piece(p, c, b)
{
}

Queen::~Queen()
{
}

bool Queen::IsLegal(Position Des, Player P)
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
		return isVerticalPathClear(Pos, Des, BN);
	}
	else if (isDiagonal(Pos, Des))
	{
		return isDiagonalPathClear(Pos, Des, BN);
	}
	return false;
}

bool Queen::IsLegal1(Position Des, Player P)
{
	return false;
}

void Queen::Print()
{
	if (this->C == BLACK)
	{
		cout << 'Q';
	}
	else
		cout << 'q';
}
