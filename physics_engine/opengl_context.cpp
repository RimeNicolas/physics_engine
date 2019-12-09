#include "opengl_context.h"
#include "engine.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

OpenGLContext::OpenGLContext(std::string filePath)
	: window(nullptr), filePath(filePath), ptr_ofstream(new std::ofstream())
{
	if (filePath != "") {
		ptr_ofstream->open(filePath);
		}
	else {
		this->ptr_ofstream = nullptr;
	}
}
	
OpenGLContext::~OpenGLContext() {
	if (filePath != "") { ptr_ofstream->close(); }
	glfwTerminate();
}

int OpenGLContext::initOpenGL() {
	// Initialize the library
	if (!glfwInit())
	{
		return -1;
	}

	// Create a windowed mode window and its OpenGL context
	this->window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Physics Engine", NULL, NULL);

	if (!this->window)
	{
		glfwTerminate();
		return -1;
	}

	// Make the window's context current
	glfwMakeContextCurrent(this->window);

	glfwSetKeyCallback(this->window, keyCallback);
	glfwSetInputMode(this->window, GLFW_STICKY_KEYS, 1);

	glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
	glMatrixMode(GL_PROJECTION); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
	glLoadIdentity(); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1); // essentially set coordinate system
	glMatrixMode(GL_MODELVIEW); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
	glLoadIdentity(); // same as above comment
}

void OpenGLContext::draw(Engine& engine) {
	double dt(engine.getTimeStep());
	std::chrono::time_point<std::chrono::system_clock> start;
	start = std::chrono::system_clock::now();
	double t_update(dt * 1000); //milliseconds
	double t_draw(2 * t_update); //milliseconds

	// Loop until the user closes the window
	while (!glfwWindowShouldClose(this->window) && t_update <= 1000*engine.getFinalTime())
	{
		if ((std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start)).count() >= t_draw)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			
			// render OpenGL here
			engine.draw();
			if (filePath != "") { engine.write(this->ptr_ofstream); }

			// Swap front and back buffers
			glfwSwapBuffers(this->window);

			t_draw += 2 * dt * 1000;
		}
		
		if ((std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start)).count() >= t_update)
		{
			engine.update_analytics();
			// engine.update();
			double elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>
				(std::chrono::system_clock::now() - start).count();
			std::cout << "elapsed time: " << elapsed_seconds << " ms\n";
			t_update += dt * 1000;
		}
		
		// Poll for and process events
		glfwPollEvents();
	}
}

void OpenGLContext::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	// std::cout << key << std::endl;

	// actions are GLFW_PRESS, GLFW_RELEASE or GLFW_REPEAT
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
	{
		std::cout << "Space Key Pressed" << std::endl;
	}
}
