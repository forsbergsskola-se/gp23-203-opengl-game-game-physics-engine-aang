#pragma once
#include <cmath>
class Vector3
{
public:
	float x, y, z;
	Vector3(float x, float y, float z) : x{ x }, y{ y }, z{ z } {};

	//Operation
	//Muliplication
	Vector3 operator*(const Vector3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return Vector3(x, y, z);
	}
	Vector3 operator*(float other) {
		x *= other;
		y *= other;
		z *= other;
		return Vector3{ x, y, z };
	}
	//Addition
	Vector3 operator+(Vector3& const other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return Vector3(x, y, z);
	}
	Vector3 operator+(float other) {
		x += other;
		y += other;
		z += other;
		return Vector3(x, y, z);
	}
	// Subtraction
	Vector3 operator-(const Vector3& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return Vector3(x, y, z);
	}
	Vector3 operator-(float other) {
		x -= other;
		y -= other;
		z -= other;
		return Vector3(x, y, z);
	}
	// Division
	Vector3 operator/(const Vector3& other) {
		x /= other.x;
		y /= other.y;
		z /= other.z;
		return Vector3(x, y, z);
	}
	Vector3 operator/(float other) {
		x /= other;
		y /= other;
		z /= other;
		return Vector3(x, y, z);
	}

	//Return Dot product
	static float Dot(Vector3& one, const Vector3& two) {
		Vector3 resultVector = one * two;
		return one.x + one.y + one.z;
	}

	//Return magnitude
	float magnitude() const {
		return sqrt(x * x + y * y + z * z);
	}

	static float Distance(Vector3& one, Vector3& two) {
		return (one - two).magnitude();
	}
	//Normalize
	Vector3 normalize() {
		return *this / magnitude();
	}

};

