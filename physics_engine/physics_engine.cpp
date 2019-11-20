#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
	GLFWwindow* window;

	if (!glfwInit())
	{
		return -1;
	}

	window = glfwCreateWindow(640, 480, "Hello", nullptr, nullptr);
	
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
