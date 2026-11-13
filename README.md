# 2D Car Dodging Game

A 2-D car dodging game created written in C++ using SFML. Use up and down arrow keys to move your car while avoiding oncoming obstacles on the road.

## Team

| Name | Roll number | Tasks |
|---|---|---|
| Muhammad Tayyab | 26L-0765 | Main game loop, shared game data, and asset loading |
| Muhammad Asim | 26L-0792 | Traffic movement and spawning, collisions, scoring, and power-ups |
| Maryam Sajjad | 26L-0851 | Menu events, difficulty selection, and on-screen interface |

## Features

- Three difficulty levels: Easy, Medium, and Hard
- Player car movement using arrow keys and incoming obstacles to avoid
- Collision detection and a single life, with game-over screen upon first collision
- Score counter and highscore recorded, passing each car increases the score counter by +1
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

1. Download Visual Studio 2022 64-bit and download desktop development extension
2. Create Empty project and select x64 and Release in tool bar
3. Add the cpp files via Solution explorer
4. Go to top bar, right click project and select properties
5. Under **C/C++ > General > Additional Include Directories**, add:
   ```text
   C:\SFML-2.6.1\include
   ```
6. Under **Linker > General > Additional Library Directories**, add:
   ```text
   C:\SFML-2.6.1\lib
   ```
7. Under **Linker > Input > Additional Dependencies**, add the SFML libraries:
   - **Release:** `sfml-graphics.lib; sfml-window.lib; sfml-system.lib; sfml-audio.lib;`
	- For Debug version, use the -d versions 
8. Under **Configuration Properties > Debugging > Working Directory**, set the value to:
   ```text
   $(ProjectDir)
   ```

9. Click **apply** then seclect **ok**

Use the SFML package built for the same Visual Studio version and platform. The DLLs currently included in `dll/` are Release-style DLLs, so select **Release** and **x64** when using the bundled set. Debug libraries must be paired with matching Debug DLLs; those are not currently included.


## Build and run

1. Make sure the project uses the SFML include, library, and dlls.
2. Confirm the `assets/` folder contains these files and that their names match the paths in `Assets.cpp`: `menuu.jpeg`, `enemy.png`, `enemy2.png`, `road.jpeg`, `gameover.jpeg`, `car.png`, `PressStart2P-Regular.ttf`, `powerup-shield.png`, `powerup-slow.png`, and `soft-arcade-racing-loop.wav`.
3. Keep the working directory set to `$(ProjectDir)` and select **Release** and **x64**.
4. Build the solution, then choose **Debug > Start Without Debugging** to run the game.

## Controls

- `1` — Easy mode
- `2` — Medium mode
- `3` — Hard mode
- `Up` / `Down` arrows — Move the player's car
- `Esc` — Return to the menu after game over

The pause function using `P` to pause and `X` to unpause are yet to be implemented
