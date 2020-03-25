#pragma once
#include "polygon.h"
#include "point.h"
#include "line.h"
using namespace std;

class Rectangle : public Polygon {
public:
	//Rectangle() = default;
	Rectangle(Point, Point, double);
	Point center() const; 
	pair<Line, Line> diagonals() const;  
};
vector<Point> MakeRectToPol(Point _p1, Point _p3, double at);


