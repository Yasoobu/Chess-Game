#pragma once
#include "Board.h"
#include "Piece.h"
#include "Player.h";
#include <vector>
#include<iostream>
using namespace std;

class Chess
{
	Board B;
	Player Ps[2];
	int Turn;
protected:
	void Highlight(Position Src, Board &B, Player p, vector<Position> &highlightedcells);
	void UnHighlight(Position Src, Board &B, Board NB);
public:
	Chess();
	~Chess();
	void Init();
	void DisplayBoard();
	void TurnChange();
	bool BishopIsLegal(Position Pos, Position Des, Board* B);
	bool RookIsLegal(Position Pos, Position Des, Board* B);
	bool KnightIsLegal(Position Pos, Position Des, Board* B);
	bool QueenIsLegal(Position Pos, Position Des, Board* B);
	bool KingIsLegal(Position Pos, Position Des, Board* B);
	bool CheckforCheck(Board B, Player myplyayer);
	bool PawnIsLegal(Position Pos, Position Des, Board* B);
	void Play();
};

