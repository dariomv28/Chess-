#include "Game.h"

Game::Game(sf::Color color1, sf::Color color2) {
	moves = 0;
	selected = false;
	gameStatus = true;
	whiteturn = true;
	theSelectedOne = nullptr;
	isGameOver = false;

	white_king = new King(1); white_pieces.push_back(white_king);
	black_king = new King(0); black_pieces.push_back(black_king);
	white_queen = new Queen(1); white_pieces.push_back(white_queen);
	black_queen = new Queen(0); black_pieces.push_back(black_queen);

	for (int i = 0; i < 8; i++) {
		white_pawn[i] = new Pawn(1); white_pieces.push_back(white_pawn[i]);
		black_pawn[i] = new Pawn(0); black_pieces.push_back(black_pawn[i]);
	}

	for (int i = 0; i < 2; i++) {
		white_rook[i] = new Rook(1); white_pieces.push_back(white_rook[i]);
		black_rook[i] = new Rook(0); black_pieces.push_back(black_rook[i]);
		white_knight[i] = new Knight(1); white_pieces.push_back(white_knight[i]);
		black_knight[i] = new Knight(0); black_pieces.push_back(black_knight[i]);
		white_bishop[i] = new Bishop(1); white_pieces.push_back(white_bishop[i]);
		black_bishop[i] = new Bishop(0); black_pieces.push_back(black_bishop[i]);
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Board[i][j].x = i;
			Board[i][j].y = j;
		}
	}
	SetBoardAndPieces(color1, color2);
}


