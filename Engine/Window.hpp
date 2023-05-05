#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>


/*sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");
while (window.isOpen())
{
    //EVENT
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    //CLEAR
    window.clear(sf::Color::Black);
    //DRAW
    window.draw(leftPaddle);
    window.draw(rightPaddle);
    window.draw(ball);

    //DISPLAY
    window.display();
}
*/

class Window {

private:
    sf::RenderWindow* window;

public:

    Window(int, int, std::string = "CalangoEngine");
    void start();
    void stop();



};