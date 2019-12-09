#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <chrono>
#include <ctime>
#include <string>
#include <thread>
#include <fstream>

#include "draw_shape.h"
#include "engine.h"

class OpenGLContext {
public:
	OpenGLContext(std::string filePath = "");
	~OpenGLContext();
	int initOpenGL();
	void draw(Engine& engine);
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
private:
	GLFWwindow* window;
	std::string filePath;
	std::unique_ptr<std::ofstream> ptr_ofstream;
};