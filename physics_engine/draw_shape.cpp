#include "draw_shape.h"

void drawCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius)
{
	const GLint numberOfSides = 100;
	const GLint numberOfVertices = numberOfSides + 2;

	GLfloat twicePi = 2.0f * M_PI;

	GLfloat circleVerticesX[numberOfVertices];
	GLfloat circleVerticesY[numberOfVertices];
	GLfloat circleVerticesZ[numberOfVertices];

	circleVerticesX[0] = x;
	circleVerticesY[0] = y;
	circleVerticesZ[0] = z;

	for (int i = 1; i < numberOfVertices; i++)
	{
		circleVerticesX[i] = x + (radius * cos(i * twicePi / numberOfSides));
		circleVerticesY[i] = y + (radius * sin(i * twicePi / numberOfSides));
		circleVerticesZ[i] = z;
	}

	GLfloat allCircleVertices[(numberOfVertices) * 3];

	for (int i = 0; i < numberOfVertices; i++)
	{
		allCircleVertices[i * 3] = circleVerticesX[i];
		allCircleVertices[(i * 3) + 1] = circleVerticesY[i];
		allCircleVertices[(i * 3) + 2] = circleVerticesZ[i];
	}

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, allCircleVertices);
	glDrawArrays(GL_TRIANGLE_FAN, 0, numberOfVertices);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void drawQuad(float vertices[]) {
	glEnableClientState(GL_VERTEX_ARRAY); // tell OpenGL that you're using a vertex array for fixed-function attribute
	glVertexPointer(3, GL_FLOAT, 0, vertices); // point to the vertices to be used
	glDrawArrays(GL_QUADS, 0, 4); // draw the vertixes
	glDisableClientState(GL_VERTEX_ARRAY); // tell OpenGL that you're finished using the vertex arrayattribute
}

void drawRectangle(float x, float y, float z, float height, float width) {
	float vertices[] =
	{
		x + width/2.0, y + height/2.0, z, // top right corner
		x - width/2.0, y + height/2.0, z, // top left corner
		x - width/2.0, y - height/2.0, z, // bottom left corner
		x + width/2.0, y - height/2.0, z  // bottom right corner
	};
	drawQuad(vertices);
}
