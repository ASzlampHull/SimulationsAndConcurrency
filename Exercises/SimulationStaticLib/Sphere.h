#pragma once
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"


class Sphere {
public:
	float radius = 10.0f;
	float mass = 1.0f;
	glm::vec3 center = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 velocity = glm::vec3(0.0f, 0.0f, 0.0f);

	Sphere(double radius_, glm::vec3 center_, glm::vec3 velocity_, float mass_)
		: radius(radius_), center(center_), velocity(velocity_), mass(mass_) {	}
	~Sphere() = default;

	bool IsInside(double point);
	void CollisionResponseToStationary(Sphere& other);
	glm::vec3 ProcessOfCollision(Sphere& other);
};
