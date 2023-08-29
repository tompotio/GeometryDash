#include "../include/Widget.hpp"

void Widget::Update(double deltaT) {
    
}

Frame::Frame(int x, int y, int width, int height) : Widget(x, y, width, height){
    showShape = true;
    showTexture = false;
    shape = Shape_E::CARRE;
    color = MAGENTA;
}

void Frame::DrawW(){
    for(Widget* widget : widgets){
        widget->Draw();
    }
}

void Frame::Update(double deltaT) {
    
}