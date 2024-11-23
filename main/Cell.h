#pragma once
#include <SFML/Graphics.hpp>


class Cell
{
public:
	int x, y;
	int occupied_value // King: 3, Queen: 2, Rook: 1, Knight: -1, Bishop: 2, Pawn: -3, 0 for no pieces
		, occupied_color;  //1: white, -1: black, 0: no pieces
	int color;    // 0 black 1 white
	sf::RectangleShape squareShape;
	Cell();
};

