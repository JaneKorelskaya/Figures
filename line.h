#pragma once
#include <iostream>
#include "point.h"
#include <cmath>
using namespace std;

#define PI 3.14159265

class Line
{
private:
  Point p1;
  Point p2;
  double alpha;
  double length;
public:
    Line() = default;
    Line (Point, Point);
    Line (Point, double, double);
    double GetAlpha() const;
    Point begin();
    Point end();
    double GetLen() const;
    Point medium();
  friend bool operator== (const Line &, const Line &);
  friend bool operator!= (const Line &, const Line &);
  friend ostream& operator<<(ostream&, const Line&);
  bool isCongurentTo(const Line& l) const;
};

Point intersect_point(Line l1, Line l2);
bool BelongToLine(Point p, Line l); //inside line
bool OnLine(Point p, Line l); //inside line + ends

