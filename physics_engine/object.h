#pragma once
#include "draw_shape.h"
#include <array>
#include <iostream>
#include <fstream>

typedef std::array<double, 2> v2;

template <class T>
T operator+(const T& a1, const T& a2)
{
	T a;
	for (typename T::size_type i = 0; i < a1.size(); i++)
		a[i] = a1[i] + a2[i];
	return a;
}

template <class T>
T operator*(const double c, const T& a2)
{
	T a;
	for (typename T::size_type i = 0; i < a2.size(); i++)
		a[i] = c * a2[i];
	return a;
}

template <class T>
double operator*(const T& a1, const T& a2)
{
	double a;
	for (typename T::size_type i = 0; i < a2.size(); i++)
		a = a1[i] * a2[i];
	return a;
}

class Object {
public:
	Object(v2 position, v2 speed, double mass);
	virtual ~Object() {	/* std::cout << "object deleted" << "\n"; */}
	inline v2 getPosition() { return this->position; }
	inline v2 getSpeed() { return this->speed; }
	inline v2 getInitPosition() { return this->init_position; }
	inline v2 getInitSpeed() { return this->init_speed; }
	inline void setPosition(v2 new_position) { position = new_position; };
	inline void setSpeed(v2 new_speed) { speed = new_speed; };
	void write(std::unique_ptr<std::ofstream>& ptr_stream);
	virtual void draw() = 0; 
	double mechanical_energy(double gravityConstant);
protected:
	v2 position;
	v2 speed;
	v2 init_position;
	v2 init_speed;
	double mass;
};

class Rectangle : public Object {
public:
	Rectangle(v2 position, v2 speed, double mass, double height, double width);
	inline double getHeight() { return this->height; }
	inline double getWidth() { return this->width; }
	void draw() override;
private:
	double height;
	double width;
};

class Circle : public Object {
public:
	Circle(v2 position, v2 speed, double mass, double radius);
	inline double getRadius() { return this->radius; }
	void draw() override;
private:
	double radius;
};