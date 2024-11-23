#pragma once
#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include <iostream>
class Game : public sf::Drawable{
private:
	bool gameStatus, whiteturn, selected; // 1 for white, 0 for black
	int  moves;
	std::vector<Cell> getMovesOfPiece;
	std::vector<sf::RectangleShape> piecePossibleMoves;
	std::vector<Pieces*> white_pieces;
	std::vector<Pieces*> black_pieces;

	Pawn* white_pawn[8], *black_pawn[8];
	Rook* white_rook[2], *black_rook[2];
	Knight* white_knight[2], *black_knight[2];
	Bishop* white_bishop[2], *black_bishop[2];
	Queen* white_queen, *black_queen;
	King* white_king, *black_king;

	
	Pieces* theSelectedOne;

	sf::RectangleShape restartBox;
	sf::Font font;
	sf::Text restart, turn;


public:
	Game(sf::Color color1, sf::Color color2);   // these 2 colors are used for the board
	void SetBoardAndPieces(sf::Color color1, sf::Color color2); // color1: light, color2: dark

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void gameOver();	
	void select(Cell Board[8][8], int x, int y);  // to select a piece
	void Run();
	bool isGameOver;
	Cell Board[8][8];
	bool getSelected();
	void SetUIForPossibleMoves();
	void moveSelectedPiece(Cell Board[8][8], int x, int y);
};

