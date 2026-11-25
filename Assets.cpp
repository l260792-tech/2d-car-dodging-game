#include <fstream>
#include "Assets.h"
using namespace sf;

bool loadAssets(GameData& game)
{
    
    game.menutex.loadFromFile("assets/menuu.jpeg");
    game.menuimg.setTexture(game.menutex);
    game.menuimg.setScale(1280.f / game.menutex.getSize().x, 720.f / game.menutex.getSize().y);

    game.selectex.loadFromFile("assets/select.jpeg");
    game.selectimg.setTexture(game.selectex);
    game.selectimg.setScale(1280.f / game.selectex.getSize().x, 720.f / game.selectex.getSize().y);

    game.carTex[0].loadFromFile("assets/enemy.png");
    game.carTex[1].loadFromFile("assets/enemy2.png");
    game.car.setScale(Vector2f(0.235f, 0.235f));

    game.boostbar.setFillColor(Color::Red);
    game.boostbar.setPosition(540.f, 610.f);

    if (game.menumusic.openFromFile("assets/sonic.wav"))
    {
        game.menumusic.setLoop(true);
        game.menumusic.setVolume(30.f);
        game.menumusic.play();
    }
    game.boostxt.setFillColor(Color::Red);
    game.boostxt.setOutlineColor(Color::Black);
    game.boostxt.setOutlineThickness(2.f);
    game.boostxt.setFont(game.menuFont);
    game.boostxt.setCharacterSize(16);
    game.boostxt.setPosition(450.f, 615.f);
    game.boostxt.setString("Boost");

    game.neardisp.setFillColor(Color::Magenta);
    game.neardisp.setOutlineColor(Color::Black);
    game.neardisp.setOutlineThickness(2);
    game.neardisp.setCharacterSize(16);
    game.neardisp.setPosition(Vector2f(1000.f, 40.f));
    game.neardisp.setFont(game.menuFont);
  
    game.Roadtex[0].loadFromFile("assets/desert3.png");
    game.Roadtex[1].loadFromFile("assets/road.png");
    game.Roadtex[2].loadFromFile("assets/coastal.png");
 
    game.hitbox.setSize(Vector2f(200.f, 140.f));

    game.buttontex.loadFromFile("assets/easy.png");
    game.button.setTexture(game.buttontex);
    game.button.setScale(.174f,.16f);
    game.button.setPosition(475.f, 458.f);

    game.button2tex.loadFromFile("assets/medium.png");
    game.button2.setTexture(game.button2tex);
    game.button2.setScale(.172f, .16f);
    game.button2.setPosition(475.f, 523.f);

    game.button3tex.loadFromFile("assets/hard.png");
    game.button3.setTexture(game.button3tex);
    game.button3.setScale(.167f, .16f);
    game.button3.setPosition(475.f, 584.f);

    game.cardtex1.loadFromFile("assets/redrunner.png");
    game.cardtex2.loadFromFile("assets/bluecruise.png");
    game.cardtex3.loadFromFile("assets/redracer.png");

    game.cardp1.setTexture(game.cardtex1);
    game.cardp2.setTexture(game.cardtex2);
    game.cardp3.setTexture(game.cardtex3);
    game.cardp1.setScale(0.6f, .6f);
    game.cardp1.setPosition(168.f, 342.f);
    game.cardp2.setScale(.6f, .6f);
    game.cardp2.setPosition(510.f, 350.f);
    game.cardp3.setScale(.6f, .6f);
    game.cardp3.setPosition(845.f, 357.f);

    game.pausetex.loadFromFile("assets/pause.jpeg");
    game.pauseimg.setTexture(game.pausetex);
    game.pauseimg.setScale(1280.f / game.pausetex.getSize().x, 720.f / game.pausetex.getSize().y);

    game.Gameovtex.loadFromFile("assets/gameover.jpeg");
    game.Gameovimg.setTexture(game.Gameovtex);
    game.Gameovimg.setScale(1280.f / game.Gameovtex.getSize().x, 720.f / game.Gameovtex.getSize().y);

    game.carselectex.loadFromFile("assets/carselect.jpeg");
    game.carselect.setTexture(game.carselectex);
    game.carselect.setScale(1280.f / game.carselectex.getSize().x, 720.f / game.carselectex.getSize().y);
 

    game.Playertex[2].loadFromFile("assets/player4.png");
    game.Playertex[1].loadFromFile("assets/player3.png");
    game.Playertex[0].loadFromFile("assets/car.png");

    if (!game.menuFont.loadFromFile("assets/PressStart2P-Regular.ttf"))
    {
        return false;
    }

    game.click.openFromFile("assets/click.wav");
    game.crash.openFromFile("assets/crash.wav");

    game.mbutton1.setSize(Vector2f(395.f, 260.f));
    game.mbutton1.setPosition(34.f, 260.f);
    game.mbutton2.setSize(Vector2f(395.f, 260.f));
    game.mbutton2.setPosition(447.f, 260.f);
    game.mbutton3.setSize(Vector2f(395.f, 260.f));
    game.mbutton3.setPosition(851.f, 260.f);

    game.pbutton1.setSize(Vector2f(395.f, 260.f));
    game.pbutton1.setPosition(34.f, 260.f);
    game.pbutton2.setSize(Vector2f(395.f, 260.f));
    game.pbutton2.setPosition(447.f, 260.f);
    game.pbutton3.setSize(Vector2f(395.f, 260.f));
    game.pbutton3.setPosition(851.f, 260.f);


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
    
    if (!game.coinTex.loadFromFile("assets/coin.png"))
    {
        return false;
    }
    game.coinSound.openFromFile("assets/coin_collect.wav");   
    game.coinSound.setVolume(60.f);

    game.coinText.setFont(game.menuFont);
    game.coinText.setFillColor(Color::Yellow);
    game.coinText.setOutlineColor(Color::Black);
    game.coinText.setOutlineThickness(2.f);
    game.coinText.setCharacterSize(16);
    game.coinText.setPosition(10.f, 40.f);   // displaying it under the "score"

    std::ifstream scoreFile("highscore.txt");
    if (scoreFile.is_open())
    {
        scoreFile >> game.highScore;
    }
    return true;
}
