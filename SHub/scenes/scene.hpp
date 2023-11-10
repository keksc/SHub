#pragma once

class Scene {
public:
	virtual void draw(GLFWwindow* window) {};
	virtual void key(GLFWwindow* window, int key, int scancode, int action, int mods) {};
	virtual void mouse(GLFWwindow* window, int button, int action, int mods) {};
	virtual void mousePos(GLFWwindow* window, double xpos, double ypos) {};
};