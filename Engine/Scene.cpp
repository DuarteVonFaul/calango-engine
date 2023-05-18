#include "Scene.hpp"


void Scene::update() {
	for (const auto& pair : children) {
		pair.second->update();
	}
}

void Scene::addChild(std::string name, Entity* other) {
	this->children[name] = other;

}
Entity* Scene::getEntity(std::string name) {

	return this->children[name];

}


std::list<Entity*> Scene::getEntitys() const {
	std::list<Entity*> components;
	for (const auto& pair : children) {
		components.push_back(pair.second);
	}
	return components;

}