#include "circle.h"

Circle::Circle(Point _c, double _r) : Ellipse(_c, _c, _r * 2), rad(_r) {}

double Circle::radius() const {
	return rad;
}

