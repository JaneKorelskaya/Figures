#pragma once 
#include "shape.h"
#include "point.h"
#include "line.h"
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Polygon : public Shape {
private:
	vector<Point> vertices;
	vector<Line> sides;
public:
	Polygon(vector<Point>);
	Polygon(vector<Line>);
	size_t verticesCount() const;
	vector<Point> getVertices() const;
        vector<Line> getSides() const;	
	bool isConvex(); 
	bool isPolygon(); 
	friend ostream& operator<<(ostream&, const Polygon);
	double perimetr() const;
	double area() const;
	bool containsPoint(Point) const;
	bool operator==(const Shape&);
	bool isCongurentTo(const Shape&) const;
	vector<vector<double>> MakeSortMatrixDist() const; 
}; 
bool isFind(vector<double>& v1, vector<vector<double>> matr);
bool isCong(vector<vector<double>>& v1, vector<vector<double>>& v2);

ostream& operator<<(ostream& os, vector<vector<double>>& v);
ostream& operator<<(ostream&, vector<double>& v);
bool operator==(vector<double>&, vector<double>&);
