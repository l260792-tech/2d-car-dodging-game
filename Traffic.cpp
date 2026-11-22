#include "Traffic.h"
#include <cstdlib>
#include <fstream>
//traffic logic
void updateTraffic(GameData& game, const sf::RenderWindow& window) {
    // Use half speed while the slow-traffic powerup is active.

    if (game.nearmisstim > 0) {
        game.nearmisstim--;
    }
    if (game.disptim > 0) {
        game.disptim--;
    }

    int spdelay = game.spawnDelay;
    int pupdelay = game.powerUpSpawnDelay;
    if (game.isboost)
    {
        spdelay = game.spawnDelay * 3 / 4;
        pupdelay = game.powerUpSpawnDelay * 3 / 4;
    }


    float trafficSpeed = game.speed;

    if (game.slowTrafficTimer > 0) 
    {
        trafficSpeed *= 0.5f;
        game.slowTrafficTimer--;
    }
   
    for (int i = 0; i < static_cast<int>(game.cars.size()); i++) 
    {
        game.cars[i].move(sf::Vector2f(trafficSpeed, 0.f));

        if (game.cars[i].getPosition().x < 0 - game.car.getGlobalBounds().width) 
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
        game.car.setPosition(game.spawnPositions[spawnIndex][0],game.spawnPositions[spawnIndex][1]);
        game.cars.push_back(sf::Sprite(game.car));
        game.carSpawnTimer = 0;
    }

    // Count frames until the next powerup appears.
    game.powerUpSpawnTimer++;
    if (game.powerUpSpawnTimer >= game.powerUpSpawnDelay) 
    {
        PowerUp item;
        item.type = std::rand() % 2; // Randomly choose shield or slow traffic.

        // Use the PNG for this powerup type: 0 = shield, 1 = slow traffic.
        item.sprite.setTexture(game.powerUpTextures[item.type]);

        // Scale the image to fit within about 36 by 36 pixels.
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
        item.sprite.setPosition(game.spawnPositions[lane][0] + 220.f, game.spawnPositions[lane][1] + 35.f);
        game.powerUps.push_back(item);
        game.powerUpSpawnTimer = 0;
    }

    // Move powerups left and remove any that leave the screen.
    for (int i = 0; i < static_cast<int>(game.powerUps.size()); i++) {
        game.powerUps[i].sprite.move(sf::Vector2f(trafficSpeed, 0.f));
        if (game.powerUps[i].sprite.getPosition().x < -20.f) 
        {
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
            i--; //indexes shift to left 1--->0 2--->1
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
                game.crash.setLoop(false);
                game.crash.setVolume(40.f);
                game.crash.play();
                game.gameOver = true;
                game.backgroundMusic.stop();
                if (game.score > game.highScore) 
                {
                    game.highScore = game.score;
                    std::ofstream scoreFile("highscore.txt");

                    if (scoreFile.is_open())
                        scoreFile << game.highScore;
                }
            }
            break;
        }
        if (game.nearmisstim==0 && game.hitbox.getGlobalBounds().intersects(game.cars[i].getGlobalBounds()))
        {
            game.score += 3;
            game.nearmisstim = 90;
            game.disptim = 80;
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
    using namespace std;
    for (int i = 0; i < game.cars.size(); i++)
    {
        window.draw(game.cars[i]);
    }

    for (int i = 0; i < game.powerUps.size(); i++)
    {
        window.draw(game.powerUps[i].sprite);
    }
    if (game.disptim != 0)
    {
        game.neardisp.setString("NEAR MISS!!\n\n+3 POINTS!!");
    }
    else
    {
        game.neardisp.setString("");
    }
    window.draw(game.neardisp);
    window.draw(game.player);
}
