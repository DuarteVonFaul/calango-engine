#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>



class Window {

private:
    sf::RenderWindow* window;

public:

    Window(int, int, std::string = "CalangoEngine");
    ~Window();


    void start();
    void stop();




};