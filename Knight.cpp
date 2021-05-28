#include "Knight.h"
#include "Board.h"
#include<iostream>
using namespace std;

Knight::Knight()
{
}

Knight::Knight(Position p, Color c, Board* b) : Piece(p, c, b)
{
}

bool Knight::IsLegal1(Position Des, Player P)
{
	return false;
}

Knight::~Knight()
{
}


//bool Knight::IsLegal(Position Des, Player P)
//{
//	void* BN[8][8];
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			BN[i][j] = B->PieceAt(i, j);
//		}
//	}
//	//checking path for 2-horizontal and 1-vertical
//	if (isVertical(Pos, Des))
//	{
//		return isVerticalPathClear(Pos, Des, BN);
//	}
//	return false;
//}

void Knight::Print()
{
	if (this->C == BLACK)
	{
		cout << 'N';
	}
	else
		cout << 'n';
}
