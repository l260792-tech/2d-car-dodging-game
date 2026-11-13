# 2D Car Dodging Game

A 2D car-dodging game written in C++ using SFML. Choose a difficulty, avoid incoming traffic, collect power-ups, and try to beat the saved high score.

## Team

| Name | Roll number | Main responsibility |
|---|---|---|
| Muhammad Tayyab | 26L-0765 | Main game loop, shared game data, and asset loading |
| Muhammad Asim | 26L-0792 | Traffic movement and spawning, collisions, scoring, and power-ups |
| Maryam Sajjad | 26L-0851 | Menu events, difficulty selection, and on-screen interface |

## Features

- Three difficulty levels: Easy, Medium, and Hard
- Incoming traffic
- Collision detection and game-over screen
- Score and saved high score
- Traffic speed increases as the game continues
- Shield and slow-traffic power-ups
- Scrolling road and looping background music

## Project files

| File | Purpose |
|---|---|
| `GameData.h` | Shared game state, including cars, road, score, and power-ups |
| `highscore.txt` | Stores the high score after a game ends; created when the game saves a score |

## Build requirements

- A C++ compiler supported by the chosen SFML package
- SFML 2.x with Graphics, Window, System, and Audio libraries
- SFML libraries that match the compiler and system architecture
- The game textures, font, and music listed below

## Build and run

1. Install SFML and configure its include and library paths in Visual Studio or your chosen C++ environment.
2. Add the project's `.cpp` files to the build and link the SFML Graphics, Window, System, and Audio libraries.
3. Update the asset paths in `Assets.cpp` to match where the files are stored on your computer.
4. Build and run the project from the IDE.

The current source refers to assets under `C:/c++/textures/`. The required files are `menuu.jpeg`, `enemy.png`, `enemy2.png`, `road.jpeg`, `gameover.jpeg`, `car.png`, `PressStart2P-Regular.ttf`, `powerup-shield.png`, `powerup-slow.png`, and `soft-arcade-racing-loop.wav`.

## Controls

- `1` — Start on Easy
- `2` — Start on Medium
- `3` — Start on Hard
- `Esc` — Return to the menu after game over

Player movement and pause controls depend on the player module.
