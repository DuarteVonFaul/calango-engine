#pragma once
#include <map>
#include <string>
#include "Entity.hpp"
#include <list>


class Scene {

private:

	std::map<std::string, Entity*> children;


public:
	void update();
	//virtual void tick() = 0;
	void addChild(std::string, Entity*);
	Entity* getEntity(std::string);
	std::list<Entity*> getEntitys() const;

};