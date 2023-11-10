#pragma once

#include "scene.hpp"
#include <utils/rect.hpp>
#include <utils/color.hpp>

class MainMenu : public Scene {
	Rect sidebar = { 1.0f, 1.0f, 1.5f, -1.0f };
	Color clearColor = { 0, 27, 121 };
	Color sidebarColor = { 22, 64, 214 };
public:
	void draw(GLFWwindow* window) override {
		clearColor.clear();
		sidebarColor.use();
		sidebar.draw();
		if (sidebar.x1 >= -1.0f)
		{
			if (sidebar.x1 <= -0.85f)
			{
				sidebar.x1 -= 0.03f;
				sidebar.x2 -= 0.03f;
			}
			else
			{
				sidebar.x1 -= 0.07f;
				sidebar.x2 -= 0.075f;
			}
		}
	}

	void key(GLFWwindow* window, int key, int scancode, int action, int mods) override {

	}

	void mouse(GLFWwindow* window, int button, int action, int mods) override {

	}

	void mousePos(GLFWwindow* window, double xpos, double ypos) override {

	}
};