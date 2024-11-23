#pragma once
#include "Pieces.h"

class Knight : public Pieces
{
public:
	std::vector<Cell> getMoves(Cell Board[8][8], int x, int y);
	sf::Texture blackOne, whiteOne;
	Knight(int color);
};

