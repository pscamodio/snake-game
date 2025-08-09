# Snake C++ Project

This project contains two sub-projects:

- **engine**: A static library with reusable code.
- **game**: An application that uses the engine library.

## Build Instructions

1. Create a build directory:
   ```bash
   mkdir -p build && cd build
   ```
2. Run CMake:
   ```bash
   cmake ..
   ```
3. Build the project:
   ```bash
   cmake --build .
   ```
4. Run the game:
   ```bash
   ./game/game
   ```
