#pragma once
#include <string>
#include "Component.hpp"
#include "Vector2D.hpp"
#include <list>
class Entity {
public:
	virtual void update() = 0;
	virtual Component* getChildren(std::string) const = 0;
	virtual std::list<Component*> getChildren() const = 0;
	virtual void setPos(Vector2D const&) = 0;
	virtual Vector2D getPos() const = 0;
};