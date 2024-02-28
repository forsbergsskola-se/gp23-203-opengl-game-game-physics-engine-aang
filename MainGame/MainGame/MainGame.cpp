#include <iostream>
#include "glad/glad.h"
#include "Window.h"
#include "GLFW/glfw3.h"
using namespace std;

int main()
{
	Window window{ 800, 600 };

	while (!window.shouldClose())
	{
		window.processInput();

		window.present();
	}
	glfwTerminate();
	return 0;
}
