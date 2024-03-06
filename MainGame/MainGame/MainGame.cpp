#include <iostream>
#include "glad/glad.h"
#include "Window.h"
#include "GLFW/glfw3.h"
#include "Vector3.h"
#include "GameObject.h"
#include "Shader.h"

using namespace std;

void processInput(GLFWwindow*);

int main()
{
	//Setup
	Window window{ 800, 600 };

	Shader vertexShader{ "vertexShader.glsl", GL_VERTEX_SHADER};
	Shader yellowShader{ "yellowFragmentShader.glsl", GL_FRAGMENT_SHADER };
	 

	//Setup Game Object (Player Circle)
	GameObject Player{ Vector3{0,0,0}, Vector3{0,0,0}, Vector3{0,0,0}, 50};
	GameObject Enemy{ Vector3{0.5,0.5,0.5}, Vector3{0.5,0.5,0.5}, Vector3{0.5,0.5,0.5}, 50};
	//Ground
	

	//Setting up physics
	//Gravitational force
	Vector3 gravity{0, -9.81f, 0};


	//OpenGL window startup, end when pressed [ESC]
	while (!window.shouldClose())
	{
		window.processInput();

		window.clear();

		window.present();
	}
	glfwTerminate();
	return 0;
}

//https://www.toptal.com/game/video-game-physics-part-i-an-introduction-to-rigid-body-dynamics