#include "Knight.h"

Knight::Knight(int color) {
	white = color;
	alive = true;
	occupied_value = -1;
	occupied_color = color;
	whiteOne.loadFromFile("images/w_knight.png");
	blackOne.loadFromFile("images/b_knight.png");
	pieceSprite.setTexture(color ? whiteOne : blackOne);
	x = color ? 7 : 0;
}

std::vector<Cell> Knight::getMoves(Cell Board[8][8], int x, int y) {
	possibleMoves.clear();
	int dx[8] = { 2, 2, -2, -2, 1, 1, -1, -1 }; // all possible moves.
	int dy[8] = { 1, -1, 1, -1, 2, -2, 2, -2 }; // all possible moves.
	for (int i = 0; i < 8; i++) {
		if (x + dx[i] > 7 || x + dx[i] < 0) continue;
		if (y + dy[i] > 7 || y + dy[i] < 0) continue;
		if (Board[x][y].occupied_color == Board[x + dx[i]][y + dy[i]].occupied_color) continue;
		possibleMoves.push_back(Board[x + dx[i]][y + dy[i]]);
	}
	return possibleMoves;
}