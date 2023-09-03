#include "../include/GameMenu.hpp"

GameMenu::GameMenu(Game* game){
    this->game = game;
    clicking = false;

    int frame1Width = 1000;

    Frame* frame1 = new Frame((int)(960 - (frame1Width/2)),250,frame1Width,570);

    frame1->SetShape(Shape_E::RECTANGLE);
    frame1->SetColor(DIMGRAY);

    Button* play_but = new Button(500,500,250,50);

    play_but->SetShape(Shape_E::RECTANGLE);

    play_but->SetOnClick([play_but,game](){
        game->SetGameState(GameState_E::In_Game);
    });

    play_but->SetText("PLAY !");

    frame1->AddWidget(play_but);
    frame1->SetCentered(true);
    frames.push_back(frame1);
}

void GameMenu::HandleEvents(){
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type)
        {
        case SDL_QUIT:
            game->SetIsRunning(false);
            break;

        case SDL_MOUSEBUTTONDOWN:
            clicking = true;
            break;

        case SDL_MOUSEBUTTONUP:
            clicking = false;
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
    }
}

void GameMenu::Update(double deltaT){
    for(Frame* frame : frames){
        frame->Update(deltaT,clicking);
    }
}