#pragma once
#include "Vector3.h"
#include <iostream>
#include "Material.h"
#include "Matrix4x4.h"
#include "Mesh.h"
#include "Texture.h"


using namespace std;

// Gravitational constant
const float G = 6.67430e-11; // m^3 kg^-1 s^-2


class GameObject
{
	const Mesh* mesh;
	Material* material;
	Texture* texture;

public:
	Vector3 position{ 0,0,0 };
	Vector3 rotation{ 0,0,0 };
	Vector3 velocity{ 0,0,0 };
	Vector3 acceleration{ 0,0,0 };
	float color;
	float radius;
	int mass;

	
	//Construct
	GameObject(Material* _material, const Mesh* _mesh, Texture* _texture = nullptr) : material(_material), mesh(_mesh), texture(_texture) {};



	// Apply force to the Rigidbody(Gameobejct)
	void applyForce(Vector3 force) {
		// (F = ma) ==> (a = F / m)
		acceleration.x += force.x / mass;
		acceleration.y += force.y / mass;
		acceleration.z += force.z / mass;
	}

	// Update position
	void UpdateAfterCollision(float time) {
		Vector3 accAfterTime = acceleration * time;
		Vector3 velAfterTime = velocity * time;

		this->position = position + velAfterTime + 0.5f * accAfterTime * time;
		this->velocity = velocity + acceleration * time;
	}

	// Calculate gravitational force between two GameObjects
	Vector3 calculateGravitationalForce(const GameObject& other) {
		// Calculate distance between the two objects
		Vector3 direction = other.position - this->position;
		float distance = direction.magnitude();

		// Avoid division by zero
		if (distance == 0) {
			return Vector3(0, 0, 0);
		}

		// Calculate gravitational force magnitude
		float forceMagnitude = (G * this->mass * other.mass) / (distance * distance);

		// Normalize direction vector
		direction.normalize();

		// Calculate gravitational force vector
		Vector3 gravitationalForce = direction * forceMagnitude;

		return gravitationalForce;
	}

	// Apply gravitational force from another GameObject
	void applyGravitationalForce(const GameObject& other) {
		Vector3 gravitationalForce = calculateGravitationalForce(other);
		applyForce(gravitationalForce);
	}

	void render() {

		material->use();

		int tintLocation = glGetUniformLocation(
			material->ShaderProgram, "tintColor");
		glUniform4f(tintLocation, color, 0, 0, 1);
  
		Matrix4x4 matTranslation = Matrix4x4::Translation(position);
		Matrix4x4 matRotation = Matrix4x4::Rotation(rotation);

		Matrix4x4 transform = matTranslation * matRotation;

		int transformLocation = glGetUniformLocation(
			material->ShaderProgram, "transform");
		glUniformMatrix4fv(transformLocation, 1, GL_TRUE, &transform.m11);

		int diffuseLocation = glGetUniformLocation(
			material->ShaderProgram, "diffuseTexture");
		glUniform1i(diffuseLocation, 0);

		glActiveTexture(GL_TEXTURE0);

		if (texture != nullptr) {
			glBindTexture(GL_TEXTURE_2D, texture->textureID);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, 0);
		}

		int blendLocation = glGetUniformLocation(
			material->ShaderProgram, "blendTexture");
		glUniform1i(blendLocation, 1);

		mesh->render();
	}
};