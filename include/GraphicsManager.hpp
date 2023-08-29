#pragma once

#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <map>
#include <string>
#include <iostream>
#include "Enums.hpp"

class Renderable {
    public:
        void Draw();
        void SetPosition(int x, int y);

    protected:
        bool showShape;
        bool showTexture;

        int w; 
        int h;

        double x;
        double y;

        std::string texture_id;
        Shape_E shape;
        SDL_Color color;
};

class Updatable {
    public:
        virtual void Update(double deltaT) = 0;
};

class GraphicsManager {
    public:
        /**
         * @brief Render une texture avec ses dimensions de base.
         */
        void RenderTexture(SDL_Texture* texture, int x, int y);

        /**
         * @brief Render une texture avec des dimensions personnalisées.
         */
        void RenderTexture(SDL_Texture* texture, int x, int y, int w, int h);

        /**
         * @brief Render une forme géométrique avec ses dimensions et sa position.
         */
        void RenderShape(Shape_E shape, int x, int y, int w, int h, const SDL_Color color);

        /**
         * @brief Nettoie les textures lors de la fermeture.
         */
        void CleanUp();

        void SetRenderer(SDL_Renderer* renderer){
            this->renderer = renderer;
        }

        static GraphicsManager& GetInstance() {
            static GraphicsManager instance; // Crée une unique instance
            return instance;
        }

    private:
        SDL_Renderer* renderer;

        std::map<std::string,SDL_Texture*> textures;
};