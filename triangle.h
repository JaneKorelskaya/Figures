#pragma once 
#include "polygon.h"
#include "ellipse.h"
#include "circle.h"
#include <cmath>
using namespace std;

class Triangle : public Polygon {
public:
        Triangle(Point, Point, Point);
	Circle csCircle() const; 
	Circle insCircle() const;
	Point centroid() const; 
	Point orthocenter() const;
	Line EulerLine() const;
	Circle ninePointsCircle() const;
	pair<Line, Line> MakeBiss() const;
};

double makealpha(double x);


