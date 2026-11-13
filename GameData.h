#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <SFML/Audio.hpp>
struct PowerUp {
    sf::Sprite sprite;
    int type = 0; // 0 = shield, 1 = slow traffic
};
struct GameData {
    sf::Texture carTex[2];
    sf::Texture powerUpTextures[2];

    sf::Sprite car;
    int carSpawnTimer = 15;
    int spawnDelay = 40;
    std::vector<sf::Sprite> cars;

    //updated
    sf::Texture menutex;
    sf::Sprite menuimg;

        //update 2
    sf::Texture Gameovtex;
    sf::Sprite Gameovimg;

    sf::Texture Roadtex;
    sf::Sprite Road;
    sf::Sprite Road2;
    sf::Texture playerTex;
    sf::Sprite player;

    bool gameStarted = false;
    sf::Font menuFont;
    int score = 0;
    int highScore = 0;
    sf::Text Score;
    sf::Text Pausetex;
    sf::Text menuText;
    sf::Text GameOver;

    bool Pause = false;
    bool touch = false;
    bool gameOver = false;
    float speed = -7.f;
    float spawnYPositions[3] = { 170.f, 330.f, 490.f };

    std::vector<PowerUp> powerUps;
    int powerUpSpawnTimer = 0;
    int powerUpSpawnDelay = 600;
    bool shieldActive = false;
    int slowTrafficTimer = 0;

    sf::Music backgroundMusic;
};
