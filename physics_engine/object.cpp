#include "object.h"

Object::Object(v2 position, v2 speed, double mass)
	: position(position), init_position(position), speed(speed), init_speed(speed), mass(mass)
{}

void Object::write(std::unique_ptr<std::ofstream>& ptr_stream) {
	*ptr_stream << position[0] << "," << position[1] << ","
		<< speed[0] << "," << speed[1] << ",";
}

double Object::mechanical_energy(double gravityConstant) {
	return 0.5 * mass * (speed * speed) + mass * gravityConstant * position[1];
}

Rectangle::Rectangle(v2 position, v2 speed, double mass, double height, double width)
	: Object(position, speed, mass) {
	this->height = height;
	this->width = width;
}

void Rectangle::draw()
{
	drawRectangle(position[0] + SCREEN_WIDTH / 2.0, position[1] + SCREEN_HEIGHT / 2.0, 0.0, height, width);
}

Circle::Circle(v2 position, v2 speed, double mass, double radius)
	: Object(position, speed, mass) {
	this->radius = radius;
}

void Circle::draw()
{
	drawCircle(position[0] + SCREEN_WIDTH / 2.0, position[1] + SCREEN_HEIGHT / 2.0, 0.0, radius);
}
