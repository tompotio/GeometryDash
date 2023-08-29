#include "../include/GraphicsManager.hpp"

// [Renderable Class method's defintion] ------------------------------------------------------------------------------------------------------------------------------

void Renderable::Draw(){
    std::cout << shape << ":" << x << ":" << y << ":" << w << ":" << h << ":" << std::endl;
    GraphicsManager& graphicsManager = GraphicsManager::GetInstance();
    if(showTexture){

    }else if(showShape){
        std::cout << shape << ":" << x << ":" << y << ":" << w << ":" << h << ":" << std::endl;
        graphicsManager.RenderShape(shape, x,y,w,h,color);
    }
}

void Renderable::SetPosition(int x, int y){
    this->x = x;
    this->y = y;
}

// [GraphicsManager Class method's defintion] ------------------------------------------------------------------------------------------------------------------------------

void GraphicsManager::RenderTexture(SDL_Texture* texture, int x, int y){
    int textureWidth, textureHeight;
    SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
    SDL_Rect rect = {x, y, textureWidth, textureHeight };
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void GraphicsManager::RenderTexture(SDL_Texture* texture, int x, int y, int w, int h){
    SDL_Rect rect = {x, y, w, h };
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void GraphicsManager::RenderShape(Shape_E shape, int x, int y, int w, int h, const SDL_Color color){
    if (shape == Shape_E::CARRE){
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_Rect rect = {x, y, w, h};
        SDL_RenderFillRect(renderer, &rect);
    }
    else if (shape == Shape_E::TRIANGLE){
        SDL_Vertex triangleVertex[3] = {
            {
                {(float)x,(float) (y + (h/2))}, /* first point location */ 
                color, /* first color */ 
                { 0.f, 0.f }
            },
            {
                {(float) (x + (w / 2)),(float)(y - (h/2))}, /* second point location */ 
                color, /* second color */
                { 0.f, 0.f }
            },
            {
                {(float)(x - (w/2)),(float)(y - (h/2))}, /* third point location */ 
                color, /* third color */
                { 0.f, 0.f }
            }
        };

        if( SDL_RenderGeometry(renderer, NULL, triangleVertex, 3, NULL, 0) < 0 ) {SDL_Log("%s\n", SDL_GetError());}
    }
}

void GraphicsManager::CleanUp(){
    for (const auto& pair : textures){
        SDL_Texture* texture = pair.second;
        SDL_DestroyTexture(texture);
    }
    textures.clear();
}