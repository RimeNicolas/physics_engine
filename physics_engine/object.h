#pragma once
#include <array>

typedef std::array<double, 2> v2;

class Rectangle {
public:
	Rectangle(v2 position, v2 speed, double height, double width);
	inline v2 getPosition() { return this->position; }
	inline v2 getSpeed() { return this->speed; }
	inline double getHeight() { return this->height; }
	inline double getWidth() { return this->width; }

	inline void setPosition(v2 new_position) { position = new_position; };
private:
	v2 position;
	v2 speed;
	double height;
	double width;
};

class Circle {
public:
	Circle(v2 position, v2 speed, double radius);
	inline v2 getPosition() { return this->position; }
	inline v2 getSpeed() { return this->speed; }
	inline double getRadius() { return this->radius; }

	inline void setPosition(v2 new_position) { position = new_position; };
private:
	v2 position;
	v2 speed;
	double radius;
};