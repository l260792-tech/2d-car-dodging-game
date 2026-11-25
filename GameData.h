#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <SFML/Audio.hpp>

// A collectible circle that moves across the road.
// STRUCT basically stores different variables 
struct PowerUp {
    sf::Sprite sprite;
    int type = 0; // 0 = shield, 1 = slow traffic
};
struct Coin {
    sf::Sprite sprite;
};
// Shared data from the original main() function. The modules receive this by
// reference, so the game logic and its existing variables stay together.
struct GameData {
    sf::Texture instex;
    sf::Sprite instsc;
    sf::Texture carTex[4];
    sf::Texture powerUpTextures[2];
    sf::Texture Roadtex[3];
    sf::Texture Playertex[3];

    sf::Music click;
    sf::Music crash;

    sf::RectangleShape mbutton1;
    sf::RectangleShape mbutton2;
    sf::RectangleShape mbutton3;

    sf::RectangleShape pbutton1;
    sf::RectangleShape pbutton2;
    sf::RectangleShape pbutton3;

    sf::RectangleShape hitbox;
    int nearmisstim = 0;
    //8 pm
    sf::Sprite button;
    sf::Texture buttontex;
    sf::Texture button2tex;
    sf::Texture button3tex;
    sf::Sprite button2;
    sf::Sprite button3;
    sf::Texture carselectex;
    sf::Sprite carselect;

    sf::Text neardisp;
    int disptim = 0;
    sf::Sprite cardp1;
    sf::Sprite cardp2;
    sf::Sprite cardp3;

    sf::Texture pausetex;
    sf::Sprite pauseimg;

    sf::Texture cardtex1;
    sf::Texture cardtex2;
    sf::Texture cardtex3;

    sf::Texture selectex;
    sf::Sprite selectimg;

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
   
    sf::Sprite Road;
    sf::Sprite Road2;
    sf::Sprite player;

    bool gameStarted = false;
    sf::Font menuFont;
    int score = 0;
    int highScore = 0;
    sf::Text Score;
    sf::Text Pausetex;
    sf::Text menuText;
    sf::Text GameOver;

    bool playerselect = false;
    bool mapselect = false;
    bool Pause = false;

    bool gameOver = false; 
    float speed = -7.f;
    float spawnPositions[3][2] = {
        {1280.f,160.f},
        {1280.f,320.f},
        {1280.f,490.f}
    };

    std::vector<PowerUp> powerUps;
    int powerUpSpawnTimer = 0;
    int powerUpSpawnDelay = 900;
    bool shieldActive = false;
    int slowTrafficTimer = 0;
    sf::Texture coinTex;
    std::vector<Coin> coins;
    int coinSpawnTimer = 0;
    int coinSpawnDelay = 120;   // spawning rate of coins
    int coinCount = 0;
    sf::Text coinText;
    sf::Music coinSound;

    sf::Music backgroundMusic;
    sf::Music menumusic;

    //boost update
    sf::Music boostm;
    sf::Text boostxt;
    sf::RectangleShape boostbar;
    sf::RectangleShape boostbar2;
    int boosttimer = 0;
    int boostdelay = 0;
    bool isboost = false;
    bool isboostdelay = false;
    
};
