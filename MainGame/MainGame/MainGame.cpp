#include <iostream>
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "Window.h"
#include "Vector3.h"
#include "GameObject.h"
#include "Shader.h"
#include "Material.h"
using namespace std;

void processInput(GLFWwindow*);

int main()
{
	//Setup
	Window window{ 800, 600 };

	Texture basketball{ "basketball.jpg", GL_TEXTURE0 };
	Shader vertexShader{ "vertexShader.glsl", GL_VERTEX_SHADER};
	Shader yellowShader{ "yellowFragmentShader.glsl", GL_FRAGMENT_SHADER };
	
	//Pipeline
	Material yellow{ vertexShader, yellowShader };

	//Setup Game Object (Player Circle)
	GameObject player{ &yellow, Mesh::createQuad() };
	player.color = 1;
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