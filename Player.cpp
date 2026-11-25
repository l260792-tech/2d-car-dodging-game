#include "Player.h"
void updatePlayer(GameData& game) {
   
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && game.player.getPosition().y > 140.f)
        game.player.move(sf::Vector2f(0.f, -7.f));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && game.player.getPosition().y < 580.f - game.player.getGlobalBounds().height)
        game.player.move(sf::Vector2f(0.f, 7.f));

    if (game.boosttimer > 0) 
    {
        game.boosttimer--;

        if (game.boosttimer == 0) 
        {
            game.isboost = false;
            game.boostdelay = 600;
        }
    }

    if (game.boostdelay > 0) 
    {
        game.boostdelay--;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && game.boostdelay == 0 && !game.isboost )
    {
        game.isboost = true;
        game.boosttimer = 60;
        if (game.boostm.openFromFile("assets/boost.wav"))
        {
            game.boostm.setLoop(false);
            game.boostm.setVolume(30.f);
            game.boostm.play();
        }
    }

    float barwidthratio = 1.f;
    
    if (game.boosttimer > 0)
    {
        barwidthratio = static_cast<float>(game.boosttimer) / 60.f;
    }
    else if (game.boostdelay > 0)
    {
        barwidthratio = 1.f - static_cast<float>(game.boostdelay) / 600.f;
    }

    game.boostbar.setSize(sf::Vector2f(200.f * barwidthratio,25.f));
/*    game.boostbar2.setSize(sf::Vector2f(200 / bar2widthratio, 40.f));*/

    float ypos = game.player.getPosition().y; //reset the car if it moves out of the road
    if (ypos < 140.f)
        ypos = 140.f;
    if (ypos + game.player.getGlobalBounds().height > 580.f)
        ypos = 580.f - game.player.getGlobalBounds().height;
    game.player.setPosition(sf::Vector2f(game.player.getPosition().x, ypos));
}
