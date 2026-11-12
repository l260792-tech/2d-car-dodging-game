#include "Menu.h"
#include <string>

void handleMenuEvent(GameData& game, const sf::Event& event)
{
    if (!game.gameStarted && event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Num1) {
            game.spawnDelay = 70; game.gameStarted = true; game.speed = -7.f;
        }
        else if (event.key.code == sf::Keyboard::Num2) {
            game.spawnDelay = 55; game.gameStarted = true; game.speed = -8.5f;
        }
        else if (event.key.code == sf::Keyboard::Num3) {
            game.spawnDelay = 42; game.gameStarted = true; game.speed = -11.f;
        }
    }

    if (game.gameOver && event.type == sf::Event::KeyPressed &&
        event.key.code == sf::Keyboard::Escape) {
        game.gameOver = false;
        game.carSpawnTimer = 15;
        game.score = 0;
        game.cars.clear();

        game.powerUps.clear();
        game.powerUpSpawnTimer = 0;
        game.shieldActive = false;
        game.slowTrafficTimer = 0;


        game.gameStarted = false;
    }
}

void drawMenuAndHud(GameData& game, sf::RenderWindow& window)
{
   if (!game.gameStarted) 
    {
        //window.draw(game.menuText);
        window.draw(game.menuimg);
    }
    else if (game.gameOver) {
        //window.draw(game.GameOver);
        //update
        window.draw(game.Gameovimg);
        game.player.setPosition(sf::Vector2f(0.f, 330.f));
    }
    game.Score.setString(
        "Score: " + std::to_string(game.score) +
        "   High score: " + std::to_string(game.highScore)
    );
    window.draw(game.Score);

    if (game.gameStarted && !game.gameOver) {
        // Show the shield icon while it is ready.
        if (game.shieldActive) {
            sf::Sprite shieldIcon(game.powerUpTextures[0]);
            shieldIcon.setScale(0.25f, 0.25f); // 128px image displays at 32px
            shieldIcon.setPosition(10.f, 55.f);
            window.draw(shieldIcon);

            sf::Text shieldLabel;
            shieldLabel.setFont(game.menuFont);
            shieldLabel.setCharacterSize(12);
            shieldLabel.setFillColor(sf::Color::Cyan);
            shieldLabel.setString("SHIELD READY");
            shieldLabel.setPosition(50.f, 63.f);
            window.draw(shieldLabel);
        }

        // Show the slow-powerup icon and a bar that shrinks as time runs out.
        if (game.slowTrafficTimer > 0) {
            sf::Sprite slowIcon(game.powerUpTextures[1]);
            slowIcon.setScale(0.25f, 0.25f);
            slowIcon.setPosition(10.f, 620.f);
            window.draw(slowIcon);

            const float fullBarWidth = 220.f;
            const float remainingRatio =
                static_cast<float>(game.slowTrafficTimer) / 600.f;

            sf::RectangleShape barBackground(sf::Vector2f(fullBarWidth, 16.f));
            barBackground.setPosition(50.f, 620.f);
            barBackground.setFillColor(sf::Color(60, 60, 60));
            window.draw(barBackground);

            sf::RectangleShape barFill(
                sf::Vector2f(fullBarWidth * remainingRatio, 16.f)
            );
            barFill.setPosition(50.f, 620.f);
            barFill.setFillColor(sf::Color::Yellow);
            window.draw(barFill);

            int secondsLeft = (game.slowTrafficTimer + 59) / 60;

            sf::Text timerLabel;
            timerLabel.setFont(game.menuFont);
            timerLabel.setCharacterSize(12);
            timerLabel.setFillColor(sf::Color::White);
            timerLabel.setString(std::to_string(secondsLeft) + "s");
            timerLabel.setPosition(280.f, 625.f);
            window.draw(timerLabel);
        }
    }
}





