#include "GraphicsManager.hpp"

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

class Player : public Renderable, public Updatable{
    public:
        Player();
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