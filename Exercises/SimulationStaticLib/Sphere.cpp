#include "pch.h"
#include "Sphere.h"

bool Sphere::IsInside(double point)
{
	if (point < radius)
		return true;
	return false;
}

void Sphere::CollisionResponseToStationary(Sphere& other)
{
	glm::vec3 incomingVelocityProjection = glm::dot(velocity, other.center - center) / glm::dot(other.center - center, other.center - center) * (other.center - center);

}

// This function calculates the conservation of momentum for a collision between this sphere and another sphere.
// It returns the new velocity of this sphere after the collision.
glm::vec3 Sphere::ProcessOfCollision(Sphere& other)
{
	float minusMass = mass - other.mass;
	float totalMass = mass + other.mass;
	float amplifiedMass = 2 * other.mass;

	glm::vec3 newVelocity = (minusMass / totalMass) * velocity + (amplifiedMass / totalMass) * other.velocity;

	return newVelocity;
}
