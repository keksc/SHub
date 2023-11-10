#pragma once

#include <glad/gl.h>

struct Color {
	int r, g, b;
	void clear() {
		glClearColor(r / 255.f, g / 255.f, b / 255.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void use() {
		glColor3ub(r, g, b);
	}
};