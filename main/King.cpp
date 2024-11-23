#include "King.h"

King::King(int color) {
	white = color;
	alive = true;
	occupied_value = 3;
	occupied_color = color;
	whiteOne.loadFromFile("images/w_king.png");
	blackOne.loadFromFile("images/b_king.png");
	pieceSprite.setTexture(color ? whiteOne : blackOne);
    x = color ? 7 : 0;
    moved = false;
    y = 4;
    pieceSprite.setPosition(sf::Vector2f(y * 100.0f + 50.0f, x * 100.0f + 50.0f));
    pieceSprite.setOrigin(sf::Vector2f(pieceSprite.getTexture()->getSize().x / 2, pieceSprite.getTexture()->getSize().y / 2));
    pieceSprite.setScale(sf::Vector2f(0.375f, 0.375f));
}

std::vector<Cell> King::getMoves(Cell Board[8][8], int x, int y) {
    possibleMoves.clear();
    int dx[] = { 1, 1, 1, -1, -1, -1, 0, 0 }; 
    int dy[] = { 1, -1, 0, -1, 1, 0, -1, 1 }; 
    for (int i = 0; i < 8; i++) {
        if (x + dx[i] > 7 || x + dx[i] < 0) continue;
        if (y + dy[i] > 7 || y + dy[i] < 0) continue;
        if (Board[x + dx[i]][y + dy[i]].occupied_color == Board[x][y].occupied_color) continue;
        if(!isCheck(Board, x + dx[i], y + dy[i])) possibleMoves.push_back(Board[x + dx[i]][y + dy[i]]);
    }
    return possibleMoves;
}

bool King::isCheck(Cell Board[8][8], int x, int y) {
    int r = x + 1;
    // check if king is being attacked from all four dieections
    while (r < 8)
    {
        if (Board[r][y].occupied_color == 0)
            continue;
        else if (Board[r][y].occupied_color == Board[x][y].occupied_color)
            break;
        else
        {
            if (Board[r][y].occupied_value == 2 || Board[r][y].occupied_value == 1)
                return true;
            else
                break;
        }
        r++;
    }
    r = x - 1;
    while (r >= 0)
    {
        if (Board[r][y].occupied_color == 0)
            continue;
        else if (Board[r][y].occupied_color == Board[x][y].occupied_color)
            break;
        else
        {
            if (Board[r][y].occupied_value == 2 || Board[r][y].occupied_value == 1)
                return true;
            else
                break;
        }
        r--;
    }
    r = y + 1;
    while (r < 8)
    {
        if (Board[x][r].occupied_color == 0)
            continue;
        else if (Board[x][r].occupied_color == Board[x][y].occupied_color)
            break;
        else
        {
            if (Board[x][r].occupied_value == 2 || Board[r][y].occupied_value == 1)
                return true;
            else
                break;
        }
        r++;
    }
    r = y - 1;
    while (r >= 0)
    {
        if (Board[x][r].occupied_color == 0)
            continue;
        else if (Board[x][r].occupied_color == Board[x][y].occupied_color)
            break;
        else
        {
            if (Board[x][r].occupied_value == 2 || Board[r][y].occupied_value == 1)
                return true;
            else
                break;
        }
        r--;
    }
    // check if it is being atteacked from diagonals
    int a = x + 1, b = y + 1;
    while (a < 8 && b < 8)
    {
        if (Board[a][b].occupied_color == 0)
            continue;
        else if (Board[a][b].occupied_color == Board[x][y].occupied_color)
            break;
        else
        {
            if (Board[a][b].occupied_value == 2 || Board[a][b].occupied_value == -2)
                return true;
            else
                break;
        }
        a++;
        b++;
    }
    a = x + 1, b = y - 1;
    while (a < 8 && b >= 0)
    {
        if (Board[a][b].occupied_color == 0)
            continue;
        else if (Board[a][b].occupied_color == Board[x][y].occupied_color)
            break;
        else
        {
            if (Board[a][b].occupied_value == 2 || Board[a][b].occupied_value == -2)
                return true;
            else
                break;
        }
        a++;
        b--;
    }
    a = x - 1, b = y + 1;
    while (a >= 0 && b < 8)
    {
        if (Board[a][b].occupied_color == 0)
            continue;
        else if (Board[a][b].occupied_color == Board[x][y].occupied_color)
            break;
        else
        {
            if (Board[a][b].occupied_value == 2 || Board[a][b].occupied_value == -2)
                return true;
            else
                break;
        }
        a--;
        b++;
    }
    a = x - 1, b - y - 1;
    while (a >= 0 && b >= 0)
    {
        if (Board[a][b].occupied_color == 0)
            continue;
        else if (Board[a][b].occupied_color == Board[x][y].occupied_color)
            break;
        else
        {
            if (Board[a][b].occupied_value == 2 || Board[a][b].occupied_value == -2)
                return true;
            else
                break;
        }
        a--;
        b--;
    }
    // check if the king is being attacked by another king
    int dx[8] = { 0, 0, 1, 1, 1, -1, -1, -1 };
    int dy[8] = { 1, -1, 1, -1, 0, 0, -1, 1 };
    for (int i = 0; i < 8; i++)
    {
        if (Board[x + dx[i]][y + dy[i]].occupied_color != Board[x][y].occupied_color && Board[x + dx[i]][y + dy[i]].occupied_value == 3)
            return true;
    }
    // check if the king is being attacked by knight of opposite colour
    int xa[] = { 2, 2, -2, -2, 1, 1, -1, -1 }; // all possible moves.
    int ya[] = { 1, -1, 1, -1, 2, -2, 2, -2 }; // all possible moves.
    for (int i = 0; i < 8; i++)
    {
        if (Board[x + xa[i]][y + ya[i]].occupied_color != Board[x][y].occupied_color && Board[x + xa[i]][y + ya[i]].occupied_value == -1)
            return true;
    }
    // loops to check if the king is being attacked by the pawn of another colour
    if (Board[x][y].occupied_color == 1)
    {
        if (x < 8 && y > 0 && Board[x + 1][y - 1].occupied_color == 0 && Board[x + 1][y - 1].occupied_value == -3)
            return true;
        if (x < 8 && y < 8 && Board[x + 1][y + 1].occupied_color == 0 && Board[x + 1][y + 1].occupied_value == -3)
            return true;
    }
    else if (Board[x][y].occupied_color == -1)
    {
        if (x > 0 && y > 0 && Board[x - 1][y - 1].occupied_color == 0 && Board[x - 1][y - 1].occupied_value == -3)
            return true;
        if (x > 0 && y < 8 && Board[x - 1][y + 1].occupied_color == 0 && Board[x - 1][y + 1].occupied_value == -3)
            return true;
    }
    return false;
}

bool King::isCheckMate(Cell Board[8][8], int x, int y) {
    if (possibleMoves.size() == 0 && isCheck(Board, x, y)) return true;
    return false;
}

bool King::isStalemate(Cell Board[8][8], int x, int y) {
    if (!isCheck(Board, x, y) && possibleMoves.size() == 0) return true;
    return false;
}