void Game::SetBoardAndPieces(sf::Color color1, sf::Color color2) {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Board[i][j].squareShape.setSize(sf::Vector2f(100.0f, 100.0f));
			Board[i][j].squareShape.setPosition(sf::Vector2f(100.0f * j, 100.0f * i));
			Board[i][j].squareShape.setFillColor((i + j) % 2 == 0 ? color1 : color2);
		}
	}

	for (int i = 0; i < 8; i++) {
		white_pawn[i]->y = i;
		white_pawn[i]->pieceSprite.setPosition(sf::Vector2f(white_pawn[i]->y * 100.0f + 50.0f, white_pawn[i]->x * 100.0f + 50.0f));
		white_pawn[i]->pieceSprite.setScale(sf::Vector2f(0.375f, 0.375f));
		white_pawn[i]->pieceSprite.setOrigin(sf::Vector2f(white_pawn[i]->pieceSprite.getTexture()->getSize().x / 2, white_pawn[i]->pieceSprite.getTexture()->getSize().y / 2));

		black_pawn[i]->y = i;
		black_pawn[i]->pieceSprite.setPosition(sf::Vector2f(black_pawn[i]->y * 100.0f + 50.0f, black_pawn[i]->x * 100.0f + 50.0f));
		black_pawn[i]->pieceSprite.setScale(sf::Vector2f(0.375f, 0.375f));
		black_pawn[i]->pieceSprite.setOrigin(sf::Vector2f(black_pawn[i]->pieceSprite.getTexture()->getSize().x / 2, black_pawn[i]->pieceSprite.getTexture()->getSize().y / 2));
	}

	white_rook[0]->y = 0; white_rook[1]->y = 7;
	white_knight[0]->y = 1; white_knight[1]->y = 6;
	white_bishop[0]->y = 2; white_bishop[1]->y = 5;
	black_rook[0]->y = 0; black_rook[1]->y = 7;
	black_knight[0]->y = 1; black_knight[1]->y = 6;
	black_bishop[0]->y = 2; black_bishop[1]->y = 5;

	for (int i = 0; i < 2; i++) {
		white_rook[i]->pieceSprite.setPosition(sf::Vector2f(white_rook[i]->y * 100.0f + 50.0f, white_rook[i]->x * 100.0f + 50.0f));
		white_rook[i]->pieceSprite.setScale(sf::Vector2f(0.375f, 0.375f));
		white_rook[i]->pieceSprite.setOrigin(sf::Vector2f(white_rook[i]->pieceSprite.getTexture()->getSize().x / 2, white_rook[i]->pieceSprite.getTexture()->getSize().y / 2));
		white_knight[i]->pieceSprite.setPosition(sf::Vector2f(white_knight[i]->y * 100.0f + 50.0f, white_knight[i]->x * 100.0f + 50.0f));
		white_knight[i]->pieceSprite.setScale(sf::Vector2f(0.375f, 0.375f));
		white_knight[i]->pieceSprite.setOrigin(sf::Vector2f(white_knight[i]->pieceSprite.getTexture()->getSize().x / 2, white_knight[i]->pieceSprite.getTexture()->getSize().y / 2));
		white_bishop[i]->pieceSprite.setPosition(sf::Vector2f(white_bishop[i]->y * 100.0f + 50.0f, white_bishop[i]->x * 100.0f + 50.0f));
		white_bishop[i]->pieceSprite.setScale(sf::Vector2f(0.375f, 0.375f));
		white_bishop[i]->pieceSprite.setOrigin(sf::Vector2f(white_bishop[i]->pieceSprite.getTexture()->getSize().x / 2, white_bishop[i]->pieceSprite.getTexture()->getSize().y / 2));


		black_rook[i]->pieceSprite.setPosition(sf::Vector2f(black_rook[i]->y * 100.0f + 50.0f, black_rook[i]->x * 100.0f + 50.0f));
		black_rook[i]->pieceSprite.setScale(sf::Vector2f(0.375f, 0.375f));
		black_rook[i]->pieceSprite.setOrigin(sf::Vector2f(black_rook[i]->pieceSprite.getTexture()->getSize().x / 2, black_rook[i]->pieceSprite.getTexture()->getSize().y / 2));
		black_knight[i]->pieceSprite.setPosition(sf::Vector2f(black_knight[i]->y * 100.0f + 50.0f, black_knight[i]->x * 100.0f + 50.0f));
		black_knight[i]->pieceSprite.setScale(sf::Vector2f(0.375f, 0.375f));
		black_knight[i]->pieceSprite.setOrigin(sf::Vector2f(black_knight[i]->pieceSprite.getTexture()->getSize().x / 2, black_knight[i]->pieceSprite.getTexture()->getSize().y / 2));
		black_bishop[i]->pieceSprite.setPosition(sf::Vector2f(black_bishop[i]->y * 100.0f + 50.0f, black_bishop[i]->x * 100.0f + 50.0f));
		black_bishop[i]->pieceSprite.setScale(sf::Vector2f(0.375f, 0.375f));
		black_bishop[i]->pieceSprite.setOrigin(sf::Vector2f(black_bishop[i]->pieceSprite.getTexture()->getSize().x / 2, black_bishop[i]->pieceSprite.getTexture()->getSize().y / 2));
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 8; j++) {
			Board[i][j].occupied_color = -1;
			Board[7 - i][j].occupied_color = 1;
		}
	}

	for (int i = 0; i < 8; i++) {
		Board[1][i].occupied_value = -3;
		Board[6][i].occupied_value = -3;
	}
	Board[0][0].occupied_value = 1;
	Board[0][7].occupied_value = 1;
	Board[7][0].occupied_value = 1;
	Board[7][7].occupied_value = 1;
	Board[0][1].occupied_value = -1;
	Board[0][6].occupied_value = -1;
	Board[7][1].occupied_value = -1;
	Board[7][6].occupied_value = -1;
	Board[0][2].occupied_value = -2;
	Board[0][5].occupied_value = -2;
	Board[7][2].occupied_value = -2;
	Board[7][5].occupied_value = -2;
	Board[0][3].occupied_value = 2;
	Board[7][3].occupied_value = 2;
	Board[0][4].occupied_value = 3;
	Board[7][4].occupied_value = 3;


}


void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.clear();

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			target.draw(Board[i][j].squareShape);
		}
	}

	for (int i = 0; i < getMovesOfPiece.size(); i++) {
		target.draw(getMovesOfPiece[i].squareShape);
	}

	if (theSelectedOne != nullptr) {
		for (int i = 0; i < piecePossibleMoves.size(); i++) {
			target.draw(piecePossibleMoves[i]);
		}
	}

	for (int i = 0; i < white_pieces.size(); i++) {
		if (white_pieces[i]->alive) {
			target.draw(white_pieces[i]->pieceSprite);
		}
	}
	for (int i = 0; i < black_pieces.size(); i++) {
		if (black_pieces[i]->alive) {
			target.draw(black_pieces[i]->pieceSprite);
		}
	}
}


