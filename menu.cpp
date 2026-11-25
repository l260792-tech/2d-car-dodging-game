#include "Menu.h"
#include <string>

void handleMenuEvent(GameData& game, const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P && game.gameStarted && !game.gameOver)
    {
        game.Pause = !game.Pause;
    }
    if (game.Pause && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    {
        game.click.setLoop(false);
        game.click.setVolume(40.f);
        game.click.play();
        game.Pause = false;
        game.gameStarted = false;
        game.playerselect = false;
        game.mapselect = false;
        game.carSpawnTimer = 15;
        game.disptim = 0;
        game.score = 0;
        game.cars.clear();
        game.nearmisstim = 0;
        game.menumusic.stop();
        game.backgroundMusic.stop();
        game.powerUps.clear();
        game.powerUpSpawnTimer = 0;
        game.shieldActive = false;
        game.slowTrafficTimer = 0;
        game.boosttimer = 0;
        game.boostdelay = 0;
        game.isboost = false;
        game.isboostdelay = false;
        if (game.menumusic.getStatus() != sf::Music::Playing)
        {
            game.menumusic.play();
        }

    }
    if (!game.gameStarted && !game.mapselect && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        
       if (game.button.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
       {
           game.click.setLoop(false);
           game.click.setVolume(40.f);
           game.click.play();
           game.spawnDelay = 70;
           game.speed = -7.f;
           game.mapselect = true;
       }
       if (game.button2.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
       {
           game.click.setLoop(false);
           game.click.setVolume(40.f);
           game.click.play();
           game.spawnDelay = 55;
           game.speed = -8.5f;
           game.mapselect = true;
       }
       if (game.button3.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
       {
           game.click.setLoop(false);
           game.click.setVolume(40.f);
           game.click.play();
           game.spawnDelay = 42;
           game.speed = -11.f;
           game.mapselect = true;
       }
        
    }
    if (!game.gameStarted && !game.mapselect && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::I)
    {
        game.click.setLoop(false);
        game.click.setVolume(40.f);
        game.click.play();
        game.isinstruc = !game.isinstruc;
    }
    
    else if (!game.gameStarted && !game.playerselect && game.mapselect && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        if (game.mbutton2.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
        {
            game.click.setLoop(false);
            game.click.setVolume(40.f);
            game.click.play();
            game.Road.setTexture(game.Roadtex[0], true);
            game.Road2.setTexture(game.Roadtex[0], true);
            game.Road.setScale(1280.f / game.Roadtex[0].getSize().x, 720.f / game.Roadtex[0].getSize().y);
            game.Road2.setScale(1280.f / game.Roadtex[0].getSize().x, 720.f / game.Roadtex[0].getSize().y);
            game.Road.setPosition(0.f, 0.f);
            game.Road2.setPosition(1280.f, 0.f); 
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
        else if (game.mbutton1.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
        {
            game.click.setLoop(false);
            game.click.setVolume(40.f);
            game.click.play();
            game.Road.setTexture(game.Roadtex[1], true);
            game.Road2.setTexture(game.Roadtex[1], true);
            game.Road.setScale(1280.f / game.Roadtex[1].getSize().x, 720.f / game.Roadtex[1].getSize().y);
            game.Road2.setScale(1280.f / game.Roadtex[1].getSize().x, 720.f / game.Roadtex[1].getSize().y);
            game.Road.setPosition(0.f, 0.f);
            game.Road2.setPosition(1280.f, 0.f);
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
        else if (game.mbutton3.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
        {
            game.click.setLoop(false);
            game.click.setVolume(40.f);
            game.click.play();
            game.Road.setTexture(game.Roadtex[2], true);
            game.Road2.setTexture(game.Roadtex[2], true); 
            game.Road.setScale(1280.f / game.Roadtex[2].getSize().x, 720.f / game.Roadtex[2].getSize().y);
            game.Road2.setScale(1280.f / game.Roadtex[2].getSize().x, 720.f / game.Roadtex[2].getSize().y);
            game.Road.setPosition(0.f, 0.f);
            game.Road2.setPosition(1280.f, 0.f);
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
   
   

    else if (!game.gameStarted && !game.mapselect && game.playerselect && event.type == sf::Event::KeyPressed) 
    {
        if (event.key.code == sf::Keyboard::Num1)
        {
            game.click.setLoop(false);
            game.click.setVolume(40.f);
            game.click.play();
            game.player.setTexture(game.Playertex[0], true);
            game.player.setScale(0.23f, 0.23f);
            game.player.setPosition(20.f, 320.f);
            game.playerselect = false;
            game.gameStarted = true;
        }
        else if (event.key.code == sf::Keyboard::Num2)
        {
            game.click.setLoop(false);
            game.click.setVolume(40.f);
            game.click.play();
            game.player.setTexture(game.Playertex[1], true);
            game.player.setScale(0.47f, 0.47f);
            game.player.setPosition(20.f, 320.f);
            game.playerselect = false;
            game.gameStarted = true;
        }
        else if (event.key.code == sf::Keyboard::Num3)
        {
            game.click.setLoop(false);
            game.click.setVolume(40.f);
            game.click.play();
            game.player.setTexture(game.Playertex[2], true);
            game.player.setScale(0.23f, 0.23f);
            game.player.setPosition(20.f, 310.f);
            game.playerselect = false;
            game.gameStarted = true;
        }
    }

    if (game.gameOver)
    {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            game.click.setLoop(false);
            game.click.setVolume(40.f);
            game.click.play();
            game.gameOver = false;
            game.carSpawnTimer = 15;
            game.disptim = 0;
            game.score = 0;
            game.cars.clear();
            game.nearmisstim = 0;
            game.menumusic.stop();
            game.coins.clear();
            game.coinCount = 0;
            game.coinSpawnTimer = 0;
            game.powerUps.clear();
            game.powerUpSpawnTimer = 0; 
            game.shieldActive = false;
            game.slowTrafficTimer = 0;
            game.gameStarted = false;
            game.boosttimer = 0;
            game.boostdelay = 0;
            game.isboost = false;
            game.isboostdelay = false;
            if (game.menumusic.getStatus() != sf::Music::Playing) 
            {
                game.menumusic.play();
            }
        }
    }
}

void drawMenuAndHud(GameData& game, sf::RenderWindow& window) {
    if (!game.gameStarted && !game.mapselect && !game.playerselect) 
    {
        window.draw(game.menuimg);
        window.draw(game.button);
        window.draw(game.button2);
        window.draw(game.button3);
        if (game.isinstruc)
        {
             window.draw(game.instsc);
        }
    }
    else if (game.mapselect && !game.gameStarted && !game.playerselect)
    {
        window.draw(game.selectimg);

    }
    else if (game.playerselect && !game.gameStarted && !game.mapselect) 
    {
        window.draw(game.carselect);
        window.draw(game.cardp1);
        window.draw(game.cardp2);
        window.draw(game.cardp3);
      
    }
    else if (game.gameOver) {
        
        window.draw(game.Gameovimg);
        game.player.setPosition(sf::Vector2f(0.f, 320.f));
    }
    game.Score.setString("Score: " + std::to_string(game.score) + "   High score: " + std::to_string(game.highScore));
    window.draw(game.Score);

    if (game.gameStarted && !game.gameOver) 
    {
        window.draw(game.boostbar);
        window.draw(game.boostxt);
       
        if (game.shieldActive) {
            sf::Sprite shieldIcon(game.powerUpTextures[0]);
            shieldIcon.setScale(0.25f, 0.25f); 
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
        if (game.Pause)
        {
            window.draw(game.pauseimg);
        }
    }
}
