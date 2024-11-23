#include "Queen.h"



Queen::Queen(int color) {
	white = color;
	alive = true;
	occupied_value = 2;
	occupied_color = color;
	whiteOne.loadFromFile("images/w_queen.png");
	blackOne.loadFromFile("images/b_queen.png");
	pieceSprite.setTexture(color ? whiteOne : blackOne);
	x = color ? 7 : 0;
	y = 3;
	pieceSprite.setPosition(sf::Vector2f(y * 100.0f + 50.0f, x * 100.0f + 50.0f));
	pieceSprite.setOrigin(sf::Vector2f(pieceSprite.getTexture()->getSize().x / 2, pieceSprite.getTexture()->getSize().y / 2));
	pieceSprite.setScale(sf::Vector2f(0.375f, 0.375f));
}

std::vector<Cell> Queen::getMoves(Cell Board[8][8], int x, int y) {
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