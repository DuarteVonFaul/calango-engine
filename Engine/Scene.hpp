#pragma once
#include <map>
#include <string>
#include "Entity.hpp"


class Scene {

private:

	std::map<std::string, Entity*> children;


public:
	virtual void update() = 0;
	virtual void tick() = 0;
	void addChild(std::string, Entity&);
	Entity* getEntity(std::string);

};