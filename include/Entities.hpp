#pragma once

#include "GraphicsManager.hpp"

class Player : public Renderable, public Updatable{
    public:
        Player(double x, double y, int w, int h);
        void Jump();
        void Update(double deltaT) override;
    
    private:
        bool isJumping;
        bool canJump;
        float jumpHeight;
        float jumpSpeed;
        float gravity;
};

class Obstacle : Renderable {
    public:

    private:
};