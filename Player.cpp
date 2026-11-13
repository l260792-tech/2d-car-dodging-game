#include "Player.h"

void updatePlayer(GameData& game)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) 
        game.Pause = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) 
        game.Pause = false;

    float speed = 7.0f;

    sf::Vector2f position = game.player.getPosition();  //current player position
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        position.y -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        position.y += speed;
    }
    
    float topLimit = 140.0f;
	float playerHeight = game.player.getGlobalBounds().height;
	float bottomLimit = 580.0f - playerHeight;

    //Player should be inside the road boundaries
    if(position.y < topLimit)
		position.y = topLimit;
    if (position.y > bottomLimit)
        position.y = bottomLimit;
    
    game.player.setPosition(position);
    
}


