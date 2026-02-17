#include "pch.h"
#include "../SimulationStaticLib/Sphere.h"

TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(IsInside, BasicCentreInside) {
	/* Your code to set up the sphere and point */

	Sphere sphere(10.0f, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 1.0f);

	// check result is true
	EXPECT_TRUE(sphere.IsInside(3.0));
}

TEST(ProcessOfCollision, BasicCollision) {
	/* Your code to set up the spheres and their velocities */
	Sphere sphere1(10.0f, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), 1.0f);
	Sphere sphere2(10.0f, glm::vec3(20.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 1.0f);
	glm::vec3 newVelocity = sphere2.ProcessOfCollision(sphere1);
	// check result is as expected
	EXPECT_EQ(newVelocity.x, 1.0f);
	EXPECT_EQ(newVelocity.y, 0.0f);
	EXPECT_EQ(newVelocity.z, 0.0f);
}

TEST(ProcessOfCollision, DifferentMasses) {
	/* Your code to set up the spheres with different masses and velocities */
	Sphere sphere1(10.0f, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), 2.0f);
	Sphere sphere2(10.0f, glm::vec3(20.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 1.0f);
	glm::vec3 newVelocity = sphere2.ProcessOfCollision(sphere1);
	// check result is as expected
	EXPECT_EQ(newVelocity.x, 1.33333333f);
	EXPECT_EQ(newVelocity.y, 0.0f);
	EXPECT_EQ(newVelocity.z, 0.0f);
}