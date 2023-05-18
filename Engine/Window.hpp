#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "Scene.hpp"



class Window {

private:
    sf::RenderWindow* window;
    Scene* focus;

public:

    Window(int, int, std::string = "CalangoEngine");
    ~Window();
    void changeScene(Scene*);

    void start();
    void stop();




};