#include "../include/GameMenu.hpp"

GameMenu::GameMenu(Game* game){
    this->game = game;

    //std::cout << frame1.GetX() << ":" << frame1.GetY() << ":" << frame1.GetW() << ":" << frame1.GetH() << std::endl;

    frames.push_back(new Frame(250,250,200,200));
}

void GameMenu::HandleEvents(){
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type)
        {
        case SDL_QUIT:
            game->SetIsRunning(false);
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

void GameMenu::HandleKeyPress(SDL_Keycode key){
    if((key == SDLK_z) || (key == 0)){

    }
}

void GameMenu::Render(){
    for(Frame* frame : frames){
        frame->Draw();
        frame->DrawW();
    }
}

void GameMenu::Update(double deltaT){
    
}