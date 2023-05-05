#pragma once
#include "Window.hpp"


Window::Window(int width, int height, std::string title) :
    window(new sf::RenderWindow(sf::VideoMode(width, height), title))
{};
void Window::start() {

    //Lista de Elementos

    while (this->window->isOpen()) {

        sf::Event event;
        while (this->window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                this->window->close();
        }

        //Aqui são os Inputs

        this->window->clear(sf::Color::Black);


        //Desenhar na tela
        /*this->window->draw(leftPaddle);
        this->window->draw(rightPaddle);
        this->window->draw(ball);*/


        this->window->display();
    }
}
void Window::stop() {

}