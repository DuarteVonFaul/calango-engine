#pragma once
#include "Component.hpp"
#include "Vector2D.hpp"

class Retangle : public Component {

private:
	sf::RectangleShape* shape;
	Vector2D pos;

public:
	Retangle(int, int, Vector2D);
	sf::Drawable* getElement() const;
	Vector2D getPos() const;
	void updateRelativePos(Vector2D);
	void setPos(Vector2D);
};
