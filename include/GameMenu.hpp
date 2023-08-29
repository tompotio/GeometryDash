#include <vector>

#include "Game.hpp"
#include "Widget.hpp"

class Game;

#ifndef GAMEMENU_HPP
#define GAMEMENU_HPP

class GameMenu {
    public:
        /**
         * @brief Construct a new Game Menu object
         * C'est ici que l'on assemble le menu en créant de nouvelles frames.
         * Et en ajoutant des widgets dans les frames.
         * @param game 
         */
        GameMenu(Game* game);

        void HandleEvents();
        void Render();
        void Update(double deltaT);
        
    private:
        std::vector<Frame*> frames;

        Game* game;

        void HandleKeyPress(SDL_Keycode key);
};

#endif // GAMEMENU_HPP