#include "../include/Game.hpp"
#include <chrono>

Game::Game(){
    isRunning = true;
    graphicsManager.SetRenderer(screenManager.GetRenderer());

    renderables.push_back(&player);
    player.SetPosition(100,1030);

    updatables.push_back(&player);
}

void Game::Run() {
    using namespace std::chrono;

    high_resolution_clock::time_point currentTime, lastFrameTime;
    nanoseconds elapsedTime;

    while (isRunning) {
        HandleEvents();

        currentTime = high_resolution_clock::now();
        elapsedTime = duration_cast<nanoseconds>(currentTime - lastFrameTime);
        deltaT = static_cast<float>(elapsedTime.count()) / 1e9f;

        if (elapsedTime.count() > 0) {
            fps = 1e9f / static_cast<float>(elapsedTime.count());
            std::cout << "FPS: " << fps << std::endl;
        }

        lastFrameTime = currentTime;

        Update();
        Render();
    }

    Clean();
}


void Game::HandleEvents(){
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        // Partie clavier
        case SDL_KEYDOWN:
            // Le joueur saute.
            if(event.key.keysym.sym == SDLK_z){
                HandleKeyPress(SDLK_z);
            }
            break;
        
        // Partie event manette 
        case SDL_JOYBUTTONDOWN:
            if (event.jbutton.button == 0) {
                HandleKeyPress(0);
            }
            break;
        default:
            break;
        }
    }
}

void Game::HandleKeyPress(SDL_Keycode key){
    if((key == SDLK_z) || (key == 0)){
        player.Jump();
    }
}

void Game::Render(){
    SDL_SetRenderDrawColor(screenManager.GetRenderer(), BLANC.r, BLANC.g, BLANC.b, BLANC.a);
    screenManager.RenderClear();
    // Boucle sur les objets du jeu et les render.
    for(Renderable* renderable : renderables){
        renderable->Draw();
    }
    screenManager.RenderPresent();
}

void Game::Clean(){
    graphicsManager.CleanUp();
    screenManager.Clean();
}

void Game::Update(){
    for(Updatable* updatable : updatables){
        updatable->Update(deltaT);
    }
}