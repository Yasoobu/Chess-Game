#include "Pawn.h"
#include"Board.h"
#include <iostream>
using namespace std;

Pawn::Pawn()
{
	
}

Pawn::Pawn(Position p, Color c, Board* b): Piece(p,c,b)
{
	
}

Pawn::~Pawn()
{
}

bool Pawn::IsLegal(Position Des, Player P)
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
	return false;
}

bool Pawn::IsLegal1(Position Des, Player P)
{
	return false;
}

void Pawn::Move(Position Des)
{
	B->setPieceAt(Des.ri, Des.ci, this);
	B->Reset(this->Pos.ri, this->Pos.ci);
	this->Pos.ri = Des.ri;
	this->Pos.ci = Des.ci;
}

void Pawn::Print()
{
	if (this->C == BLACK)
	{
		cout << 'P';
	}
	else
		cout << 'p';
}