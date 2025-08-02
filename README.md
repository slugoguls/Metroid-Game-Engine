# Metroid Game Engine

> A simple 2D game engine built in C++ and SDL2, focusing on clean architecture and SOLID design principles.

## About The Project

This project was started as a way to learn the fundamentals of game engine development. The primary goal is to build a modular, scalable engine from scratch, applying object-oriented and SOLID principles to create a clean and maintainable codebase.

### Built With

*   C++
*   [SDL2](https://www.libsdl.org/)
*   [CMake](https://cmake.org/)

## Current Features

*   **Renderer:** A basic rendering system that handles window creation and surface blitting.
*   **Input Manager:** A system for processing keyboard input.
*   **Asset Manager:** A simple manager for loading and accessing game assets (currently BMP surfaces).
*   **SOLID Architecture:** The core design emphasizes the Single Responsibility Principle to create decoupled, easy-to-manage components.

## Getting Started

To get a local copy up and running, follow these steps.

1.  Clone the repo
    ```sh
    git clone https://github.com/slugoguls/Metroid-Game-Engine.git
    ```
2.  Configure and build the project using CMake.

## Roadmap

- [ ] Implement a Game State manager
- [ ] Refactor input handling to use the Command pattern
- [ ] Integrate OpenGL for hardware-accelerated rendering
- [ ] Add support for sprite sheets and animations
- [ ] Create a basic 2D physics system
