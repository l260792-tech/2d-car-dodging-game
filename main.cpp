#include <SFML/Graphics.hpp>
#include "Assets.h"
#include "Menu.h"
#include "Player.h"
#include "Traffic.h"
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Car Dodging Game");
    window.setFramerateLimit(60);
     sf::Image icon;
     if (icon.loadFromFile("assets/icon.png"))
     {
     window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
     }
    GameData game;
    if (!loadAssets(game)) {
        std::cerr << "Could not load the menu font. Check your asset paths.\n";
        return 1;
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
            handleMenuEvent(game, event);

        }

        window.clear();
        // road loop
        

        window.draw(game.Road);
        window.draw(game.Road2);// end
        float roadspd = game.speed;
        if (game.isboost)
        {
            roadspd *= 3.f;
        }
        if (game.gameStarted && !game.gameOver && !game.Pause) {
            game.Road.move(roadspd*0.8f, 0.f);
            game.Road2.move(roadspd*0.8f, 0.f);

            if (game.Road.getPosition().x <= -1280.f)
            {
                game.Road.setPosition(game.Road2.getPosition().x + game.Road2.getGlobalBounds().width, 0.f);
            }

            if (game.Road2.getPosition().x <= -1280.f)
            {
                game.Road2.setPosition(game.Road.getPosition().x + game.Road.getGlobalBounds().width, 0.f);
            }
            updatePlayer(game);
            game.hitbox.setPosition(game.player.getPosition().x,game.player.getPosition().y-30);
            updateTraffic(game, window);
            drawTrafficAndPlayer(game, window);
        }

        drawMenuAndHud(game, window);
        window.display();
    }
    return 0;
}
