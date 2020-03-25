#include "square.h"
using namespace std;

Square::Square(Point _p1, Point _p2) : Rectangle(_p1, _p2, 1) {}

Circle Square::csCircle() const {
	return Circle(Line(getVertices().at(0), getVertices().at(2)).medium(), 
			Line(getVertices().at(0), getVertices().at(2)).GetLen() / 2);
}

Circle Square::insCircle() const {
        //return Circle(this->center(), Line(p1, p2).GetLen() / 2);
	return Circle(csCircle().center(), Line(getVertices().at(0), getVertices().at(1)).GetLen() / 2);

}

