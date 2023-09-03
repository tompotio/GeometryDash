#include "../include/Widget.hpp"

// [Widget Class method's definition] ---------------------------------------------------------------------------------------------------------------------------------

void Widget::Update(double deltaT) {
    
}

void Button::SetHovered(bool val){
    Widget::SetHovered(val);
    if (!val){
        this->SetColor(showColor);
    }
}

// [Frame Class method's definition] ---------------------------------------------------------------------------------------------------------------------------------

Frame::Frame(int x, int y, int width, int height) : Widget(x, y, width, height), centered(false), centeredWidgets(false){
    showShape = true;
    showTexture = false;
    hovered = false;
}

void Frame::AddWidget(Widget* widget){
    widgets.push_back(widget);

}

void Frame::Draw(){
    Renderable::Draw();
    for(Widget* widget : widgets){
        widget->Draw();
    }
}

bool CompareWidgets(const Widget* widget1, const Widget* widget2) {
    return widget1->GetLayoutOrder() <= widget2->GetLayoutOrder();
}

void Frame::SetCentered(bool val){
    centered = val;

    std::sort(widgets.begin(), widgets.end(), CompareWidgets);
    for (Widget* widget : widgets) {
        int x = (this->GetW() - widget->GetW()) / 2;
        int y = (this->GetH() - widget->GetH()) / 2;
        widget->SetPosition(x, y);
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
                if(widget->IsA(Widget_E::button)){
                    Button* button = dynamic_cast<Button*>(widget);
                    button->SetHovered(false);
                }else{
                    widget->SetHovered(false);
                }
            }
        }
    }
}