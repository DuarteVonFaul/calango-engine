
#include "Area2D.h"




Area2D::Area2D(Vector2D pos) :
	pos(pos)
{
}
Area2D::Area2D(float x, float y) :
	pos(Vector2D(x,y))
{
}


Component* Area2D::getChildren(std::string key) const {

	auto it = myComponents.find(key);
	if (it != myComponents.end()) {
		return it->second;
	}
	return nullptr;
}


void Area2D::addChildren(std::string key, Component* child){
	myComponents[key] = child;
	child->updateRelativePos(pos);
}


std::list<Component*> Area2D::getChildren(
) const {
	std::list<Component*> components;
	for (const auto& pair : myComponents) {
		components.push_back(pair.second);
	}
	return components;
}
void Area2D::setPos(Vector2D const& otherPos) {
	pos = otherPos;
	for (const auto& pair : myComponents) {
		pair.second->updateRelativePos(pos);
	}

}
Vector2D Area2D::getPos() const {
	return pos;
}