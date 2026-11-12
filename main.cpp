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
        //
        game.Road.move(game.speed, 0.f);
        game.Road2.move(game.speed, 0.f);

        if (game.Road.getPosition().x <= -1280.f)
        {
            game.Road.setPosition(game.Road2.getPosition().x + 1280.f, 0.f);
        }

        if (game.Road2.getPosition().x <= -1280.f)
        {
            game.Road2.setPosition(game.Road.getPosition().x + 1280.f, 0.f);
        }

        window.draw(game.Road);
        window.draw(game.Road2);// end


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


