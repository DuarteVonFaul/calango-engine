#pragma once
#include "Window.hpp"
#include <chrono>
#include <thread>

Window::Window(int width, int height, std::string title) :
    window(new sf::RenderWindow(sf::VideoMode(width, height), title))
{};

Window::~Window() {
    delete window;
}
void Window::start() {

    const double frameRate = 60.0;
    const std::chrono::duration<double> frameTime(1.0 / frameRate);

    int frameCount = 0;


    while (this->window->isOpen()) {
        auto startTime = std::chrono::steady_clock::now();

        //Logica do Jogo

        sf::Sprite shape;
        sf::Texture texture;
        if (texture.loadFromFile("Player.png")) {
            shape.setTexture(texture);
        }
        shape.setPosition(100, 100);


        sf::Event event;
        while (this->window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                this->window->close();
        }
        if(focus != NULL){
            focus->update();
        }
        

        this->window->clear(sf::Color::Black);

        if (focus != NULL) {
            for (const auto& pair : focus->getEntitys()) {
                for (const auto& comp : pair->getChildren()) {
                    this->window->draw((*comp->getElement()));
                }
            }
        }


        this->window->display();

        auto endTime = std::chrono::steady_clock::now();
        auto elapsedTime = endTime - startTime;

        std::chrono::duration<double> sleepTime = frameTime - elapsedTime;
        if (sleepTime > std::chrono::duration<double>(0)) {
            std::this_thread::sleep_for(sleepTime);
        }

        frameCount++;
    }
}

void Window::changeScene(Scene* scene) {
    this->focus = scene;
};

void Window::stop() {

}