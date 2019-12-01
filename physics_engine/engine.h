#pragma once
#include "object.h"
#include <vector>

class Engine
{
public:
	Engine(double finalTime, double timeStep);
	void addRectangle(v2 position, v2 speed, double height, double width);
	void addCircle(v2 position, v2 speed, double radius);
	void update();
	inline double getTime() { return time; };
	inline std::vector<Rectangle> getRectangle() { return rectangles; };
	inline std::vector<Circle> getCircle() { return circles; };
	std::vector<v2> getParticlesPosition();

private:
	std::vector<Rectangle> rectangles;
	std::vector<Circle> circles;
	double time;
	double finalTime;
	double timeStep;
	double gravityConst;
};

