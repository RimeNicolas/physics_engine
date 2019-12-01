#include "draw_opengl.h"
#include <thread>
#include "engine.h"

int draw_opengl()
{
	GLFWwindow* window;

	// Initialize the library
	if (!glfwInit())
	{
		return -1;
	}

	// Create a windowed mode window and its OpenGL context
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// Make the window's context current
	glfwMakeContextCurrent(window);

	glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
	glMatrixMode(GL_PROJECTION); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
	glLoadIdentity(); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1); // essentially set coordinate system
	glMatrixMode(GL_MODELVIEW); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
	glLoadIdentity(); // same as above comment

	float vertices[] =
	{
		300, 300, 0.0, // top right corner
		0, 300, 0.0, // top left corner
		0, 0, 0.0, // bottom left corner
		300, 0, 0.0 // bottom right corner
	};

	double dt(0.01);
	Engine engine(10.0, dt);
	engine.addCircle({ 0,0 }, { 0,0 }, 100);

	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();

	// Loop until the user closes the window
	while (!glfwWindowShouldClose(window))
	{
		if ((std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - start)).count() > 16.0*dt)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			
			std::vector<Circle> circles = engine.getCircle();
			v2 position = circles[0].getPosition();
			double radius = circles[0].getRadius();
			
			// render OpenGL here
			drawCircle(position[0] + SCREEN_WIDTH / 2.0, position[1] + SCREEN_HEIGHT / 2.0, 0.0, radius);
			
			// Swap front and back buffers
			glfwSwapBuffers(window);

			double elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
				(std::chrono::system_clock::now() - start).count();
			std::cout << "elapsed time: " << elapsed_seconds << "s\n";
			std::cout << position[0] << "\n";
			std::cout << position[1] << "\n";
		}
		
		if ((std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - start)).count() > dt)
		{
			engine.update();
		}
		
		// Poll for and process events
		glfwPollEvents();

	}

	glfwTerminate();
}