*This project has been created as part of the 42 curriculum by hacharka and azmakhlo.*

# 🧊 cub3D - A Wolfenstein 3D Inspired Raycaster


## 📖 Description

**cub3D** is a graphics project that recreates the 3D game engine technique used in the 90s classic, *Wolfenstein 3D*.

Using the **Raycasting** algorithm, this program renders a 3D perspective inside a maze defined by a 2D map. It is built using the **C language** and the **MLX42** graphics library. This project explores mathematics (trigonometry, vectors), graphics optimization, and event handling.

## ✨ Features

Based on the codebase, this engine supports:

* **Raycasting Rendering:** Uses the DDA (Digital Differential Analyzer) algorithm for precise wall rendering.
* **Texture Mapping:** Supports distinct textures for North, South, East, and West walls.
* **Format Support:** Loads both **PNG** and **XPM** textures.
* **Smooth Movement:**
    * Strafing (moving left/right) and walking (forward/backward).
    * **Sprint Mechanic:** Press `SHIFT` to increase movement speed.
* **Collision Detection:** Prevents the player from walking through walls.
* **Map Parsing & Validation:**
    * Strict checking of map borders and closed walls using the **Flood Fill algorithm**.
    * Parses RGB colors for Floor and Ceiling.
* **Performance:** optimized utilizing the MLX42 library.

## 🛠️ Installation & Usage

### Prerequisites
The project relies on **MLX42**, which requires `cmake` and `glfw`.

* **macOS (Homebrew):** `brew install cmake glfw`
* **Linux (apt):** `sudo apt-get install cmake libglfw3-dev xorg-dev build-essential`

### Building the Project
1.  Clone the repository:
    ```bash
    git clone [https://github.com/azh4rrr/cub3D](https://github.com/azh4rrr/cub3D)
    cd cub3d
    ```
2.  Compile using the Makefile:
    ```bash
    make
    ```
    *This will automatically clone and build the MLX42 library if missing.*

### Running the Game
Run the executable with a path to a `.cub` configuration file:
```bash
./cub3D map.cub
```
## 🎮 Controls Key
| Key | Action |
| :--- | :--- |
| `W` / `S` | Move Forward / Backward |
| `A` / `D` | Strafe Left / Right |
| `←` / `→` | Rotate Camera |
| `Shift` | Sprint (Increase Speed) |
| `ESC` | Quit Game |

## 🗺️ Map Configuration (.cub)
The program parses a file with the .cub extension. The file must contain:
1. **Texture Paths:**
```Plaintext
NO ./path_to_north_texture.png
SO ./path_to_south_texture.png
WE ./path_to_west_texture.png
EA ./path_to_east_texture.png
``````
2. **Colors (RGB):**
```Plaintext
F 220,100,0   (Floor Color)
C 225,30,0    (Ceiling Color)
```
3. **The Map:**
* 1: Wall
* 0: Empty Space
* N, S, E, W: Player start position and orientation

The map must be completely closed/surrounded by walls.
## 📚 Resources
Lodev's Raycasting Tutorial: https://lodev.org/cgtutor/raycasting.html - The primary resource for understanding the DDA algorithm.

MLX42 Documentation: https://github.com/codam-coding-college/MLX42 - API reference for the graphics library.

### 🤖 AI Usage Statement

In accordance with the project's integrity guidelines, AI assistance (Gemini) was utilized strictly as a supportive tool for understanding and debugging, avoiding direct code generation.

* **Algorithm Design:** I used AI to conceptualize the logic behind the **Flood Fill** algorithm for map validation. I used these insights to design my own implementation.
* **Debugging Strategy:** Instead of asking for code fixes, I used AI to explain the root causes of complex linker errors (cmake/library paths). This allowed me to understand the build process and resolve the issues manually.

*Disclaimer: No code was copy-pasted. I wrote the implementation myself to ensure I can justify every decision and line of code during defense.*