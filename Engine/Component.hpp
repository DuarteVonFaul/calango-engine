#pragma once
#include <SFML/Graphics.hpp>
class Component {
public:
	virtual sf::Drawable* getElement() const = 0;
};