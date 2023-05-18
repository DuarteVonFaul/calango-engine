#pragma once
#include "Entity.hpp"
#include <map>
#include <list>
class Area2D :public Entity {

private:
	std::map<std::string, Component*> myComponents;
	Vector2D pos;

public:
	virtual void update() = 0;
	Area2D(Vector2D);
	Area2D(float, float);
	Component* getChildren(std::string) const;
	void addChildren(std::string key, Component* child);
	std::list<Component*> getChildren() const;
	void setPos(Vector2D const&);
	Vector2D getPos() const;


};