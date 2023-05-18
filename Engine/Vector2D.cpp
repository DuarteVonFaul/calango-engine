#include "Vector2D.hpp"

Vector2D::Vector2D(float X, float Y) {
	this->x = X;
	this->y = Y;
}

Vector2D::Vector2D() {
	this->x = 0;
	this->y = 0;
}
float Vector2D::getX() {
	return this->x;
}
float Vector2D::getY() {
	return this->y;
}
void Vector2D::set(Vector2D other) {
	this->x = other.getX();
	this->y = other.getY();
}
void Vector2D::set(float X, float Y) {
	this->x = X;
	this->y = Y;
}
void Vector2D::setX(float X) {
	this->x = X;
}
void Vector2D::setY(float Y) {
	this->y = Y;
}

Vector2D Vector2D::operator+(Vector2D const& other) {
	return Vector2D(this->x + other.x, this->y + other.y);
}
Vector2D Vector2D::operator-(Vector2D const& other) {
	return Vector2D(this->x - other.x, this->y - other.y);
}

void Vector2D::operator+=(Vector2D const& other) {
	this->x += other.x;
	this->y += other.y;
}
void Vector2D::operator-=(Vector2D const& other) {
	this->x = other.x;
	this->y = other.y;
}