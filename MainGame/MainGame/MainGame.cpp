#include <iostream>
#include "glad/glad.h"
#include "Window.h"
#include "GLFW/glfw3.h"
#include "Vector3.h"
#include "GameObject.h"

using namespace std;

int main()
{
	//Setup Game Object (Player Circle)
	GameObject Player{ Vector3{0,0,0}, Vector3{0,0,0}, Vector3{0,0,0}, 50};


	//Setting up physics
	//Gravitational force
	Vector3 gravity{0, -9.81f, 0};


	//OpenGL window startup, end when pressed [ESC]
	Window window{ 800, 600 };
	while (!window.shouldClose())
	{
		window.processInput();

		window.present();
	}
	glfwTerminate();
	return 0;
}
