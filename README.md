# 2D Car Dodging Game

A 2-D car dodging game created written in C++ using SFML. Use up and down arrow keys to move your car while avoiding oncoming obstacles on the road. Use spacebar for quick boost.

## Team

| Name | Roll number | Tasks |
|---|---|---|
| Muhammad Tayyab | 26L-0765 | Main game loop, shared game data, asset loading, near-miss scoring system, boost , player movement, boost system |
| Muhammad Asim | 26L-0792 | Traffic movement and spawning, collision detection, scoring, high-score management, coin collection and power-up mechanics |
| Maryam Sajjad | 26L-0851 | Main menu events, difficulty and map selection, player car selection, pause and resume functionality, screen transitions, gameplay management|

## Features

- Three difficulty levels: Easy, Medium, and Hard
- On screen difficulty and map selection
- Press 1,2 or 3 for selecting first, second or third car
- Player car movement using up and down arrow keys and space bar for boost
- Collision detection and a single life, with game-over screen upon first collision
- Score counter and highscore recorded, passing each car increases the score counter by +1
- Catching a coin adds +5 to the score
- Enemy car speeds increase as time passes
- One-time Shield and slow-traffic power-ups
- Scrolling road and background music

## Files

| File or folder | Purpose |
|---|---|
| `main.cpp` | Generates the main game video and is the main game loop |
| `GameData.h` | Stores game info and lets other files access it |
| `Assets.h`, `Assets.cpp` | Declares assets, customizes them and makes them usable in other files |
| `Player.h`, `Player.cpp` | Manages movement of player |
| `Traffic.h`, `Traffic.cpp` | Manages traffic and powerup movement and spawning at location randomly |
| `Menu.h`, `menu.cpp` | Manages the menu, difficulty selection |
| `assets/` | Folder containing all textures, audios and font used in game |
| `highscore.txt` | txt file created in working directory which stores highscore and updates when a new score is higher than previous highscore |
| `dll/` | contains the dll files required for running SFML |

## Build requirements

- Visual Studio 2022
- SFML 2.6.1
- DLL files from `dll/`
- Assets from `assets/`

## Setup

Open `2d-car-dodging-game.sln` in Visual Studio and select **x64** with either **Debug** or **Release**. The project is configured for SFML 2.6.1 installed at `C:\SFML-2.6.1`; if SFML is installed elsewhere, update the include, library, and DLL paths in the project properties. The post-build step copies the matching SFML runtime DLLs beside the executable. The working directory is the project folder so the game can load files from `assets/`.


## Build and run

1. Select **Release** and **x64** for a standard run (Debug and x64 is also configured).
2. Build the solution, then choose **Debug > Start Without Debugging** to run the game.

## Controls

1. While in the Main Menu
- Click to choose difficulty
  
2. While in the Map Select Screen
- Click to choose the map
  
3. While in the Character Select Screen
- `1` Red Runner
- `2` Blue Cruiser
- `3` Red Racer
  
4. While in Game
- `Up` / `Down` arrows - Movement
- `Space` - Boost 
- `Esc` — Return to the menu after game over

The pause function using `P` to pause and unpause
