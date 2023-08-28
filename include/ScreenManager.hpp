
#pragma once 

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL_image.h>

// Classe qui s'occupe de gérer l'écran du jeu.
class ScreenManager{
    public: 
        ScreenManager();

        void Clean(){
            SDL_DestroyWindow(window);
        };

        // Applique le nouveau rendu : Ce qu'il y avait dans le backbuffer précédent.
        void RenderClear()
        {
            SDL_RenderClear(renderer);
        };

        // Rajoute un nouveau rendu à afficher.
        void RenderPresent()
        {
            SDL_RenderPresent(renderer);
        };

        SDL_Renderer* GetRenderer(){return renderer;};
        SDL_Window* GetWindow(){return window;};

    private:
        SDL_Renderer* renderer;
        SDL_Window *window;
};