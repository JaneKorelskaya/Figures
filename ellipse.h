#pragma once
#include "shape.h"
#include "point.h"
#include <cmath> 
#include "line.h"  
using namespace std;

class Ellipse : public Shape {
protected:
	Point focus_1, focus_2;
	double dist;
	double a, b;
public:
	Ellipse(Point, Point, double);
	pair<Point, Point> focuses() const;
	double eccentricity() const;
	Point center() const;
	double perimetr() const;
	double area() const;
	bool containsPoint(Point) const;
	bool operator==(const Shape&);
	bool isCongurentTo(const Shape&) const;
};


