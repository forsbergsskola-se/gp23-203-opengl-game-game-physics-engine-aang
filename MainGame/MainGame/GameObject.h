#pragma once
#include "Vector3.h"
#include <iostream>
#include "GLFW/glfw3.h"

using namespace std;

struct GameObject
{
	//Circles
	Vector3 position;
	Vector3 velocity;
	Vector3 force;
	int mass;
	float radius;

	void renderThisObject() {
		glBegin(GL_TRIANGLE_FAN);
		// Center of the circle
		glVertex2f(0.0f, 0.0f);

		// Calculate vertices for the circle
		for (int i = 0; i <= mass; i++) {
			float theta = 2.0f * 3.1415926f * float(i) / float(mass);
			float x = radius * cosf(theta);
			float y = radius * sinf(theta);
			// Draw the vertex
			glVertex2f(x, y);
		}
		glEnd();
	}

	GameObject AddGameObject(){
		//Insert add object function
	}

	void RemoveObject()
	{
		//Insert remove object function
		//Design Pattern: object pooling?
	}
};