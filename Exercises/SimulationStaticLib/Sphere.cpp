#include "pch.h"
#include "Sphere.h"

bool Sphere::IsInside(double point)
{
	if (point < radius)
		return true;
	return false;
}
