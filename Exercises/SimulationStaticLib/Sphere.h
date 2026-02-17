#pragma once
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"


class Sphere {
private:
	double radius = 10.0;
	glm::vec3 center = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 velocity = glm::vec3(0.0f, 0.0f, 0.0f);

public:
	Sphere(double radius_, glm::vec3 center_, glm::vec3 velocity_)
		: radius(radius_), center(center_), velocity(velocity_) {}
	~Sphere() = default;

	double getRadius() const;
	bool IsInside(double point);
};
