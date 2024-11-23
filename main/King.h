#pragma once
#include "Pieces.h"
class King : public Pieces
{
public:
	std::vector<Cell> getMoves(Cell Board[8][8], int x, int y);
	sf::Texture blackOne, whiteOne;
	bool isCheck(Cell Board[8][8], int x, int y);
	bool isCheckMate(Cell Board[8][8], int x, int y);
	bool isStalemate(Cell Board[8][8], int x, int y);
	bool moved;

	bool canCastle(Cell Board[8][8], int x, int y);

	King(int color);
};

