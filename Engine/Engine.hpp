#pragma once
#include "Area2D.h"
#include "Retangle.hpp"
#include "Sprite.hpp"
#include "Scene.hpp"
#include "Window.hpp"
#include "Vector2D.hpp"



#define DECLARE_CLASS_WITH_GLOBALS(className, baseClassName, ...) \
class className : public baseClassName { \
public: \
    className(__VA_ARGS__) {} \
    virtual ~className() {} \
    __VA_ARGS__ \
}