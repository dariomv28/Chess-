#include "Pawn.h"



Pawn::Pawn(int color) {
	white = color;
	alive = true;
	occupied_value = -3;
	occupied_color = color;
	whiteOne.loadFromFile("images/w_pawn.png");
	blackOne.loadFromFile("images/b_pawn.png");
	pieceSprite.setTexture(color ? whiteOne : blackOne);
	x = color ? 6 : 1;
}

std::vector<Cell> Pawn::getMoves(Cell Board[8][8], int x, int y) {
	possibleMoves.clear();
	if (Board[x][y].occupied_color == -1) {
		if (x == 1) {
			if (Board[x + 2][y].occupied_color == 0) possibleMoves.push_back(Board[x + 2][y]);
		}
		if (x != 7) {
			if (Board[x + 1][y].occupied_color == 0 && Board[x+1][y].occupied_value == 0) possibleMoves.push_back(Board[x + 1][y]);

		}
		if (y != 0 && Board[x + 1][y - 1].occupied_color == 1) possibleMoves.push_back(Board[x + 1][y - 1]);
		if (y != 7 && Board[x+1][y+1].occupied_color == 1) possibleMoves.push_back(Board[x + 1][y + 1]);
	}

	if (Board[x][y].occupied_color == 1) {
		if (x == 6) {
			if (Board[x - 2][y].occupied_color == 0) possibleMoves.push_back(Board[x - 2][y]);
		}
		if (x != 0) {
			if (Board[x - 1][y].occupied_color == 0 && Board[x - 1][y].occupied_value == 0) possibleMoves.push_back(Board[x - 1][y]);

		}
		if (y != 0 && Board[x - 1][y - 1].occupied_color == -1) possibleMoves.push_back(Board[x - 1][y - 1]);
		if (y != 7 && Board[x - 1][y + 1].occupied_color == -1) possibleMoves.push_back(Board[x - 1][y + 1]);
	}
	return possibleMoves;
}