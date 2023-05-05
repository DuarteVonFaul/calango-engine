#include <SFML/Graphics.hpp>


int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");


    sf::RectangleShape leftPaddle(sf::Vector2f(20, 100));
    leftPaddle.setPosition(50, 250);
    leftPaddle.setFillColor(sf::Color::White);

    sf::RectangleShape rightPaddle(sf::Vector2f(20, 100));
    rightPaddle.setPosition(730, 250);
    rightPaddle.setFillColor(sf::Color::White);


    sf::CircleShape ball(10);
    ball.setPosition(395, 295);
    ball.setFillColor(sf::Color::White);


    float ballVelocityX = 0.05f;
    float ballVelocityY = 0.03f;


    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        ball.move(ballVelocityX, ballVelocityY);


        if (ball.getPosition().y < 0 || ball.getPosition().y > 590)
        {
            ballVelocityY = -ballVelocityY;
        }


        if (ball.getGlobalBounds().intersects(leftPaddle.getGlobalBounds()) ||
            ball.getGlobalBounds().intersects(rightPaddle.getGlobalBounds()))
        {
            ballVelocityX = -ballVelocityX;
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && leftPaddle.getPosition().y > 0)
        {
            leftPaddle.move(0, -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && leftPaddle.getPosition().y < 500)
        {
            leftPaddle.move(0, 1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && rightPaddle.getPosition().y > 0)
        {
            rightPaddle.move(0, -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && rightPaddle.getPosition().y < 500)
        {
            rightPaddle.move(0, 1);
        }


        window.clear(sf::Color::Black);


        window.draw(leftPaddle);
        window.draw(rightPaddle);
        window.draw(ball);


        window.display();
    }

    return 0;
}