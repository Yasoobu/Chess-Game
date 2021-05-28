
#include <fstream>
#include<iostream>
using namespace std;
#include "Board.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Piece.h"

Board::Board()
{
}

Board::~Board()
{
}

void Board::Init()
{
	ifstream Rdr("Text.txt");
	char ch;
	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			Rdr >> ch;
			switch (ch) {
			case '-':
				Ps[ri][ci] = nullptr;
				break;
			case 'P':
				Ps[ri][ci] = new Pawn(Position(ri, ci), BLACK, this);
				break;
			case 'R':
				Ps[ri][ci] = new Rook(Position(ri, ci), BLACK, this);
				break;
			case 'N':
				Ps[ri][ci] = new Knight(Position(ri, ci), BLACK, this);
				break;
			case 'B':
				Ps[ri][ci] = new Bishop(Position(ri, ci), BLACK, this);
				break;
			case 'Q':
				Ps[ri][ci] = new Queen(Position(ri, ci), BLACK, this);
				break;
			case 'K':
				Ps[ri][ci] = new King(Position(ri, ci), BLACK, this);		//Player 1 pieces end here
				break;
			case 'p':
				Ps[ri][ci] = new Pawn(Position(ri, ci), WHITE, this);
				break;
			case 'r':
				Ps[ri][ci] = new Rook(Position(ri, ci), WHITE, this);
				break;
			case 'n':
				Ps[ri][ci] = new Knight(Position(ri, ci), WHITE, this);
				break;
			case 'b':
				Ps[ri][ci] = new Bishop(Position(ri, ci), WHITE, this);
				break;
			case 'q':
				Ps[ri][ci] = new Queen(Position(ri, ci), WHITE, this);
				break;
			case 'k':
				Ps[ri][ci] = new King(Position(ri, ci), WHITE, this);		//Player 2 pieces end here
				break;
			}
			//if (ch == '-')
			//{
			//	Ps[ri][ci] = nullptr;
			//}
			//else if (ch == 'P' || ch == 'R' || ch == 'N' || ch == 'B' || ch == 'Q' || ch == 'K')
			//{
			//	Ps[ri][ci] = new Pawn(Position(ri, ci), BLACK, this);
			//}
			//else if (ch == 'p' || ch == 'r' || ch == 'n' || ch == 'b' || ch == 'q' || ch == 'k')
			//{
			//	Ps[ri][ci] = new Pawn(Position(ri, ci), WHITE, this);
			//}
		}
	}
}

Piece* Board::PieceAt(int ri, int ci)
{
	return Ps[ri][ci];
}

void Board::Reset(int ri, int ci)
{
	Ps[ri][ci] = nullptr;
}

void Board::setPieceAt(int ri, int ci, Piece* p)
{
	Ps[ri][ci] = p;
}
