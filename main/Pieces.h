#pragma once

#include <SFML/Graphics.hpp>
#include "Cell.h"
#include<vector>
class Pieces
{
public:
	int x, y;
	bool alive, occupied_color, white;
	int occupied_value;
	std::vector<Cell> possibleMoves;	
	sf::Sprite pieceSprite;
	virtual std::vector<Cell> getMoves(Cell Board[8][8], int x, int y) = 0;
};

