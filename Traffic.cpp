#include "Traffic.h"
#include <cstdlib>
#include <fstream>
#include<string>
//traffic logic
void updateTraffic(GameData& game, const sf::RenderWindow& window) 
{
  

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
    if (game.isboost) {
        trafficSpeed *= 3.f;
    }
  

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
    
    if (game.carSpawnTimer < spdelay) 
        game.carSpawnTimer++;
    if (game.carSpawnTimer >= spdelay) 
    {
        int spawnIndex = std::rand() % 3;
        int texind = std::rand() % 2;
        game.car.setTexture(game.carTex[texind]);
        game.car.setPosition(game.spawnPositions[spawnIndex][0],game.spawnPositions[spawnIndex][1]);
        game.cars.push_back(sf::Sprite(game.car));
        game.carSpawnTimer = 0;
    }

    game.powerUpSpawnTimer++;
    if (game.powerUpSpawnTimer >= pupdelay) 
    {
        PowerUp item;
        item.type = std::rand() % 2; // choose a powerup

        item.sprite.setTexture(game.powerUpTextures[item.type]);

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

    // powerups move towards left and remove which leave the screen.
    for (int i = 0; i < static_cast<int>(game.powerUps.size()); i++) {
        game.powerUps[i].sprite.move(sf::Vector2f(trafficSpeed, 0.f));
        if (game.powerUps[i].sprite.getPosition().x < -20.f) 
        {
            game.powerUps.erase(game.powerUps.begin() + i);
            i--;
        }
    }

    //collect powerups
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
    int coindelay = game.coinSpawnDelay;
    if (game.isboost)
        coindelay = game.coinSpawnDelay * 3 / 4;

    game.coinSpawnTimer++;
    if (game.coinSpawnTimer >= coindelay)
    {
        Coin c;
        c.sprite.setTexture(game.coinTex);

        sf::Vector2u sz = game.coinTex.getSize();
        if (sz.x > 0 && sz.y > 0)
        {
            float s = 40.f / static_cast<float>(sz.x > sz.y ? sz.x : sz.y);
            c.sprite.setScale(s, s);
            c.sprite.setOrigin(sz.x / 2.f, sz.y / 2.f);
        }

        int lane = std::rand() % 3;
        c.sprite.setPosition(game.spawnPositions[lane][0] + 220.f,
            game.spawnPositions[lane][1] + 35.f);

        bool blocked = false;
        for (int i = 0; i < static_cast<int>(game.cars.size()); i++)
            if (c.sprite.getGlobalBounds().intersects(game.cars[i].getGlobalBounds()))
                blocked = true;
        for (int i = 0; i < static_cast<int>(game.powerUps.size()); i++)
            if (c.sprite.getGlobalBounds().intersects(game.powerUps[i].sprite.getGlobalBounds()))
                blocked = true;

        if (!blocked)
        {
            game.coins.push_back(c);
            game.coinSpawnTimer = 0;
        }
        
    }

    for (int i = 0; i < static_cast<int>(game.coins.size()); i++)
    {
        game.coins[i].sprite.move(sf::Vector2f(trafficSpeed, 0.f));

        if (game.coins[i].sprite.getPosition().x < -20.f)
        {
            game.coins.erase(game.coins.begin() + i);
            i--;
            continue;
        }

        if (game.player.getGlobalBounds().intersects(game.coins[i].sprite.getGlobalBounds()))
        {
            game.coinCount++;
            game.score += 5;       //score increment when coin is collected   
            game.coinSound.play();
            game.coins.erase(game.coins.begin() + i);
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
            if (game.speed > -10)
                game.nearmisstim = 60;
            else if (game.speed > -20)
                game.nearmisstim = 40;
            else
                game.nearmisstim = 30;
            game.disptim = 80;
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

    for (int i = 0; i < game.coins.size(); i++)
    {
        window.draw(game.coins[i].sprite);
    }
    game.coinText.setString("Coins: " + std::to_string(game.coinCount));
    window.draw(game.coinText);

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
