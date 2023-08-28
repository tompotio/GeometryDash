#include <iostream>
#include <vector>

#include "ScreenManager.hpp"
#include "GraphicsManager.hpp"
#include "Entities.hpp"

class Game {
    public:
        Game();
        void Run();

    private:
        bool isRunning;
        double deltaT;
        double fps;

        std::vector<Renderable*> renderables;
        std::vector<Updatable*> updatables;
        Player player;

        ScreenManager screenManager;
        GraphicsManager& graphicsManager = GraphicsManager::GetInstance();

        void HandleEvents();
        void HandleKeyPress(SDL_Keycode key);
        void Update();
        void Render();
        void Clean();
};

