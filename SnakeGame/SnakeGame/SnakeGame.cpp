#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

const int Screen_WIDTH = 800;
const int Screen_HEIGHT = 600;

SDL_Window* g_window = nullptr;
SDL_Renderer* g_renderer = nullptr;
SDL_Texture* g_backgroundTexture = nullptr;
SDL_Event g_event;

bool Init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }
    g_window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Screen_WIDTH, Screen_HEIGHT, SDL_WINDOW_SHOWN);
    if (g_window == nullptr) {
        cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }
    g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
    if (g_renderer == nullptr) {
        cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }
    SDL_SetRenderDrawColor(g_renderer, 255, 255, 255, 255); // Set renderer color to white
    return true;
}

SDL_Texture* LoadTexture(string file_path) {
    SDL_Surface* surface = IMG_Load(file_path.c_str());
    if (surface == nullptr) {
        cerr << "Unable to load image! SDL_Error: " << IMG_GetError() << endl;
        return nullptr;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(g_renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void ApplyTexture(SDL_Texture* texture, int x, int y) {
    SDL_Rect destRect = { x, y, Screen_WIDTH, Screen_HEIGHT };
    SDL_RenderCopy(g_renderer, texture, NULL, &destRect);
}

void Cleanup() {
    SDL_DestroyTexture(g_backgroundTexture);
    SDL_DestroyRenderer(g_renderer);
    SDL_DestroyWindow(g_window);
    g_backgroundTexture = nullptr;
    g_renderer = nullptr;
    g_window = nullptr;
}

int main(int argc, char* argv[]) {
    if (!Init()) {
        return 1; // Error in initialization
    }

    g_backgroundTexture = LoadTexture("img.jpg");
    if (g_backgroundTexture == nullptr) {
        Cleanup();
        return 1; // Error in loading texture
    }

    while (true) {
        while (SDL_PollEvent(&g_event)) {
            if (g_event.type == SDL_QUIT) {
                Cleanup();
                SDL_Quit();
                return 0; // Quit the program
            }
        }
        SDL_RenderClear(g_renderer);
        ApplyTexture(g_backgroundTexture, 0, 0);
        SDL_RenderPresent(g_renderer);
    }

    return 0;
}
