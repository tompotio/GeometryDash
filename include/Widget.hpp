#pragma once

/**
 * @file Widget.hpp
 *
 * @brief Définition de la classe Widget ainsi que ses classes auxiliaires.
 * Un widget est un objet 2D affiché à l'écran pouvant adopter un comportement en fonction des actions de l'utilisateur.
 * Si l'utilisateur décide de cliquer sur le widget, il est possible de définir un comportement lié à cet action en amont, lors de la création de l'objet.
 * Pour faciliter la création d'une interface, j'ai créé des widgets prédéfinis utiles pour des situations besoins différents.
 * Par exemple la classe Bouton qui hérite de Widget, permet de créer un bouton à l'écran. Avec un système de hovering classique aux boutons déjà écrits.
 * La classe CheckBox crée une checkBox qui fait apparaitre une croix ou bien une encoche personnalisable lorsque l'on clique dessus.
 * 
 * Pour qu'un widget soit correctement utilisé, il doit être lié à une frame préalablement instanciée.
 * Une frame agit comme un conteneur à widgets avec lequel on peut positionner les widgets tout en pouvant imposer des contraintes :  
 * Par exemple en centrant tous les widgets au milieu de la frame.
 * Les coordonées d'un widget sont propres à la position de la frame. Ainsi par exemple : la position (0;0) du widget fait référence à la position (x;y) de la frame dans
 * lequel le widget est implanté.
 * 
 * @date 2023-09-03
 * @author Tompotio
 */

#include <vector>
#include <functional>

#include "GraphicsManager.hpp"
#include "SDL_ttf.h"

enum Widget_E {
    button,
    checkBox,
    label,
    textLabel,
    widget,
    imageButton,
    textInput,
    frame,
};

class Widget : public Renderable, Updatable{
    public:
        Widget(int x, int y, int width, int height) : Renderable(x, y, width, height), hovered(false), clicked(false) {
            this->showShape = true,
            this->showTexture = false;
        }

        void SetOnHover(std::function<void()> callback) {
            onHoverCallback = callback;
        }

        void SetOnClick(std::function<void()> callback) {
            onClickCallback = callback;
        }

        virtual void SetHovered(bool val){hovered = val;}

        virtual bool IsA(Widget_E widgetType){
            if (widgetType == Widget_E::widget){
                return true;
            }
            return false;
        }

        void SetClicked(bool val){clicked = val;}

        void SetLayoutOrder(int val){layoutOrder = val;}

        int GetLayoutOrder() const{return layoutOrder;}

        bool GetHovered(){return hovered;}

        bool GetClicked(){return clicked;}

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
        bool clicked;

        int layoutOrder;

        std::function<void()> onHoverCallback;
        std::function<void()> onClickCallback;
};

class TextLabel : public Widget {
    public: 
        TextLabel(int x, int y, int width, int height) : Widget(x,y,width,height), fontSize(15), textColor(BLANC){
            SetFont(Font_E::StarBorn);
        }

        void SetText(String text){this->text = text;}

        void SetFontSize(int val){fontSize = val;}

        void SetFont(Font_E fontType);

        int GetFontSiez(){return fontSize;}

        void Draw() override;

        String GetText(){return text;}

    private:
        String text;
        Color textColor;
        Font font;
        int fontSize;
};

class Button : public TextLabel {
    public:
        Button(int x, int y, int width, int height) : TextLabel(x,y,width,height), showColor(MAGENTA), hoverColor(MAGENTAHOVER) {
            this->SetColor(showColor);
            this->SetHoverColor(MAGENTAHOVER);
        }

        void SetHovered(bool val) override;

        void SetHoverColor(Color hc){
            hoverColor = hc;
            this->onHoverCallback = [this,hc](){
                this->color = hc;
            };
        }

        void SetColor(Color c){
            showColor = c;
            color = showColor;
        }

        bool IsA(Widget_E widgetType) override{
            if (widgetType == Widget_E::button){
                return true;
            }
            return false;
        }

        Color GetHoverColor(){return hoverColor;}
        Color GetShowColor(){return showColor;}

    private:
        Color showColor;
        Color hoverColor;
        Color texthoverColor;
};

class CheckBox : public Widget {
    public: 

    private:

};

class ImageLabel : public Widget {
    public: 
        void AddTexture(Texture texture){this->texture = texture;}
        Texture GetTexture(){return texture;}

    private:
        Texture texture;
};

class ImageButton : public ImageLabel {
    public: 
        void AddHoverTexture(Texture texture){hovertexture = texture;}
        
        Texture GetHoverTexture(){return hovertexture;}

    private:
        Texture hovertexture;        
};

class TextInput : public Widget {
    public: 

    private:
};

/**
 * @brief Conteneur à widgets. La position des widgets se fait par rapport à la frame et non plus par rapport au reste de l'écran.
 * 
 */
class Frame : public Widget{
    public:
        Frame(int x, int y, int width, int height);

        void Draw();
        void AddWidget(Widget* widget);

        void Update(double deltaT) override;
        void Update(double deltaT, bool clicking);

        void SetCentered(bool val);

        void SetAllWidgetsCentered(bool val){
            centeredWidgets = val;
        }

    private:
        bool centered;
        bool centeredWidgets;

        std::vector<Widget*> widgets;
};