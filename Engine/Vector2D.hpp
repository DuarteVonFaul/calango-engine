#pragma once
class Vector2D {
private:
	float x;
	float y;

public:

	Vector2D(float, float);
	Vector2D();

	float getX();
	float getY();
	void set(Vector2D);
	void set(float, float);
	void setX(float);
	void setY(float);

	Vector2D operator+(Vector2D const& obj);
	Vector2D operator-(Vector2D const& obj);

	void operator+=(Vector2D const& obj);
	void operator-=(Vector2D const& obj);
	
};