#include "Scene.hpp"




void Scene::addChild(std::string name, Entity& other) {
	this->children.insert(std::make_pair(name, &other));

}
Entity* Scene::getEntity(std::string name) {

	return this->children[name];

}