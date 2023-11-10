#pragma once

#include <glad/gl.h>

struct Rect {
	float a, b, c, d;
	void draw() {
		glRectf(a, b, c, d);
	}
};