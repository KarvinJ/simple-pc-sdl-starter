#include <iostream>
#include "inc/SDL.h"

#undef main

int main() {

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("My Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 960, 640, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Set drawing color to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // RGB: Red (255, 0, 0), Alpha (255)

    // Clear the renderer
    SDL_RenderClear(renderer);

    // Set drawing color to white
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // RGB: White (255, 255, 255), Alpha (255)

    // Define the rectangle's dimensions and position
    SDL_Rect rectangle;
    rectangle.x = 960 / 2 - 16; // X coordinate of the top-left corner
    rectangle.y = 640 / 2 - 16; // Y coordinate of the top-left corner
    rectangle.w = 32;            // Width of the rectangle
    rectangle.h = 32;            // Height of the rectangle

    // Render the rectangle
    SDL_RenderFillRect(renderer, &rectangle);

    // Present the renderer
    SDL_RenderPresent(renderer);

    // Main loop
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}