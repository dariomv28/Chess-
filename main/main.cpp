#include "Game.h"



int main() {

    //test

    sf::RenderWindow window(sf::VideoMode(1500, 1000), "Chess");
    Game chess(sf::Color(0xf3bc7aff), sf::Color(0xae722bff));
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (event.mouseButton.x >= 0 && event.mouseButton.x <= 800 && event.mouseButton.y >= 0 && event.mouseButton.y <= 800) {
                        int x = event.mouseButton.y / 100, y = event.mouseButton.x / 100;
                        if (!chess.isGameOver && !chess.getSelected()) {
                            chess.select(chess.Board, x, y); 
                        }
                        else {
                            chess.moveSelectedPiece(chess.Board, x, y);
                        }
                    }
                }
            }
        }
        window.draw(chess);
        window.display();
    }



    
    return 0;
}