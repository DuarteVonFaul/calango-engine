#include "Sprite.hpp"


Sprite::Sprite(std::string path, Vector2D first_pos) {



	shape = new sf::Sprite();
	texture = new sf::Texture();
	sf::IntRect frameRect(0, 0, 52, 52);
	if (this->texture->loadFromFile(path)) {
		shape->setTexture(*texture);
		shape->setTextureRect(frameRect);
	}
	pos = first_pos;
	shape->setPosition(pos.getX(), pos.getY());


}

sf::Drawable* Sprite::getElement() const {
	return shape;
}
void Sprite::updateRelativePos(Vector2D global_pos) {
	Vector2D absotulePos = pos + global_pos;
	shape->setPosition(absotulePos.getX(), absotulePos.getY());
}


void Sprite::setPos(Vector2D new_pos) {
	pos = new_pos;
}
Vector2D Sprite::getPos() {
	return pos;
}