#include "Player.h"
//update
void updatePlayer(GameData& game) 
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) 
        game.Pause = true;
	
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) 
        game.Pause = false;
	
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && game.player.getPosition().y > 140.f)
        game.player.move(sf::Vector2f(0.f, -7.f));
	
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && game.player.getPosition().y < 580.f - game.player.getGlobalBounds().height)
        game.player.move(sf::Vector2f(0.f, 7.f));

    float ypos = game.player.getPosition().y; //this code block is for resetting the car if it goes out of bounds of the road
	
    if (ypos < 140.f)
        ypos = 140.f;
	
    if (ypos + game.player.getGlobalBounds().height > 580.f)
        ypos = 580.f - game.player.getGlobalBounds().height;
	
    game.player.setPosition(sf::Vector2f(game.player.getPosition().x, ypos));
}
