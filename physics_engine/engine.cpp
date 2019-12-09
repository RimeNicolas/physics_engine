#include "engine.h"

Engine::Engine(double finalTime, double timeStep)
	: time(0.0), gravityConst(10.0) {
	this->finalTime = finalTime;
	this->timeStep = timeStep;
};

void Engine::addRectangle(v2 position, v2 speed, double mass, double height, double width) {
	objects.push_back(std::unique_ptr<Rectangle>(new Rectangle(position, speed, mass, height, width)));
}

void Engine::addCircle(v2 position, v2 speed, double mass, double radius) {
	objects.push_back(std::unique_ptr<Circle>(new Circle(position, speed, mass, radius)));
}

void Engine::initEngine() {
	double mass(1.0);
	double a(100.0);
	double b(10.0);
	addCircle({ 0.0, a }, { 0.0, 0.0 }, mass, b);
	//addCircle({ -a, 0.0 }, { -b, 0.0*b }, mass, b);
	// addCircle({ a, 0.0 }, { b, a }, mass, a);
	//addRectangle({ a, 0.0 }, { b, 0.0*b }, mass, b, b);
}

void Engine::update() {
	for (std::size_t i = 0; i < objects.size(); i++)
	{
		v2 vect = { 0.0,-1.0 };
		objects[i]->setSpeed(objects[i]->getSpeed() + timeStep * gravityConst * vect);
		objects[i]->setPosition(objects[i]->getPosition() + timeStep * objects[i]->getSpeed());
		std::cout << "position at time " << time << ": x = " << objects[i]->getPosition()[0] << " y = " << objects[i]->getPosition()[1] << "\n";
	}
	time += timeStep;
}

void Engine::update_analytics() {
	for (std::size_t i = 0; i < objects.size(); i++)
	{
		objects[i]->setSpeed({ objects[i]->getInitSpeed()[0], -gravityConst * time + objects[i]->getInitSpeed()[1] });
		objects[i]->setPosition({ objects[i]->getInitSpeed()[0] * time + objects[i]->getInitPosition()[0], 
			(-0.5) * gravityConst * time * time  + objects[i]->getInitSpeed()[1] * time + objects[i]->getInitPosition()[1] });
		std::cout << "position at time " << time << ": x = " << objects[i]->getPosition()[0] << " y = " << objects[i]->getPosition()[1] << "\n";
	}
	time += timeStep;
}

void Engine::write(std::unique_ptr<std::ofstream>& ptr_stream) {
	for (std::size_t i = 0; i < objects.size(); i++) {
		objects[i]->write(ptr_stream);
	}
	*ptr_stream << mechanical_energy() << "\n";
}

void Engine::draw() {
	for (std::size_t i = 0; i < objects.size(); i++) {
		objects[i]->draw();
	}
}

double Engine::mechanical_energy() {
	double mec_energy(0.0);
	for (std::size_t i = 0; i < objects.size(); i++) {
		mec_energy += objects[i]->mechanical_energy(gravityConst);
	}
	return mec_energy;
}
