#pragma once

#include <glad/gl.h>

struct Rect {
	float x1, y1, x2, y2;
	void draw() {
		glRectf(x1, y1, x2, y2);
	}
};