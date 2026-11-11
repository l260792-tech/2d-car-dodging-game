#include <SFML/Graphics.hpp>
#include "Assets.h"
#include "Menu.h"
#include "Player.h"
#include "Traffic.h"
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Car Dodging Game");
    window.setFramerateLimit(60);

    GameData game;
    if (!loadAssets(game)) {
        std::cerr << "Could not load the menu font. Check your asset paths.\n";
        return 1;
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            handleMenuEvent(game, event);
        }

        window.clear();

        window.draw(game.Road);
        if (game.gameStarted && !game.gameOver) {
            updatePlayer(game);
            updateTraffic(game, window);
            drawTrafficAndPlayer(game, window);
        }

        drawMenuAndHud(game, window);
        window.display();
    }
    return 0;
}