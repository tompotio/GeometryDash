#include "../include/ScreenManager.hpp"

ScreenManager::ScreenManager() {
    const char* title = "GeometryDash";

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "Erreur lors de l'initialisation de SDL : " << SDL_GetError() << std::endl;
    }

    // Récupère la résolution de base (écran principal)
    SDL_DisplayMode desktopMode;
    if (SDL_GetDesktopDisplayMode(0, &desktopMode) != 0) {
        std::cout << "Erreur lors de la récupération de la résolution du bureau : " << SDL_GetError() << std::endl;
    }

    window = SDL_CreateWindow(title, 0, 0, desktopMode.w, desktopMode.h, SDL_WINDOW_FULLSCREEN);
    if (!window) {
        std::cout << "Erreur lors de la création de la fenêtre : " << SDL_GetError() << std::endl;
    }
    else {
        std::cout << "Fenêtre créée !" << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cout << "Erreur lors de la création du renderer : " << SDL_GetError() << std::endl;
    }
    else {
        std::cout << "Renderer créé !" << std::endl;
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    }

    SDL_SetWindowTitle(window, title);
}
