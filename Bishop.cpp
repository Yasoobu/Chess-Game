#include "Bishop.h"
#include "Board.h"
#include<iostream>
using namespace std;

Bishop::Bishop()
{
}

Bishop::Bishop(Position p, Color c, Board* b) : Piece(p, c, b)
{
}

Bishop::~Bishop()
{
}

bool Bishop::IsLegal(Position Des, Player P)
{
	
	cout << "x";
	void* BN[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			BN[i][j] = B->PieceAt(i, j);
		}
	}
	if (isDiagonal(Pos, Des))
	{
		return isDiagonalPathClear(Pos, Des, BN);
	}
	return false;
}

bool Bishop::IsLegal1(Position Des, Player P)
{

	if (abs(Pos.ri - Des.ri) == abs(Pos.ci - Des.ci))
	{
		int xIncrement = (Des.ri - Pos.ri) / (abs(Des.ri - Pos.ri));
		int yIncrement = (Des.ci - Pos.ci) / (abs(Des.ci - Pos.ci));

		for (int i = 1; i < abs(Pos.ri - Des.ri); i++)
		{
			std::cout << "It got here somehow";
			if (B->PieceAt(Pos.ri + xIncrement * i,Pos.ci + yIncrement * i) != nullptr)
				return false;
		}
		return true;
	}
	else
		return false;
}

void Bishop::Print()
{
	if (this->C == BLACK)
	{
		cout << 'B';
	}
	else
		cout << 'b';
}
