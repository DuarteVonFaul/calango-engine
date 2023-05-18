#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2D.hpp"
#include <iostream>
class Component {
public:
	virtual sf::Drawable* getElement() const = 0;
	virtual void updateRelativePos(Vector2D global_pos) = 0;
};