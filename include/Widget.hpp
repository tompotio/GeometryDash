#pragma once
#include <vector>
#include <functional>

#include "GraphicsManager.hpp"

class Widget : public Renderable, Updatable{
    public:
        Widget(int x, int y, int width, int height) : Renderable(x, y, width, height) {
            showShape = true;
            showTexture = false;
        }

        void SetOnHover(std::function<void()> callback) {
            onHoverCallback = callback;
        }

        void SetOnClick(std::function<void()> callback) {
            onClickCallback = callback;
        }

        void SetHovered(bool val){hovered = val;}

        bool GetHovered(){return hovered;}

        void Reset(){SetColor(MAGENTA);}

        void OnHover() {
            if (onHoverCallback) {
                onHoverCallback();
            }
        }

        void OnClick() {
            if (onClickCallback) {
                onClickCallback();
            }
        }

        void Update(double deltaT) override;

    protected:
        bool hovered;

        std::function<void()> onHoverCallback;
        std::function<void()> onClickCallback;
};

class Button : public Widget {
    public:
        Button(int x, int y, int width, int height) : Widget(x,y,width,height) {
            this->onHoverCallback = [this](){
                this->SetColor(this->GetHoverColor());
            };
        }

        void SetHoverColor(SDL_Color hc){hoverColor = hc;}
        void SetColor(SDL_Color c){color = c;showColor = c;}
        SDL_Color GetHoverColor(){return hoverColor;}
        SDL_Color GetShowColor(){return showColor;}

    private:
        SDL_Color showColor = MAGENTA;
        SDL_Color hoverColor = MAGENTA;
        
};

class Frame : public Widget{
    public:
        Frame(int x, int y, int width, int height);

        void DrawW();
        void AddWidget(Widget* widget);
        void Update(double deltaT) override;
        void Update(double deltaT, bool clicking);

    private:
        std::vector<Widget*> widgets;
};