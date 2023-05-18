#include "Window.hpp"
#include "Area2D.h"
#include "Retangle.hpp"
#include "Sprite.hpp"
#include <iostream>


class Player : public Area2D {

private:


public:

    Player(Vector2D pos) : Area2D(pos) {
        addChildren("head", new Retangle(20, 20, Vector2D(0, 0)));
    };

    void update() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->getPos().getX() > 0)
        {
            setPos(getPos() + Vector2D(-10, 0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && this->getPos().getX() < 1600 - 30)
        {
            setPos(getPos() + Vector2D(10, 0));
        }

        /*if (this->getPos().getY() < 600 - 70) {
            setPos(getPos() + Vector2D(0, 10));
        }*/

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->getPos().getY() >= 600 - 70) {
            setPos(getPos() + Vector2D(0, -250));
            
        }

    };

   
};




class Win01 : public Scene {

public:
    Win01() {
        this->addChild("Player", new Player(Vector2D(200, 50)));
    };
};



int main()
{

    Window window(1600, 600);
    window.changeScene(new Win01());
    window.start();

    return 0;
}