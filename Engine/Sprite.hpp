#pragma once
#include "Component.hpp"
#include <string>
class Sprite : public Component {

private:

	sf::Sprite* shape;
	sf::Texture* texture;
	Vector2D pos;

public:
	
	Sprite(std::string, Vector2D);
	
	sf::Drawable* getElement() const;
	void updateRelativePos(Vector2D global_pos);


	void setPos(Vector2D);
	Vector2D getPos();

};