#include "Chess.h"
#include<conio.h>
#include<time.h>
#include<Windows.h>
#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Pawn.h"
#include "Highlighter.h"
#include "Player.h"
#include <stdlib.h>
#include <Windows.h>
#include <typeinfo>
#include <vector> 
void getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}
void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}

bool Chess::BishopIsLegal(Position Pos, Position Des, Board* B)
{

	if (abs(Pos.ri - Des.ri) == abs(Pos.ci - Des.ci))
	{
		int xIncrement = (Des.ri - Pos.ri) / (abs(Des.ri - Pos.ri));
		int yIncrement = (Des.ci - Pos.ci) / (abs(Des.ci - Pos.ci));

		for (int i = 1; i < abs(Pos.ri - Des.ri); i++)
		{
			std::cout << "It got here somehow";
			if (B->PieceAt(Pos.ri + xIncrement * i, Pos.ci + yIncrement * i) != nullptr)
				return false;
		}
		return true;
	}
	else
		return false;
}

bool Chess::RookIsLegal(Position Pos, Position Des, Board* B)
{
	return false;
}

bool Chess::KnightIsLegal(Position Pos, Position Des, Board* B)
{
	return false;
}

bool Chess::QueenIsLegal(Position Pos, Position Des, Board* B)
{
	return false;
}

bool Chess::KingIsLegal(Position Pos, Position Des, Board* B)
{
	return false;
}

bool Chess::CheckforCheck(Board B, Player myplyayer)
{
	for (int i = 0;i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (B.PieceAt(i,j)!=nullptr && B.PieceAt(i, j)->getColor(B.PieceAt(i, j)) != myplyayer.getColor())
			{
				for (int ii = 0; ii <8; ii++)
				{
					for (int jj = 0; jj < 8; jj++)
					{

					}
				}
			}
		}
	}
	return false;
}

bool Chess::PawnIsLegal(Position Pos, Position Des, Board* B)
{
	return false;
}

Chess::Chess()
{

}

Chess::~Chess()
{
}

void Chess::Init()
{
	B.Init();
	cout << "Player 1 and Player 2" << endl;
	for (int i = 0; i < 2; i++)
	{
		string s;
		cin >> s;
		Ps[i].setName(s);
	}
}

void Chess::DisplayBoard()
{
	system("cls");
	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			if (B.PieceAt(ri, ci) == nullptr)
			{
				cout << '-';
			}
			else
			{
				B.PieceAt(ri, ci)->Print();
			}
		}
		cout << endl;
	}
}

void Chess::TurnChange()
{
	if (Turn == BLACK)
		Turn = WHITE;
	else
		Turn = BLACK;
}

void TurnMsg(string n)
{
	cout << endl<<endl<<n << "'s turn\n" << endl;
}

