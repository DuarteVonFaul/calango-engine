#include "Retangle.hpp"



Retangle::Retangle(int width, int height, Vector2D first_pos) {
	shape = new sf::RectangleShape(sf::Vector2f(width, height));
	shape->setPosition(first_pos.getX(), first_pos.getY());
	shape->setFillColor(sf::Color::White);
	pos = first_pos;
}
sf::Drawable* Retangle::getElement() const {
	return shape;
}
Vector2D Retangle::getPos() const {
	return pos;
}
void Retangle::updateRelativePos(Vector2D global_pos) {
	Vector2D absotulePos = pos + global_pos ;
	shape->setPosition(absotulePos.getX() , absotulePos.getY());

}
void Retangle::setPos(Vector2D new_pos) {
	pos = new_pos;
	//shape->setPosition(pos.getX(), pos.getY());
}
