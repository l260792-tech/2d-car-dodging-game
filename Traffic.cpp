#include "Traffic.h"
#include <cstdlib>
#include <fstream>
//traffic logic
void updateTraffic(GameData& game, const sf::RenderWindow& window) 
{
    //slow-traffic powerup slows the speed
    float trafficSpeed = game.speed;
    if (game.slowTrafficTimer > 0) 
    {
        trafficSpeed *= 0.5f;
        game.slowTrafficTimer--;
    }

    for (int i = 0; i < static_cast<int>(game.cars.size()); i++) 
    {
        game.cars[i].move(sf::Vector2f(trafficSpeed, 0.f));
        float carWidth = game.car.getGlobalBounds().width;
        if (game.cars[i].getPosition().x < -carWidth)
        {
            game.cars.erase(game.cars.begin() + i);
            i--;
            game.score++;
        }
    }

    if (game.carSpawnTimer < game.spawnDelay) 
        game.carSpawnTimer++;
    if (game.carSpawnTimer >= game.spawnDelay) 
    {
        int spawnIndex = std::rand() % 3;
        int texind = std::rand() % 2;

        game.car.setTexture(game.carTex[texind]);
        game.car.setPosition(static_cast<float>(window.getSize().x),
            game.spawnYPositions[spawnIndex]);
        game.cars.push_back(sf::Sprite(game.car));
        game.carSpawnTimer = 0;
    }

    // Count frames until the next powerup appears.
    game.powerUpSpawnTimer++;

    if (game.powerUpSpawnTimer >= game.powerUpSpawnDelay) 
    {
        PowerUp item;
        item.type = std::rand() % 2; // Randomly choose shield or slow traffic.

        //Set texture of powerup
        item.sprite.setTexture(game.powerUpTextures[item.type]);

        // Scale the image to fit within about 55 by 55 pixels.

        sf::Vector2u imageSize = game.powerUpTextures[item.type].getSize();
        if (imageSize.x > 0 && imageSize.y > 0) 
        {
            float scaleX = 55.f / static_cast<float>(imageSize.x);
            float scaleY = 55.f / static_cast<float>(imageSize.y);
            float scale = (scaleX < scaleY) ? scaleX : scaleY;

            item.sprite.setScale(scale, scale);
            item.sprite.setOrigin(imageSize.x / 2.f, imageSize.y / 2.f);
        }

        int lane = std::rand() % 3;
        item.sprite.setPosition(
            static_cast<float>(window.getSize().x) +220.f,
            game.spawnYPositions[lane] + 35.f
        );
        game.powerUps.push_back(item);
        game.powerUpSpawnTimer = 0;
    }

    // Move powerups left and remove any that leave the screen.
    for (int i = 0; i < static_cast<int>(game.powerUps.size()); i++) 
    {
        game.powerUps[i].sprite.move(sf::Vector2f(trafficSpeed, 0.f));
        if (game.powerUps[i].sprite.getPosition().x < -20.f) {
            game.powerUps.erase(game.powerUps.begin() + i);
            i--;
        }
    }

    //collect powerups when car intersects with it
    for (int i = 0; i < static_cast<int>(game.powerUps.size()); i++)
    {
        if (game.player.getGlobalBounds().intersects(game.powerUps[i].sprite.getGlobalBounds()))
        {
            if (game.powerUps[i].type == 0)
            {
                game.shieldActive = true;
            }
            else
            {
                game.slowTrafficTimer = 600; // About 10 seconds.
            }
            game.powerUps.erase(game.powerUps.begin() + i);
            i--;
        }
    }

    for (int i = 0; i < static_cast<int>(game.cars.size()); i++)
    {
        if (game.player.getGlobalBounds().intersects(game.cars[i].getGlobalBounds()))
        {
            if (game.shieldActive)
            {
                game.shieldActive = false;
                game.cars.erase(game.cars.begin() + i);
            }
            else
            {
                game.gameOver = true;
                if (game.score > game.highScore) {
                    game.highScore = game.score;
                    std::ofstream scoreFile("highscore.txt");

                    if (scoreFile.is_open())
                        scoreFile << game.highScore;
                }
            }
            break;
        }

        // Preserve the existing check for a car passing the player.
        if (game.cars[i].getPosition().x + game.cars[i].getGlobalBounds().width < game.player.getPosition().x + game.player.getGlobalBounds().width)
        {
            game.touch = true;
        }
    }

    if (game.speed > -30.f)
    {
        game.speed -= 0.005f;
    }
}

void drawTrafficAndPlayer(GameData& game, sf::RenderWindow& window)
{
    for (std::size_t i = 0; i < game.cars.size(); i++)
    {
        window.draw(game.cars[i]);
    }

    for (std::size_t i = 0; i < game.powerUps.size(); i++)
    {
        window.draw(game.powerUps[i].sprite);
    }

    window.draw(game.player);
}