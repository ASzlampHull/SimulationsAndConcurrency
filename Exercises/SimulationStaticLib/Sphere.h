#pragma once

class Sphere {
private:
	double radius = 10.0;

public:
	Sphere(double radius_) : radius(radius_) {}
	~Sphere() = default;

	double getRadius() const;
	bool IsInside(double point);
};