void Chess::Highlight(Position Src, Board &B, Player p, vector<Position> &highlightedcells)
{
	//King* kingg = new King();
	Piece* king = new King();
	Piece* queen = new Queen();
	Piece* knight = new Knight();
	Piece* bishop = new Bishop();
	Piece* rook = new Rook();
	Piece* pawn = new Pawn();
	if(typeid(*B.PieceAt(Src.ri,Src.ci)) == typeid(*king))
	{
		gotoRowCol(100, 100);
		cout << "Piece is a King";
		int rri=-1;
		int cci = -1;
		int cend = 2;
		int rend = 2;
		if (Src.ri == 0)
			rri++;
		if (Src.ci == 0)
			cci++;
		if (Src.ci == 7)
			cend--;
		if (Src.ri == 7)
			rend--;

		//if (p.getColor() == BLACK)
		//	Des.ri = Src.ri + 1;
		//else
		//	Des.ri = Src.ri - 1;

		for (int i = rri; i < rend; i++)
		{
			for (int j = cci; j < cend; j++)
			{
				if (i == 0 && j == 0)
					continue;
				Position Des(Src.ri + i, Src.ci + j);
				if (B.PieceAt(Src.ri, Src.ci)->IsLegal(Des, p))
				{
					Piece* highlighter=new Highlighter();
					B.setPieceAt(Des.ri, Des.ci, highlighter);
					highlightedcells.push_back(Des);
				}
			}
		}
	}
	else if (typeid(*B.PieceAt(Src.ri, Src.ci)) == typeid(*knight))
	{
		gotoRowCol(100, 100);
		cout << "Piece is a Knight";
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				Position Des(i, j);
				if (B.PieceAt(Src.ri, Src.ci)->IsLegal(Des, p))
				{
					if ((abs(Src.ri - Des.ri) == 2 && abs(Src.ci - Des.ci) == 1) || (abs(Src.ri - Des.ri) == 1 && abs(Src.ci - Des.ci) == 2))
					{
						Piece* highlighter = new Highlighter();
						B.setPieceAt(Des.ri, Des.ci, highlighter);
						highlightedcells.push_back(Des);
					}
				}
			}
		}
		
	}
	else if (typeid(*B.PieceAt(Src.ri, Src.ci)) == typeid(*bishop))
	{
		gotoRowCol(100, 100);
		cout << "Piece is a Bishop";
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				Position Des(i, j);
				if (B.PieceAt(Src.ri, Src.ci)->IsLegal(Des, p) && BishopIsLegal(Src,Des,&B))
				{
					int xIncrement = (Des.ri - Src.ri) / (abs(Des.ri - Src.ri));
					int yIncrement = (Des.ci - Src.ci) / (abs(Des.ci - Src.ci));

					for (int i = 1; i < abs(Src.ri - Des.ri); i++)
					{
						std::cout << "It got here somehow";
						Piece* highlighter = new Highlighter();
						B.setPieceAt(Src.ri + xIncrement * i, Src.ci + yIncrement * i, highlighter);
						Position Dess(Src.ri + xIncrement * i, Src.ci + yIncrement * i);
						highlightedcells.push_back(Dess);
						//if (B->PieceAt(Pos.ri + xIncrement * i, Pos.ci + yIncrement * i) != nullptr)
						//	return false;
					}
					Piece* highlighter = new Highlighter();
					B.setPieceAt(Des.ri, Des.ci, highlighter);
					highlightedcells.push_back(Des);
					
				}
			}
		}
	}
	else if (typeid(*B.PieceAt(Src.ri, Src.ci)) == typeid(*rook))
	{
		gotoRowCol(100, 100);
		cout << "Piece is a Rook";
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				Position Des(i, j);
				if (B.PieceAt(Src.ri, Src.ci)->IsLegal(Des, p) && B.PieceAt(Src.ri, Src.ci)->IsLegal1(Des, p))
				{
					if (Src.ri == Des.ri)
					{
						int start;
						int end;
						if (Src.ci < Des.ci)
						{
							start = Src.ci + 1;
							end = Des.ci;
						}
						else
						{
							start = Des.ci;
							end = Src.ci-1;
						}
						for (int i = start; i <= end; i++)
						{
							Piece* highlighter = new Highlighter();
							B.setPieceAt(Des.ri, i, highlighter);
							Position Dess(Des.ri, i);
							highlightedcells.push_back(Dess);
						}
					}
					else if (Src.ci == Des.ci)
					{
						int start;
						int end;
						if (Src.ri < Des.ri)
						{
							start = Src.ri + 1;
							end = Des.ri;
						}
						else
						{
							start = Des.ri;
							end = Src.ri - 1;
						}
						for (int i = start; i <= end; i++)
						{
							Piece* highlighter = new Highlighter();
							B.setPieceAt(i, Des.ci, highlighter);
							Position Dess(i, Des.ci);
							highlightedcells.push_back(Dess);
						}
					}
				}
			}
		}
	}
	else if (typeid(*B.PieceAt(Src.ri, Src.ci)) == typeid(*pawn))
	{
		gotoRowCol(100, 100);
		cout << "Piece is a Pawn";
		Piece* pawnpc = B.PieceAt(Src.ri, Src.ci);
		if (B.PieceAt(Src.ri, Src.ci)->isFirstTurn(B.PieceAt(Src.ri, Src.ci)))
		{
			Position Des;
			Des.ci = Src.ci;
			if (p.getColor() == BLACK) {
				Des.ri = Src.ri + 2;
				if (B.PieceAt(Src.ri + 1, Src.ci) != nullptr)
					return;
			}
			else {
				Des.ri = Src.ri - 2;
				if (B.PieceAt(Src.ri - 1, Src.ci) != nullptr)
					return;
			}

			if (B.PieceAt(Src.ri, Src.ci)->IsLegal(Des, p))
			{
				Piece* highlighter = new Highlighter();
				B.setPieceAt(Des.ri, Des.ci, highlighter);
				highlightedcells.push_back(Des);
			}
		}
		else
		{
			Position Des;
			Des.ci = Src.ci;
			if (p.getColor()== BLACK)
				Des.ri = Src.ri + 1;
			else
				Des.ri = Src.ri - 1;

			if (B.PieceAt(Src.ri, Src.ci)->IsLegal(Des, p))
			{
				Piece* highlighter = new Highlighter();
				B.setPieceAt(Des.ri, Des.ci, highlighter);
				highlightedcells.push_back(Des);
			}
		}
		
	}
	else if (typeid(*B.PieceAt(Src.ri, Src.ci)) == typeid(*queen))
	{
	gotoRowCol(100, 100);
	cout << "Piece is a Queen";
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Position Des(i, j);
			//if (B.PieceAt(Src.ri, Src.ci)->IsLegal(Des, p) && B.PieceAt(Src.ri, Src.ci)->IsLegal1(Des, p))
			//{
				if (B.PieceAt(Src.ri, Src.ci)->isVertical(Src,Des))
				{
					int start;
					int end;
					if (Src.ri < Des.ri)
					{
						start = Src.ri + 1;
						end = Des.ri;
					}
					else
					{
						start = Des.ri;
						end = Src.ri - 1;
					}
					for (int i = start; i <= end; i++)
					{
						bool stop = false;
						if (B.PieceAt(i, Des.ci) != nullptr)
							stop = true;
						Piece* highlighter = new Highlighter();
						B.setPieceAt(i, Des.ci, highlighter);
						Position Dess(i, Des.ci);
						highlightedcells.push_back(Dess);
						if (stop)
							break;
					}

				}
				else if (B.PieceAt(Src.ri, Src.ci)->isHorizontal(Src, Des))
				{
					int start;
					int end;
					if (Src.ci < Des.ci)
					{
						start = Src.ci + 1;
						end = Des.ci;
					}
					else
					{
						start = Des.ci;
						end = Src.ci - 1;
					}
					for (int i = start; i <= end; i++)
					{
						bool stop = false;
						if (B.PieceAt(Des.ri, i) != nullptr)
							stop = true;
						Piece* highlighter = new Highlighter();
						B.setPieceAt(Des.ri, i, highlighter);
						Position Dess(Des.ri, i);
						highlightedcells.push_back(Dess);
						if (stop)
							break;
					}
				}
				else if (B.PieceAt(Src.ri, Src.ci)->isDiagonal(Src, Des))
				{
					int xIncrement = (Des.ri - Src.ri) / (abs(Des.ri - Src.ri));
					int yIncrement = (Des.ci - Src.ci) / (abs(Des.ci - Src.ci));

					for (int i = 1; i < abs(Src.ri - Des.ri); i++)
					{
						bool stop = false;
						if (B.PieceAt(Des.ri, i) != nullptr)
							stop = true;
						std::cout << "It got here somehow";
						Piece* highlighter = new Highlighter();
						B.setPieceAt(Src.ri + xIncrement * i, Src.ci + yIncrement * i, highlighter);
						Position Dess(Src.ri + xIncrement * i, Src.ci + yIncrement * i);
						highlightedcells.push_back(Dess);
						if (stop)
							break;
					}
					Piece* highlighter = new Highlighter();
					B.setPieceAt(Des.ri, Des.ci, highlighter);
					highlightedcells.push_back(Des);
				}
				

			//}
		}
	}
	}
}

