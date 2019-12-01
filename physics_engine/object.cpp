#include "object.h"

Rectangle::Rectangle(v2 position, v2 speed, double height, double width) {
	this->position = position;
	this->speed = speed;
	this->height = height;
	this->width = width;
}

Circle::Circle(v2 position, v2 speed, double radius) {
	this->position = position;
	this->speed = speed;
	this->radius = radius;
}
