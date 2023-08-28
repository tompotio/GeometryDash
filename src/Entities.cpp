#include "../include/Entities.hpp"

// [Renderable Class method's defintion] ------------------------------------------------------------------------------------------------------------------------------

void Renderable::Draw(){
    GraphicsManager& graphicsManager = GraphicsManager::GetInstance();
    if(showTexture){

    }else if(showShape){
        graphicsManager.RenderShape(shape, x, y,w,h,color);
    }
}

void Renderable::SetPosition(int x, int y){
    this->x = x;
    this->y = y;
}

// [Player Class method's definition] ---------------------------------------------------------------------------------------------------------------------------------

Player::Player(){
    isJumping = false;
    showShape = true;
    showTexture = false;
    shape = Shape_E::CARRE;
    color = MAGENTA;
    w = 50;
    h = 50;
    jumpHeight = 130.0f;
    jumpSpeed = 800.0f;
    gravity = 800.0f;
    canJump = true;
}

void Player::Jump(){
    if(!isJumping && canJump){
        isJumping = true;
        canJump = false;
    }
}

void Player::Update(double deltaT) {
    if (isJumping) {
        double height = jumpSpeed * deltaT;
        jumpHeight -= height;
        if(jumpHeight <= 0.0f){
            isJumping = false;
            jumpHeight = 130.0f;
            return;
        }
        y -= height;
    } else {
        if (y < 1030){
            y += gravity * deltaT;
        }else if(y >= 1030){
            canJump = true;
            y = 1030;
        }
    }
}

// [Obstacles Class method's definition] -----------------------------------------------------------------------------------------------------------------------------

