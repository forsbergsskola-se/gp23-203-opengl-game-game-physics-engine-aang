#pragma once
#include "GameObject.h"
#include "Vector3.h"
#include <cmath>

struct Collision
{
	bool isColliding(GameObject object1, GameObject object2) {
		float distance = Vector3::Distance(object1.position, object2.position); //Calculate distance between the centers of game objets

		if (distance < object1.radius - object2.radius) {
			return true;
		}
		return false;
	}
};
