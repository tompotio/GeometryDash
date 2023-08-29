#pragma once
#include <vector>
#include <functional>

#include "GraphicsManager.hpp"

class Widget : public Renderable, Updatable{
    public:
        Widget(int x, int y, int width, int height): x(x), y(y), w(width), h(height) {}

        void SetOnHover(std::function<void()> callback) {
            onHoverCallback = callback;
        }

        void SetOnClick(std::function<void()> callback) {
            onClickCallback = callback;
        }

        void Update(double deltaT) override;

    protected:
        int x; 
        int y;
        int w;
        int h;

        std::function<void()> onHoverCallback;
        std::function<void()> onClickCallback;
};

class Frame : public Widget{
    public:
        Frame(int x, int y, int width, int height);

        void DrawW();
        void addWidget(Widget& widgets...);
        void Update(double deltaT) override;

    private:
        std::vector<Widget*> widgets;
};