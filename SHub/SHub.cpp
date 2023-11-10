#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <utils/rect.hpp>
#include <memory>
#include "winsettings.hpp"
#include "scenes/scene.hpp"
#include "scenes/mainMenu.hpp"

void draw(GLFWwindow *window);
void sizeCallback(GLFWwindow* window, int width, int height);
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouseCallback(GLFWwindow* window, int button, int action, int mods);
void mousePosCallback(GLFWwindow* window, double xpos, double ypos);

std::unique_ptr<Scene> scene;

int main()
{
	if (!glfwInit())
		return -1;

	GLFWwindow* window = glfwCreateWindow(width, height, "SHub", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwSetWindowSizeLimits(window, width, height, GLFW_DONT_CARE, GLFW_DONT_CARE);

	glfwSetKeyCallback(window, keyCallback);
	glfwSetMouseButtonCallback(window, mouseCallback);
	glfwSetCursorPosCallback(window, mousePosCallback);
	glfwSetWindowSizeCallback(window, sizeCallback);

	glfwMakeContextCurrent(window);
	gladLoadGL(glfwGetProcAddress);
	glfwSwapInterval(1);

	gladLoadGL(glfwGetProcAddress);

	glViewport(0, 0, width, height);

	scene = std::make_unique<MainMenu>();

	while (!glfwWindowShouldClose(window))
	{
		draw(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}

void draw(GLFWwindow *window) {
	scene->draw(window);
	glfwSwapBuffers(window);
}

void sizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	draw(window);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void mouseCallback(GLFWwindow* window, int button, int action, int mods)
{
	scene->mouse(window, button, action, mods);
}

static void mousePosCallback(GLFWwindow* window, double xpos, double ypos)
{
	scene->mousePos(window, xpos, ypos);
}