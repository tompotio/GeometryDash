#include "../include/Entities.hpp"

// [Player Class method's definition] ---------------------------------------------------------------------------------------------------------------------------------

Player::Player(double x, double y, int w, int h) : Renderable(x,y,w,h) {
    isJumping = false;
    showShape = true;
    showTexture = false;
    shape = Shape_E::RECTANGLE;
    color = MAGENTA;
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
    } else { // Memo : Appliquer la rotation du joueur ici 
        if (y < 1030){
            y += gravity * deltaT;
        }else if(y >= 1030){
            canJump = true;
            y = 1030;
        }
    }
}

// [Obstacles Class method's definition] -----------------------------------------------------------------------------------------------------------------------------

