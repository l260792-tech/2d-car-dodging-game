#include <fstream>
#include "Assets.h"
using namespace sf;

bool loadAssets(GameData& game)
{
    //update
    game.menutex.loadFromFile("assets/menuu.jpeg");
    game.menuimg.setTexture(game.menutex);
    game.menuimg.setScale(1280.f / game.menutex.getSize().x, 720.f / game.menutex.getSize().y);

    game.selectex.loadFromFile("assets/select.jpeg");
    game.selectimg.setTexture(game.selectex);
    game.selectimg.setScale(1280.f / game.selectex.getSize().x, 720.f / game.selectex.getSize().y);

    game.carTex[0].loadFromFile("assets/enemy.png");
    game.carTex[1].loadFromFile("assets/enemy2.png");
    game.car.setScale(Vector2f(0.235f, 0.235f));
    
    //update3
    game.Roadtex[0].loadFromFile("assets/new.png");
    game.Roadtex[1].loadFromFile("assets/road.jpeg");
 

    //update2 
    game.Gameovtex.loadFromFile("assets/gameover.jpeg");
    game.Gameovimg.setTexture(game.Gameovtex);
    game.Gameovimg.setScale(1280.f / game.Gameovtex.getSize().x, 720.f / game.Gameovtex.getSize().y);

  

    game.playerTex.loadFromFile("assets/car.png");
    game.player.setTexture(game.playerTex);
    game.player.setScale(0.2f, 0.2f);
    game.player.setPosition(Vector2f(0.f, 330.f));

    if (!game.menuFont.loadFromFile("assets/PressStart2P-Regular.ttf"))
    {
        return false;
    }

    game.Score.setFont(game.menuFont);
    game.Score.setFillColor(Color::Green);
    game.Score.setCharacterSize(16);
    game.Score.setPosition(10.f, 10.f);

    game.Pausetex.setFont(game.menuFont);
    game.Pausetex.setCharacterSize(33);
    game.Pausetex.setPosition(640.f, 360.f);
    game.Pausetex.setFillColor(Color::Cyan);
    game.Pausetex.setString("Pause");

    game.menuText.setFont(game.menuFont);
    game.menuText.setCharacterSize(36);
    game.menuText.setFillColor(Color::White);
    game.menuText.setString("CAR DODGING GAME \n \n 1 - Easy \n 2 - Medium \n 3 - Hard");
    game.menuText.setPosition(400.f, 200.f);

    game.GameOver.setFont(game.menuFont);
    game.GameOver.setFillColor(Color::Red);
    game.GameOver.setString("GAME OVER \n Esc to Return to Menu");
    game.GameOver.setPosition(350.f, 300.f);
    if (!game.powerUpTextures[0].loadFromFile("assets/powerup-shield.png"))
    {
        return false;
    }
    if (!game.powerUpTextures[1].loadFromFile("assets/powerup-slow.png"))
    {
        return false;
    }
    if (!game.powerUpTextures[0].loadFromFile("assets/powerup-shield.png"))
    {
        return false;
    }
    if (!game.powerUpTextures[1].loadFromFile("assets/powerup-slow.png"))
    {
        return false;
    }
    if (game.backgroundMusic.openFromFile("assets/soft-arcade-racing-loop.wav"))
    {
        game.backgroundMusic.setLoop(true);
        game.backgroundMusic.setVolume(30.f);
        game.backgroundMusic.play();
    }
    std::ifstream scoreFile("highscore.txt");
    if (scoreFile.is_open())
    {
        scoreFile >> game.highScore;
    }
    return true;
}
