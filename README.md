# so_long

## Overview
so_long is a straightforward 2D puzzle-adventure game designed to teach basic game programming concepts. You start at a designated point on a grid-based map, collect all items scattered around, and then make your way to the exit. Along the way, you cannot pass through walls, and each move you make is counted and displayed. This project relies on MiniLibX for rendering graphics and simple event handling.

## Description
In so_long, the player navigates a tile-based map containing floor tiles, walls, collectibles, a single exit, and a starting point. The goal is to pick up all collectibles (`C`) and reach the exit (`E`) in the fewest moves possible. If you try to walk into a wall (`1`) or off the map, the move is ignored. The game runs at 60 frames per second to ensure smooth input handling and rendering.

## How It Works
1. **Map Parsing**: On launch, the program reads a `.ber` map file and validates its format and contents.
2. **Initialization**: Images for background, walls, floor, collectibles, exit, and player are loaded into memory.
3. **Game Loop**: Using MiniLibX’s `mlx_loop_hook()`, the loop:
   - **Processes Input**: Listens for **W/A/S/D**, **ESC**, or window close.
   - **Updates State**: Moves the player if possible, updates collectible count, checks for exit conditions.
   - **Renders Scene**: Draws layers in order: background → map tiles & objects → player.
4. **Move Counter**: After each successful move, the total number of moves is printed in the terminal.
5. **Exit Conditions**: The exit only becomes active once all collectibles have been gathered.
6. **Cleanup**: On exit (ESC, window close, or error), all resources are freed and the application quits gracefully.

## Requirements
- A C compiler (`cc`)
- Compiler flags: `-Wall`, `-Werror`, `-Wextra`, `-lm`
- MiniLibX library (system or source version)
- Permitted functions: `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`, math functions, MiniLibX calls, `ft_printf` or equivalent.

## Installation
1. Clone the repository.
2. Ensure MiniLibX and Libft are installed or available locally.
3. Run `make` to build the executable (`so_long`).

## Usage
```bash
./so_long path/to/map.ber
```
- The map file must have extension `.ber` and follow the format rules.
- Use **W/A/S/D** to move, collect all `C`, then reach `E`.
- Press **ESC** or click the close button to quit.
- On error, you will see `Error\n` followed by a message.

## Map File Rules
- The map is made of characters: `0` (floor), `1` (wall), `C` (collectible), `E` (exit), `P` (player start).
- Must be rectangular and surrounded by walls.
- Exactly one `P` and one `E`.
- At least one `C`.
- Path validation ensures you can collect all `C` and reach `E`.

## Controls
- **W**: move up
- **A**: move left
- **S**: move down
- **D**: move right
- **ESC**: exit game
