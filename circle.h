#pragma once 
#include "ellipse.h"

class Circle : public Ellipse {
private:
	double rad;
public:
	Circle(Point, double);
	double radius() const;
};
