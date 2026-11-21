#include "Menu.h"
#include <string>
// menu, game over
void handleMenuEvent(GameData& game, const sf::Event& event) {
    if (!game.gameStarted && !game.mapselect && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
       /* if (event.key.code == sf::Keyboard::Num1) {
            game.spawnDelay = 70; 
            game.speed = -7.f;
            game.mapselect = true;
        }
        else if (event.key.code == sf::Keyboard::Num2) {
            game.spawnDelay = 55; 
            game.speed = -8.5f;
            game.mapselect = true;
        }
        else if (event.key.code == sf::Keyboard::Num3) {
            game.spawnDelay = 42;
            game.speed = -11.f;
            game.mapselect = true;
        }*/
        
       if (game.button.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
       {
           game.spawnDelay = 70;
           game.speed = -7.f;
           game.mapselect = true;
       }
       if (game.button2.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
       {
           game.spawnDelay = 55;
           game.speed = -8.5f;
           game.mapselect = true;
       }
       if (game.button3.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
       {
           game.spawnDelay = 42;
           game.speed = -11.f;
           game.mapselect = true;
       }
        
    }
    else if (!game.gameStarted && !game.playerselect && game.mapselect && event.type == sf::Event::KeyPressed)
    {

        if (event.key.code == sf::Keyboard::Num2) 
        {
            game.Road.setTexture(game.Roadtex[0],true);
            game.Road2.setTexture(game.Roadtex[0],true);
            game.Road.setScale(1280.f / game.Roadtex[0].getSize().x, 720.f / game.Roadtex[0].getSize().y);
            game.Road2.setScale(1280.f / game.Roadtex[0].getSize().x, 720.f / game.Roadtex[0].getSize().y);
            game.Road.setPosition(0.f, 0.f);
            game.Road2.setPosition(1280.f, 0.f); // a second copy to loop
            game.mapselect = false;
            game.playerselect = true;
            game.menumusic.stop();
            if (game.backgroundMusic.openFromFile("assets/TM1.wav"))
            {
                game.backgroundMusic.setLoop(true);
                game.backgroundMusic.setVolume(30.f);
                game.backgroundMusic.play();
            }
        }
        else if (event.key.code == sf::Keyboard::Num1) 
        {
            game.Road.setTexture(game.Roadtex[1],true);
            game.Road2.setTexture(game.Roadtex[1],true); // true resets rectangle size for scaling
            game.Road.setScale(1280.f / game.Roadtex[1].getSize().x, 720.f / game.Roadtex[1].getSize().y);
            game.Road2.setScale(1280.f / game.Roadtex[1].getSize().x, 720.f / game.Roadtex[1].getSize().y);
            game.Road.setPosition(0.f, 0.f);
            game.Road2.setPosition(1280.f, 0.f); // a second copy to loop
            game.mapselect = false;
            game.playerselect = true;
            game.menumusic.stop();
            if (game.backgroundMusic.openFromFile("assets/jin.wav"))
            {
                game.backgroundMusic.setLoop(true);
                game.backgroundMusic.setVolume(30.f);
                game.backgroundMusic.play();
            }
        }
        else if (event.key.code == sf::Keyboard::Num3)
        {
            game.Road.setTexture(game.Roadtex[2], true);
            game.Road2.setTexture(game.Roadtex[2], true); // true resets rectangle size for scaling
            game.Road.setScale(1280.f / game.Roadtex[2].getSize().x, 720.f / game.Roadtex[2].getSize().y);
            game.Road2.setScale(1280.f / game.Roadtex[2].getSize().x, 720.f / game.Roadtex[2].getSize().y);
            game.Road.setPosition(0.f, 0.f);
            game.Road2.setPosition(1280.f, 0.f); // a second copy to loop
            game.mapselect = false;
            game.playerselect = true;
            game.menumusic.stop();
            if (game.backgroundMusic.openFromFile("assets/coastalmusic.wav"))
            {
                game.backgroundMusic.setLoop(true);
                game.backgroundMusic.setVolume(30.f);
                game.backgroundMusic.play();
            }
        }
    }
    else if (!game.gameStarted && !game.mapselect && game.playerselect && event.type == sf::Event::KeyPressed) //11pm
    { 
        if (event.key.code == sf::Keyboard::Num1)
        {
            game.player.setTexture(game.Playertex[0], true);
            game.player.setScale(0.23f,0.23f);
            game.player.setPosition(20.f, 320.f);
            game.playerselect = false;
            game.gameStarted = true;
        }
        else if (event.key.code == sf::Keyboard::Num2)
        {
            game.player.setTexture(game.Playertex[1], true);
            game.player.setScale(0.47f, 0.47f);
            game.player.setPosition(20.f, 320.f);
            game.playerselect = false;
            game.gameStarted = true;
        }
        else if (event.key.code == sf::Keyboard::Num3)
        {
            game.player.setTexture(game.Playertex[2], true);
            game.player.setScale(0.23f, 0.23f);
            game.player.setPosition(20.f, 310.f);
            game.playerselect = false;
            game.gameStarted = true;
        }
    }

    //if (game.gameOver && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) 
    //{
    //    game.backgroundMusic.stop();
    //    game.gameOver = false;
    //    game.carSpawnTimer = 15;
    //    game.disptim = 0;
    //    game.score = 0;
    //    game.cars.clear();
    //    game.nearmisstim = 0;
    //    game.menumusic.stop();
    //   

    //    game.powerUps.clear();
    //    game.powerUpSpawnTimer = 0;
    //    game.shieldActive = false;
    //    game.slowTrafficTimer = 0;
    //    game.gameStarted = false;
    //    if (game.menumusic.getStatus() != sf::Music::Playing) //new
    //    {
    //        game.menumusic.play();
    //    }
    //}
    if (game.gameOver)
    {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            game.gameOver = false;
            game.carSpawnTimer = 15;
            game.disptim = 0;
            game.score = 0;
            game.cars.clear();
            game.nearmisstim = 0;
            game.menumusic.stop();

            game.powerUps.clear();
            game.powerUpSpawnTimer = 0;
            game.shieldActive = false;
            game.slowTrafficTimer = 0;
            game.gameStarted = false;
            if (game.menumusic.getStatus() != sf::Music::Playing) //new
            {
                game.menumusic.play();
            }
        }
    }
}

void drawMenuAndHud(GameData& game, sf::RenderWindow& window) {
    if (!game.gameStarted && !game.mapselect && !game.playerselect) 
    {
        //window.draw(game.menuText);
        window.draw(game.menuimg);
        window.draw(game.button);
        window.draw(game.button2);
        window.draw(game.button3);
    }
    else if (game.mapselect && !game.gameStarted && !game.playerselect)
    {
        window.draw(game.selectimg);
    }
    else if (game.playerselect && !game.gameStarted && !game.mapselect) //up
    {
        window.draw(game.carselect);
        window.draw(game.cardp1);
        window.draw(game.cardp2);
        window.draw(game.cardp3);
    }
    else if (game.gameOver) {
        //window.draw(game.GameOver);
        //UPDATE 2 
        window.draw(game.Gameovimg);
        game.player.setPosition(sf::Vector2f(0.f, 320.f));
    }
    game.Score.setString("Score: " + std::to_string(game.score) + "   High score: " + std::to_string(game.highScore));
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

            sf::RectangleShape barFill(sf::Vector2f(fullBarWidth * remainingRatio, 16.f));
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
