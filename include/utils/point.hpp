#pragma once

#include "rect.hpp"

struct Point {
	int x, y;
	virtual void intersects(NdcRect) = 0;
	virtual void intersects(WinRect) = 0;
};

struct NdcPoint : public Point {
	
};