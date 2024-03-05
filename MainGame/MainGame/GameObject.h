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
	Vector3 acceleration;
	int mass;
	float radius;

	
	//Construct
	GameObject(Vector3 pos, Vector3 vel, Vector3 acc, float m) :
		position(pos), velocity(vel), acceleration(acc), mass(m) {}

	// Apply force to the Rigidbody(Gameobejct)
	void applyForce(Vector3 force) {
		// (F = ma) ==> (a = F / m)
		acceleration.x += force.x / mass;
		acceleration.y += force.y / mass;
		acceleration.z += force.z / mass;
	}

	//Update position
	void UpdatePosition() {
		
	}


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