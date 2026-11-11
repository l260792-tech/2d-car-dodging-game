#include "Assets.h"
#include <fstream>
// starting part of og code
bool loadAssets(GameData& game) {
    game.carTex[0].loadFromFile("C:/c++/textures/enemy.png");
    game.carTex[1].loadFromFile("C:/c++/textures/enemy2.png");
    game.car.setScale(sf::Vector2f(0.235f, 0.235f));

    game.Roadtex.loadFromFile("C:/c++/textures/road.jpeg");
    game.Road.setTexture(game.Roadtex);
    game.Road.setScale(1280.f / game.Roadtex.getSize().x,
        720.f / game.Roadtex.getSize().y);

    game.playerTex.loadFromFile("C:/c++/textures/car.png");
    game.player.setTexture(game.playerTex);
    game.player.setScale(0.2f, 0.2f);
    game.player.setPosition(sf::Vector2f(0.f, 330.f));

    if (!game.menuFont.loadFromFile("C:/c++/textures/PressStart2P-Regular.ttf"))
        return false;

    game.Score.setFont(game.menuFont);
    game.Score.setFillColor(sf::Color::Green);
    game.Score.setCharacterSize(16);
    game.Score.setPosition(10.f, 10.f);

    game.Pausetex.setFont(game.menuFont);
    game.Pausetex.setCharacterSize(33);
    game.Pausetex.setPosition(640.f, 360.f);
    game.Pausetex.setFillColor(sf::Color::Cyan);
    game.Pausetex.setString("PAUSE");

    game.menuText.setFont(game.menuFont);
    game.menuText.setCharacterSize(36);
    game.menuText.setFillColor(sf::Color::White);
    game.menuText.setString("CAR DODGING GAME\n\n1 - Easy\n2 - Medium\n3 - Hard");
    game.menuText.setPosition(400.f, 200.f);

    game.GameOver.setFont(game.menuFont);
    game.GameOver.setFillColor(sf::Color::Red);
    game.GameOver.setString("GAME OVER \n Esc to Return to Menu ");
    game.GameOver.setPosition(350.f, 300.f);

    // Load the shield image and the slow-traffic image.
    if (!game.powerUpTextures[0].loadFromFile(
        "C:/c++/textures/powerup-shield.png")) {
        return false;
    }
    if (!game.powerUpTextures[1].loadFromFile(
        "C:/c++/textures/powerup-slow.png")) {
        return false;
    }
    if (!game.powerUpTextures[0].loadFromFile(
        "C:/c++/textures/powerup-shield.png"))
        return false;
    if (!game.powerUpTextures[1].loadFromFile(
        "C:/c++/textures/powerup-slow.png"))
        return false;

    // Start the background music and keep it looping.
    if (game.backgroundMusic.openFromFile(
        "C:/c++/textures/soft-arcade-racing-loop.wav")) {
        game.backgroundMusic.setLoop(true);
        game.backgroundMusic.setVolume(30.f); // Volume ranges from 0 to 100.
        game.backgroundMusic.play();
    }

    // Load the saved high score. It stays 0 if the file does not exist yet.
    std::ifstream scoreFile("highscore.txt");
    if (scoreFile.is_open()) {
        scoreFile >> game.highScore;
    }
    return true;
}