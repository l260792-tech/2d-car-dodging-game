#include <SFML/Graphics.hpp>
#include <iostream>

#include "Assets.h"
#include "Menu.h"
#include "Player.h"
#include "Traffic.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Car Dodging Game");
    window.setFramerateLimit(60);

    GameData game; //It will load required assets
    if (!loadAssets(game)) {
        std::cerr << "Could not load the menu font. Check your asset paths.";
        return 1;
    }
    //Main game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) 
                window.close();
            handleMenuEvent(game, event);
        }
         
        window.clear(); //clear the window


        window.draw(game.Road);  //draw road


        if (game.gameStarted && !game.gameOver) 
        {
            updatePlayer(game);
            updateTraffic(game, window);
            drawTrafficAndPlayer(game, window);
        }

        drawMenuAndHud(game, window);
        window.display();
    }
    return 0;
}


