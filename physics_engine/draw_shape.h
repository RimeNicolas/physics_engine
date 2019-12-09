#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <array>
#include <GL/glew.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void drawCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius);
void drawQuad(float vertices[]);
void drawRectangle(float x, float y, float z = 0.0f, float height = 1.0f, float width = 1.0f);
