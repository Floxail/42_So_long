_This project has been created as part of the 42 curriculum by flvejux_

## Description

So Long is a 2D game project built using the MLX (MiniLibX) graphics library. The goal is to create a simple tile-based game where a player navigates through a map, collects items, and reaches an exit while avoiding obstacles.

### Features
- 2D tile-based map rendering
- Player movement with keyboard controls
- Collectible items to gather before reaching the exit
- Enemy obstacles and collision detection
- Move counter displayed during gameplay
- Map validation with error handling

## Instructions

### Compilation
```bash
make
```

To clean object files:
```bash
make clean
```

To remove all compiled files and binaries:
```bash
make fclean
```

### Running the Game
```bash
./so_long <map_file>
```

Example:
```bash
./so_long maps/map.ber
```

### Map Format
Maps must be in `.ber` format and follow these requirements:
- Map must be rectangular and closed by walls (1)
- Player (P) must be present (exactly one)
- At least one collectible (C) required
- Exactly one exit (E) required
- Valid characters: 0 (empty), 1 (wall), P (player), C (collectible), X (Enemy), E (exit)

### Controls
- **W** - Move up
- **A** - Move left
- **S** - Move down
- **D** - Move right
- **ESC** - Close the game

## Resources

- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [42GitBook](https://42-cursus.gitbook.io/guide/2-rank-02/so_long)
- Gemini for structuration and Minilibx usage