void Game::select(Cell Board[8][8], int x, int y) {
	if (Board[x][y].occupied_color == 0) {
		theSelectedOne = nullptr;
		return;
	}
	if (Board[x][y].occupied_color == 1 && !whiteturn || Board[x][y].occupied_color == -1 && whiteturn) {
		theSelectedOne = nullptr;
		return;
	}
	selected = true;
	if (Board[x][y].occupied_color == 1) {
		if (Board[x][y].occupied_value == -3) {
			for (int i = 0; i < 8; i++) {
				if (white_pawn[i]->y == y && white_pawn[i]->x == x) {
					theSelectedOne = white_pawn[i];
					break;
				}
			}
		}
		else if (Board[x][y].occupied_value == 1) {
			if (white_rook[0]->x == x && white_rook[0]->y == y) theSelectedOne = white_rook[0];
			else theSelectedOne = white_rook[1];
		}
		else if (Board[x][y].occupied_value == -1) {
			if (white_knight[0]->x == x && white_knight[0]->y == y) theSelectedOne = white_knight[0];
			else theSelectedOne = white_knight[1];
		}
		else if (Board[x][y].occupied_value == -2) {
			if (white_bishop[0]->x == x && white_bishop[0]->y == y) theSelectedOne = white_bishop[0];
			else theSelectedOne = white_bishop[1];
		}
		else if (Board[x][y].occupied_value == 2) {
			theSelectedOne = white_queen;
		}
		else if (Board[x][y].occupied_value == 3) {
			theSelectedOne = white_king;
		}
	}
	else {
		if (Board[x][y].occupied_value == -3) {
			for (int i = 0; i < 8; i++) {
				if (black_pawn[i]->y == y && black_pawn[i]->x == x) {
					theSelectedOne = black_pawn[i];
					break;
				}
			}
		}
		else if (Board[x][y].occupied_value == 1) {
			if (black_rook[0]->x == x && black_rook[0]->y == y) theSelectedOne = black_rook[0];
			else theSelectedOne = black_rook[1];
		}
		else if (Board[x][y].occupied_value == -1) {
			if (black_knight[0]->x == x && black_knight[0]->y == y) theSelectedOne = black_knight[0];
			else theSelectedOne = black_knight[1];
		}
		else if (Board[x][y].occupied_value == -2) {
			if (black_bishop[0]->x == x && black_bishop[0]->y == y) theSelectedOne = black_bishop[0];
			else theSelectedOne = black_bishop[1];
		}
		else if (Board[x][y].occupied_value == 2) {
			theSelectedOne = black_queen;
		}
		else if (Board[x][y].occupied_value == 3) {
			theSelectedOne = black_king;
		}
	}
	SetUIForPossibleMoves();
}

void Game::SetUIForPossibleMoves() {
	if (theSelectedOne == nullptr) return;
	getMovesOfPiece.clear();
	piecePossibleMoves.clear();
	getMovesOfPiece = theSelectedOne->getMoves(Board, theSelectedOne->x, theSelectedOne->y);
	for (int i = 0; i < getMovesOfPiece.size(); i++) {
		sf::RectangleShape cell;
		cell.setPosition(sf::Vector2f(100.0f * getMovesOfPiece[i].y, 100.0f * getMovesOfPiece[i].x));
		cell.setFillColor(sf::Color(0x66b4cc50));
		cell.setSize(sf::Vector2f(100.0f, 100.0f));
		piecePossibleMoves.push_back(cell);
	}

	sf::RectangleShape selectedCell;
	selectedCell.setPosition(sf::Vector2f(100.0f * theSelectedOne->y, 100.0f * theSelectedOne->x));
	selectedCell.setFillColor(sf::Color(0x00000000));
	selectedCell.setSize(sf::Vector2f(100.0f, 100.0f));
	selectedCell.setOutlineColor(sf::Color::Red);
	selectedCell.setOutlineThickness(-3.0f);
	piecePossibleMoves.push_back(selectedCell);
}

