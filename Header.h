#pragma once

enum Color{BLACK, WHITE};
struct Position
{
	bool operator == (const Position P)const
	{
		return ri == P.ri && ci == P.ci;
	}
public:
	int ri, ci;
	Position()
	{
		ri = 0;
		ci = 0;
	}
	Position(int r, int c)
	{
		ri = r;
		ci = c;
	}

};
