#include "Bishop.h"

Bishop::Bishop(int color) {
	white = color;
	alive = true;
	occupied_value = -2;
	occupied_color = color;
	whiteOne.loadFromFile("images/w_bishop.png");
	blackOne.loadFromFile("images/b_bishop.png");
	pieceSprite.setTexture(color ? whiteOne : blackOne);
	x = color ? 7 : 0;
}

std::vector<Cell> Bishop::getMoves(Cell Board[8][8], int x, int y) {
	possibleMoves.clear();
	int moveX = x + 1, moveY = y + 1;
	while (moveX <= 7 && moveY <= 7) {
		if (Board[moveX][moveY].occupied_color == 0) possibleMoves.push_back(Board[moveX][moveY]);
		else if (Board[moveX][moveY].occupied_color == Board[x][y].occupied_color) break;
		else {
			possibleMoves.push_back(Board[moveX][moveY]);
			break;
		}
		moveX++; moveY++;
	}
	moveX = x + 1; moveY = y - 1;
	while (moveX <= 7 && moveY >= 0) {
		if (Board[moveX][moveY].occupied_color == 0) possibleMoves.push_back(Board[moveX][moveY]);
		else if (Board[moveX][moveY].occupied_color == Board[x][y].occupied_color) break;
		else {
			possibleMoves.push_back(Board[moveX][moveY]);
			break;
		}
		moveX++; moveY--;
	}

	moveX = x - 1; moveY = y + 1;
	while (moveX >= 0 && moveY <= 7) {
		if (Board[moveX][moveY].occupied_color == 0)
			possibleMoves.push_back(Board[moveX][moveY]);
		else if (Board[moveX][moveY].occupied_color == Board[x][y].occupied_color)
			break;
		else {
			possibleMoves.push_back(Board[moveX][moveY]);
			break;
		}
		moveX--; moveY++;
	}

	moveX = x - 1; moveY = y - 1;
	while (moveX >= 0 && moveY >= 0) {
		if (Board[moveX][moveY].occupied_color == 0)
			possibleMoves.push_back(Board[moveX][moveY]);
		else if (Board[moveX][moveY].occupied_color == Board[x][y].occupied_color)
			break;
		else {
			possibleMoves.push_back(Board[moveX][moveY]);
			break;
		}
		moveX--; moveY--;
	}
	
	return possibleMoves;
}