#pragma once
#include "rectangle.h"
#include "circle.h"
using namespace std;

class Square : public Rectangle {
//private:
//	Point p1, p2, p3, p4;
public:
	//Square() = default;
	Square(Point, Point);
	Circle csCircle() const;
	Circle insCircle() const;
	//friend ostream& operator<<(ostream&, const Square&);
};
		
