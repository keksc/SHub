#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <rect.hpp>

constexpr int width = 640;
constexpr int height = 360;

void draw(GLFWwindow *window);

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

	//glfwSetKeyCallback(window, key_callback);
	//glfwSetMouseButtonCallback(window, mouse_callback);
	//glfwSetCursorPosCallback(window, cursor_pos_callback);
	//glfwSetWindowSizeCallback(window, window_size_callback);

	glfwMakeContextCurrent(window);
	gladLoadGL(glfwGetProcAddress);
	glfwSwapInterval(1);

	gladLoadGL(glfwGetProcAddress);

	std::cout << "Hello World !!!!!!!!!!!!!!!!!!" << std::endl;

	while (!glfwWindowShouldClose(window))
	{
		draw(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}

void draw(GLFWwindow *window) {
	glClearColor(0.1f, 0.1f, 0.1f, 0.1f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(250, 0, 0);
	Rect rect = {-0.5, -0.5, 0.5, 0.5};
	rect.draw();
	glfwSwapBuffers(window);
}
