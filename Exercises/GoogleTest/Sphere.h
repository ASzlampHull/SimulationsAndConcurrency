#pragma once

static class Sphere
{
private:
	double radius;
public:
	Sphere();
	~Sphere();

	void isPointInside(double point);
};