void Game::moveSelectedPiece(Cell Board[8][8], int x, int y) {
	if (theSelectedOne == nullptr) return;
	bool valid = false;
	std::vector<Cell> moves = theSelectedOne->getMoves(Board, theSelectedOne->x, theSelectedOne->y);
	for (auto cell : moves) {
		if (cell.x == x && cell.y == y) {
			valid = true;
			break;
		}
	}
	if (valid) {
		int old_x = theSelectedOne->x, old_y = theSelectedOne->y;
		if (whiteturn) {
			if (theSelectedOne->occupied_value == 3) {
				white_king->x = x;
				white_king->y = y;
			}
			else if (theSelectedOne->occupied_value == 2) {
				white_queen->x = x;
				white_queen->y = y;
			}
			else if (theSelectedOne->occupied_value == 1) {
				for (int i = 0; i < 2; i++) {
					if (white_rook[i]->x == old_x && white_rook[i]->y == old_y) {
						white_rook[i]->x = x;
						white_rook[i]->y = y;
					}
				}
			}
			else if (theSelectedOne->occupied_value == -1) {
				for (int i = 0; i < 2; i++) {
					if (white_knight[i]->x == old_x && white_knight[i]->y == old_y) {
						white_knight[i]->x = x;
						white_knight[i]->y = y;
					}
				}
			}
			else if (theSelectedOne->occupied_value == -2) {
				for (int i = 0; i < 2; i++) {
					if (white_bishop[i]->x == old_x && white_bishop[i]->y == old_y) {
						white_bishop[i]->x = x;
						white_bishop[i]->y = y;
					}
				}
			}

			else if (theSelectedOne->occupied_value == -3) {
				for (int i = 0; i < 8; i++) {
					if (white_pawn[i]->x == old_x && white_pawn[i]->y == old_y) {
						white_pawn[i]->x = x;
						white_pawn[i]->y = y;
						break;
					}
				}
			}

		}
		else {
			if (theSelectedOne->occupied_value == 3) {
				black_king->x = x;
				black_king->y = y;
			}
			else if (theSelectedOne->occupied_value == 2) {
				black_queen->x = x;
				black_queen->y = y;
			}
			else if (theSelectedOne->occupied_value == 1) {
				for (int i = 0; i < 2; i++) {
					if (black_rook[i]->x == old_x && black_rook[i]->y == old_y) {
						black_rook[i]->x = x;
						black_rook[i]->y = y;
					}
				}
			}
			else if (theSelectedOne->occupied_value == -1) {
				for (int i = 0; i < 2; i++) {
					if (black_knight[i]->x == old_x && black_knight[i]->y == old_y) {
						black_knight[i]->x = x;
						black_knight[i]->y = y;
					}
				}
			}
			else if (theSelectedOne->occupied_value == -2) {
				for (int i = 0; i < 2; i++) {
					if (black_bishop[i]->x == old_x && black_bishop[i]->y == old_y) {
						black_bishop[i]->x = x;
						black_bishop[i]->y = y;
					}
				}
			}

			else if (theSelectedOne->occupied_value == -3) {
				for (int i = 0; i < 8; i++) {
					if (black_pawn[i]->x == old_x && black_pawn[i]->y == old_y) {
						black_pawn[i]->x = x;
						black_pawn[i]->y = y;
						break;
					}
				}
			}
		}

		theSelectedOne->pieceSprite.setPosition(sf::Vector2f(100.0f * x + 50.0f, 100.0f * y + 50.0f));

		if (Board[x][y].occupied_color != 0 && Board[x][y].occupied_color != Board[old_x][old_y].occupied_color) {
			if (Board[old_x][old_y].occupied_color == 1) {
				for (auto piece : black_pieces) {
					if (piece->x == x && piece->y == y) {
						piece->alive = false;
						break;
					}
				}
			}
			else {
				for (auto piece : white_pieces) {
					if (piece->x == x && piece->y == y) {
						piece->alive = false;
						break;
					}
				}
			}
		}

		Board[x][y].occupied_color == whiteturn ? 1 : -1;
		Board[x][y].occupied_value == theSelectedOne->occupied_value;
		Board[old_x][old_y].occupied_color == 0;
		Board[old_x][old_y].occupied_value == 0;

		whiteturn = !whiteturn;

	}

	if (!white_king->alive || !black_king->alive) {
		gameOver();
	}

	theSelectedOne = nullptr;
	selected = false;
}

void Game::gameOver() {
	isGameOver = true;
	if (!whiteturn) {
		std::cout << "CHECKMATE! WHITE WON" << std::endl;
	}
	else {
		std::cout << "CHECKMATE! BLACK WON" << std::endl;
	}
}

bool Game::getSelected() {
	return selected;
}

