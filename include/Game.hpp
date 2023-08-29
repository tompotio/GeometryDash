#pragma once

#include <iostream>
#include <vector>

#include "ScreenManager.hpp"
#include "GraphicsManager.hpp"
#include "Entities.hpp"
#include "GameMenu.hpp"

enum GameState_E {
    Game_Menu,
    Pause_Menu,
    In_Game,
};

class Game {
    public:
        Game();
        void Run();
        void SetGameState(GameState_E state) {
            this->gameState = state;
        }
        void SetIsRunning(bool val){this->isRunning = false;}

    private:
        bool isRunning;
        double deltaT;
        double fps;

        std::vector<Renderable*> renderables;
        std::vector<Updatable*> updatables;
        Player player;

        ScreenManager screenManager;
        GraphicsManager& graphicsManager = GraphicsManager::GetInstance();

        GameState_E gameState;
        
        GameMenu* gameMenu;

        void HandleEvents();
        void HandleKeyPress(SDL_Keycode key);
        void Update();
        void Render();
        void Clean();
};

