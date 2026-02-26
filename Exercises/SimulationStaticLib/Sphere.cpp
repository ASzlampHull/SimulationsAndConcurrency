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

// This function calculates the new orientation of the sphere based on its angular velocity and the time step.
glm::mat4 Sphere::AngularVelocityNewOrientation(glm::vec3 angularVelocity, float deltaTime)
{
	// Calculate the magnitude of angular velocity (angular speed in rad/s)
	float angularSpeed = glm::length(angularVelocity);

	// If angular speed is negligible, no rotation occurs
	if (angularSpeed < 0.0001f)
		return orientation;

	// Get the axis of rotation (normalized angular velocity vector)
	glm::vec3 rotationAxis = glm::normalize(angularVelocity);

	// Calculate the angle to rotate during this time step (angle = angular speed × time)
	float rotationAngle = angularSpeed * deltaTime;

	// Create an incremental rotation matrix
	glm::mat4 incrementalRotation = glm::rotate(glm::mat4(1.0f), rotationAngle, rotationAxis);

	// Apply the incremental rotation to the current orientation
	glm::mat4 newOrientation = incrementalRotation * orientation;

	// Update and return the new orientation
	orientation = newOrientation;
	return newOrientation;
}

