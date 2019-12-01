#include "engine.h"
#include <iostream>

Engine::Engine(double finalTime, double timeStep)
	: time(0.0), gravityConst(10.0)
{
	this->finalTime = finalTime;
	this->timeStep = timeStep;
};

void Engine::addRectangle(v2 position, v2 speed, double height, double width)
{
	rectangles.push_back(Rectangle(position, speed, height, width));
}

void Engine::addCircle(v2 position, v2 speed, double radius)
{
	circles.push_back(Circle(position, speed, radius));
}

std::vector<v2> Engine::getParticlesPosition()
{
	std::vector <v2> positions;
	for (size_t i = 0; i < rectangles.size(); i++)
		positions.push_back(rectangles[i].getPosition());
	return positions;
}

void Engine::update()
{
	for (std::size_t i = 0; i < circles.size(); i++)
	{
		v2 new_position =circles[i].getPosition();
		new_position[0] += 0.0;
		new_position[1] += (-0.5) * gravityConst * time * time;
		circles[i].setPosition(new_position);
	}
	time += timeStep;
}
