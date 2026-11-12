#include <fstream>
#include "Assets.h"
using namespace sf; 

bool loadAssets(GameData& game)
{
    game.menutex.loadFromFile("C:/c++/textures/menuu.jpeg");
    game.menuimg.setTexture(game.menutex);
    game.menuimg.setScale(1280.f / game.menutex.getSize().x, 720.f / game.menutex.getSize().y);
   
    game.carTex[0].loadFromFile("C:/c++/textures/enemy.png");
    game.carTex[1].loadFromFile("C:/c++/textures/enemy2.png");
    game.car.setScale(Vector2f(0.235f,0.235f));

    game.Roadtex.loadFromFile("C:/c++/textures/road.jpeg");
    game.Road.setTexture(game.Roadtex);
    game.Road.setScale(1280.f/game.Roadtex.getSize().x,720.f/game.Roadtex.getSize().y);

        //update2 
    game.Gameovtex.loadFromFile("C:/c++/textures/gameover.jpeg");
    game.Gameovimg.setTexture(game.Gameovtex);
    game.Gameovimg.setScale(1280.f / game.Gameovtex.getSize().x, 720.f / game.Gameovtex.getSize().y);

     game.Road2.setTexture(game.Roadtex);
     game.Road2.setScale(1280.f / game.Roadtex.getSize().x, 720.f / game.Roadtex.getSize().y);
     game.Road2.setPosition(1280.f, 0.f); // a second copy to loop

    game.playerTex.loadFromFile("C:/c++/textures/car.png");
    game.player.setTexture(game.playerTex);
    game.player.setScale(0.2f,0.2f);
    game.player.setPosition(Vector2f(0.f,330.f));

      if(!game.menuFont.loadFromFile("C:/c++/textures/PressStart2P-Regular.ttf"))
    {
        return false;
    }
    
    game.Score.setFont(game.menuFont);
    game.Score.setFillColor(Color::Green);
    game.Score.setCharacterSize(16);
    game.Score.setPosition(10.f,10.f);

    game.Pausetex.setFont(game.menuFont);
    game.Pausetex.setCharacterSize(33);
    game.Pausetex.setPosition(640.f, 360.f);
    game.Pausetex.setFillColor(Color::Cyan);
    game.Pausetex.setString("Pause");

    game.menuText.setFont(game.menuFont);
    game.menuText.setCharacterSize(36);
    game.menuText.setFillColor(Color::White);
    game.menuText.setString("CAR DODGING GAME \n \n 1 - Easy \n 2 - Medium \n 3 - Hard");
    game.menuText.setPosition(400.f,200.f);

    game.GameOver.setFont(game.menuFont);
    game.GameOver.setFillColor(Color::Red);
    game.GameOver.setString("GAME OVER \n Esc to Return to Menu");
    game.GameOver.setPosition(350.f,300.f);
    if(!game.powerUpTextures[0].loadFromFile("C:/c++/textures/powerup-shield.png"))
    {
        return false;
    }
    if(!game.powerUpTextures[1].loadFromFile("C:/c++/textures/powerup-slow.png"))
    {
        return false;
    }
    if(!game.powerUpTextures[0].loadFromFile("C:/c++/textures/powerup-shield.png"))
    {
        return false;
    }
    if(!game.powerUpTextures[1].loadFromFile("C:/c++/textures/powerup-slow.png"))
    {
        return false;
    }
    if(game.backgroundMusic.openFromFile("C:/c++/textures/soft-arcade-racing-loop.wav"))
    {
        game.backgroundMusic.setLoop(true);
        game.backgroundMusic.setVolume(30.f);
        game.backgroundMusic.play();
    }
    std::ifstream scoreFile("highscore.txt");
    if(scoreFile.is_open())
    {
        scoreFile>>game.highScore;
    }
    return true;
}
