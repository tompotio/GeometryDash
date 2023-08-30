#include "../include/Widget.hpp"

// [Widget Class method's definition] ---------------------------------------------------------------------------------------------------------------------------------

void Widget::Update(double deltaT) {
    
}

// [Frame Class method's definition] ---------------------------------------------------------------------------------------------------------------------------------

Frame::Frame(int x, int y, int width, int height) : Widget(x, y, width, height){
    showShape = true;
    showTexture = false;
    hovered = false;
}

void Frame::AddWidget(Widget* widget){
    widgets.push_back(widget);
}

void Frame::DrawW(){
    for(Widget* widget : widgets){
        widget->Draw();
    }
}

void Frame::Update(double deltaT) {
    
}

void Frame::Update(double deltaT, bool clicking) {
    int x,y;
    SDL_GetMouseState(&x, &y);

    for(Widget* widget : widgets){
        if(widget->GetShape() == Shape_E::RECTANGLE){
            bool collide = false;
            if(
                (x >= widget->GetX()) && 
                (x <= (widget->GetX() + widget->GetW())) &&
                (y >= widget->GetY()) && 
                (y <= (widget->GetY() + widget->GetH()))
            ){
                collide = true;
                widget->SetHovered(true);
                widget->OnHover();
                if(clicking){
                    widget->OnClick();
                }
            }
            if(!collide && widget->GetHovered()){
                widget->SetHovered(false);
                widget->Reset();
            }
        }
    }
}