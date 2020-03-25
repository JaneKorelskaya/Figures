#include "rectangle.h"
#include "line.h"

using namespace std;

vector<Point> MakeRectToPol(Point _p1, Point _p3, double at) {
	double a, b, d;
        d = Line(_p1 , _p3).GetLen();
	double d_alph = 180 - Line(_p1, _p3).GetAlpha();
        a = d / sqrt(1 + at * at);
        b = at * a;
	//cout << a << " " << b << endl;
        Point p2, p4;
        double a_alph = Line(_p1, _p3).GetAlpha() + (180 / PI * atan(b / a));
	Line l1(Line(_p1, _p3).medium(), d_alph, d / 2);
	p2 = l1.end();
	p4 = Line(p2, d_alph - 180, d).end();
        return { _p1, p2, _p3, p4 };
}


Rectangle::Rectangle(Point _p1, Point _p2, double attitude) : Polygon(MakeRectToPol(_p1, _p2, attitude)) {}

pair<Line, Line> Rectangle::diagonals() const {
	return {Line(getVertices().at(0), getVertices().at(2)), Line(getVertices().at(1), getVertices().at(3))};
}

Point Rectangle::center() const {
	return Line(getVertices().at(0), getVertices().at(2)).medium();
}


