#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/projectName_functions.h"

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window *win = SDL_CreateWindow(
        "SDL2 Window",
        100, 100,
        640, 480,
        SDL_WINDOW_SHOWN);
    if (!win) {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    my_function();
    SDL_Delay(3000);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return EXIT_SUCCESS;

}