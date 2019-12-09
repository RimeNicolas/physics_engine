#pragma once
#include "object.h"
#include <vector>

class Engine {
public:
	Engine(double finalTime, double timeStep);
	void addRectangle(v2 position, v2 speed, double mass, double height, double width);
	void addCircle(v2 position, v2 speed, double mass, double radius);
	void initEngine();
	void update();
	void update_analytics();
	inline double getTime() { return time; };
	inline double getFinalTime() { return finalTime; };
	inline double getTimeStep() { return timeStep; }
	// inline std::vector<Object> getObject() { return objects; };
	// std::vector<v2> getObjectPosition();
	void write(std::unique_ptr<std::ofstream>& ptr_stream);
	void draw();
	double mechanical_energy();

private:
	std::vector<std::unique_ptr<Object>> objects;
	double time;
	double finalTime;
	double timeStep;
	double gravityConst;
};

