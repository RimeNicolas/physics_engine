#include "opengl_context.h"
#include "object.h"
#include "engine.h"

int main(void)
{
	std::string filePath = "../output/analytical.txt";
	//std::string filePath = "../output/numerical.txt";

	double dt(0.01);
	double finalTime(5.0);
	Engine engine(finalTime, dt);
	engine.initEngine();

	OpenGLContext context;
	context.initOpenGL();
	context.draw(engine);
	
	return 0;
}





