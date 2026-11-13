# 2D Car Dodging Game

A 2D car-dodging game written in C++ using SFML. Choose a difficulty, move your car up or down to avoid incoming traffic, collect power-ups, and try to beat the saved high score.

## Team

| Name | Roll number | Main responsibility |
|---|---|---|
| Muhammad Tayyab | 26L-0765 | Main game loop, shared game data, and asset loading |
| Muhammad Asim | 26L-0792 | Traffic movement and spawning, collisions, scoring, and power-ups |
| Maryam Sajjad | 26L-0851 | Menu events, difficulty selection, and on-screen interface |

## Features

- Three difficulty levels: Easy, Medium, and Hard
- Player car movement and incoming traffic
- Collision detection and game-over screen
- Score and saved high score
- Traffic speed increases as the game continues
- Shield and slow-traffic power-ups
- Scrolling road and looping background music

## Project files

| File or folder | Purpose |
|---|---|
| `main.cpp` | Creates the game window and runs the main loop |
| `GameData.h` | Holds shared game state, including cars, road, score, and power-ups |
| `Assets.h`, `Assets.cpp` | Declare and implement asset loading |
| `Player.h`, `Player.cpp` | Declare and implement player movement |
| `Traffic.h`, `Traffic.cpp` | Handle traffic, power-up movement, collisions, and scoring |
| `Menu.h`, `menu.cpp` | Handle menu input, difficulty selection, and the HUD |
| `assets/` | Contains the game's images, font, and music |
| `highscore.txt` | Created in the working directory when a high score is saved |
| `dll/` | Contains the bundled Release runtime DLLs for SFML graphics, window, system, and audio |

## Build requirements

- Windows and Visual Studio 2022 with the C++ desktop development workload
- SFML 2.6.1 for Visual C++ 17 (2022), matching the project's platform; these instructions use x64 and Release configuration.
- The assets included in `assets/`

## Set up SFML 2.6.1 in Visual Studio

1. Download the **Visual C++ 17 (2022), 64-bit** SFML 2.6.1 package from the [official SFML 2.6.1 download page](https://www.sfml-dev.org/download/sfml/2.6.1/).
2. Extract it to a location such as `C:\SFML-2.6.1`. Keep the SFML installation separate from this game repository.
3. Open the game solution in Visual Studio. In the toolbar, select **x64**. If the solution does not include a Visual Studio project, create an **Empty Project** and add `main.cpp`, `Assets.cpp`, `Player.cpp`, `Traffic.cpp`, and `menu.cpp` to it.
4. In Solution Explorer, right-click the game project and select **Properties**. Set **Configuration** to **All Configurations** and **Platform** to **x64**.
5. Under **C/C++ > General > Additional Include Directories**, add:

   ```text
   C:\SFML-2.6.1\include
   ```

6. Under **Linker > General > Additional Library Directories**, add:

   ```text
   C:\SFML-2.6.1\lib
   ```

7. Under **Linker > Input > Additional Dependencies**, add the SFML libraries for each configuration:
   - **Debug:** `sfml-graphics-d.lib; sfml-window-d.lib; sfml-system-d.lib; sfml-audio-d.lib;`
   - **Release:** `sfml-graphics.lib; sfml-window.lib; sfml-system.lib; sfml-audio.lib;`
8. Under **Configuration Properties > Debugging > Working Directory**, set the value to:

   ```text
   $(ProjectDir)
   ```

   The game loads files from `assets/...` and reads or writes `highscore.txt` relative to this folder.

9. Click **Apply**, then **OK**. Select **Debug** or **Release** and **x64**, then build the project.

Use the SFML package built for the same Visual Studio version and platform. The DLLs currently included in `dll/` are Release-style DLLs, so select **Release** and **x64** when using the bundled set. Debug libraries must be paired with matching Debug DLLs; those are not currently included.

## Runtime DLLs

The repository includes these runtime DLLs in its `dll/` folder:

- `sfml-audio-2.dll`
- `sfml-graphics-2.dll`
- `sfml-system-2.dll`
- `sfml-window-2.dll`
- `openal32.dll` (needed by SFML Audio)

This is the Release-style set. Use the Debug DLLs from your matching SFML installation if you build in Debug.

To let Visual Studio find DLLs in that subfolder, open the project **Properties > Configuration Properties > Debugging > Environment** and add:

```text
PATH=$(ProjectDir)dll;%PATH%
```

When running the `.exe` outside Visual Studio, copy the matching DLLs from `dll/` beside the `.exe`, or use a launcher that adds `dll/` to `PATH`. Windows does not automatically search a subfolder of the executable's directory for DLLs.

## Build and run

1. Make sure the project uses the SFML include, library, and runtime DLL paths described above.
2. Confirm the `assets/` folder contains these files and that their names match the paths in `Assets.cpp`: `menuu.jpeg`, `enemy.png`, `enemy2.png`, `road.jpeg`, `gameover.jpeg`, `car.png`, `PressStart2P-Regular.ttf`, `powerup-shield.png`, `powerup-slow.png`, and `soft-arcade-racing-loop.wav`.
3. Confirm the `dll/` folder contains the five DLLs listed above.
4. Keep the working directory set to `$(ProjectDir)` and select **Release** and **x64**.
5. Build the solution, then choose **Debug > Start Without Debugging** to run the game.

## Controls

- `1` — Start on Easy
- `2` — Start on Medium
- `3` — Start on Hard
- `Up` / `Down` arrows — Move the player's car
- `Esc` — Return to the menu after game over

The features for Pause using 'P' to Pause and 'X' to unpause have to be implemented in the future.