//void Chess::Highlight1(Position Src, Board& B, Board NB)
//{
//
//}

void Chess::UnHighlight(Position Src, Board &B, Board NB)
{
	B = NB;
	DisplayBoard();
}

void Chess::Play()
{
	Turn = BLACK;
	Ps[0].setColor(BLACK);
	Ps[1].setColor(WHITE);
	Position Src, Dst;

	do 
	{
		DisplayBoard();
		TurnMsg(Ps[Turn].getName());
		getRowColbyLeftClick(Src.ri, Src.ci);
		if (B.PieceAt(Src.ri, Src.ci) == nullptr)
		{
			cout << "There's no piece over there... Try again\n\n";
			_getch();
			continue;
		}
		//part for highlighting the potential move options
		Board NB = B;
		vector<Position> highlightedcells;
		Highlight(Src, B, Ps[Turn],highlightedcells);
		DisplayBoard();
		getRowColbyLeftClick(Dst.ri, Dst.ci);
		UnHighlight(Src, B, NB);
		int i;
		for (i = 0; i < highlightedcells.size(); i++)
		{
			if (highlightedcells[i] == Dst)
				break;
		}
		if (i == highlightedcells.size())
		{
			cout << "Illegal Move... Try again\n\n";
			Sleep(1000);
			UnHighlight(Src, B, NB);
			continue;
		}

		
		if (B.PieceAt(Src.ri, Src.ci)->IsLegal(Dst, Ps[Turn]))
		{
			B.PieceAt(Src.ri, Src.ci)->setFirstTurn(B.PieceAt(Src.ri, Src.ci));
			B.PieceAt(Src.ri, Src.ci)->Move(Dst);
			
			if (CheckforCheck(B, Ps[Turn]))
			{
				gotoRowCol(4, 15);
				cout << "Check!";
				Sleep(1000);
			}
			TurnChange();
		}
		else
		{
			cout << "Illegal Move... Try again\n\n";
			Sleep(1000);
			UnHighlight(Src, B, NB);
			_getch();
			
		}

	}
	while (true);
}
