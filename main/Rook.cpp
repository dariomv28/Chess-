#include "Rook.h"


Rook::Rook(int color) {
	white = color;
	alive = true;
	occupied_value = 1;
	occupied_color = color;
	whiteOne.loadFromFile("images/w_rook.png");
	blackOne.loadFromFile("images/b_rook.png");
	pieceSprite.setTexture(color ? whiteOne : blackOne);
	x = color ? 7 : 0;
}

std::vector<Cell> Rook::getMoves(Cell Board[8][8], int x, int y) {
	possibleMoves.clear();
	int u = x - 1;
	while (u >= 0) {
		if (Board[u][y].occupied_color == 0) possibleMoves.push_back(Board[u][y]);
		else if (Board[u][y].occupied_color == Board[x][y].occupied_color) break;
		else if (Board[u][y].occupied_color != Board[x][y].occupied_color) {
			possibleMoves.push_back(Board[u][y]);
			break;
		}
		u--;
	}
	u = x + 1;
	while (u <= 7) {
		if (Board[u][y].occupied_color == 0) possibleMoves.push_back(Board[u][y]);
		else if (Board[u][y].occupied_color == Board[x][y].occupied_color) break;
		else if (Board[u][y].occupied_color != Board[x][y].occupied_color) {
			possibleMoves.push_back(Board[u][y]);
			break;
		}
		u++;
	}
	u = y - 1;
	while (u >= 0) {
		if (Board[x][u].occupied_color == 0) possibleMoves.push_back(Board[x][u]);
		else if (Board[x][u].occupied_color == Board[x][y].occupied_color) break;
		else if (Board[x][u].occupied_color != Board[x][y].occupied_color) {
			possibleMoves.push_back(Board[x][u]);
			break;
		}
		u--;
	}
	u = y + 1;
	while (u <= 7) {
		if (Board[x][u].occupied_color == 0) possibleMoves.push_back(Board[x][u]);
		else if (Board[x][u].occupied_color == Board[x][y].occupied_color) break;
		else if (Board[x][u].occupied_color != Board[x][y].occupied_color) {
			possibleMoves.push_back(Board[x][u]);
			break;
		}
		u++;
	}
	return possibleMoves;
}