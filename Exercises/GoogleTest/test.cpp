#include "pch.h"
#include "../SimulationStaticLib/Sphere.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(IsInside, BasicCentreInside) {
	/* Your code to set up the sphere and point */

	Sphere sphere(10.0);

	// check result is true
	EXPECT_TRUE(sphere.IsInside(3.0));
}