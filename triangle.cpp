#include "triangle.h"

using namespace std;
double makealpha(double x) {
	if (x > 90)
		return x - 90;
	return x + 90;
}

Triangle::Triangle(Point p1, Point p2, Point p3) : Polygon({p1, p2, p3}) {} 

Circle Triangle::csCircle() const {
	double radius = (getSides().at(0).GetLen() * getSides().at(1).GetLen() 
			* getSides().at(2).GetLen()) / (4 * area());
	
	Line l1(getSides().at(0).medium(), makealpha(getSides().at(0).GetAlpha()), radius);
	Line l2(getSides().at(1).medium(), makealpha(getSides().at(1).GetAlpha()), radius);
	return Circle(intersect_point(l1, l2), radius);
}

pair<Line, Line> Triangle::MakeBiss() const {
	Line biss1 = Line(getVertices().at(1), (getSides().at(0).GetAlpha() + getSides().at(1).GetAlpha()) / 2, 1);
	Line biss2 = Line(getVertices().at(2), (getSides().at(1).GetAlpha() + getSides().at(2).GetAlpha()) / 2, 1);
        if (!BelongToLine(intersect_point(getSides().at(2), biss1), getSides().at(2))) {
              biss1 = Line(getVertices().at(1), (getSides().at(0).GetAlpha() + getSides().at(1).GetAlpha()) / 2 + 90, 1);

        } 
        if (!BelongToLine(intersect_point(getSides().at(0), biss2), getSides().at(0))) {
              biss2 = Line(getVertices().at(2), (getSides().at(1).GetAlpha() + getSides().at(2).GetAlpha()) / 2 + 90, 1);

        }
	return {biss1, biss2};
}
			
Circle Triangle::insCircle() const {
	double p = perimetr() / 2;
	double radius = sqrt((p - getSides().at(0).GetLen()) * (p - getSides().at(1).GetLen()) * (p - getSides().at(2).GetLen()) / p);
	return Circle(intersect_point(MakeBiss().first, MakeBiss().second), radius);
}
Point Triangle::centroid() const {
	Line m1(getVertices().at(0), getSides().at(1).medium());
	Line m2(getVertices().at(1), getSides().at(2).medium());
	return intersect_point(m1, m2);
}


Point Triangle::orthocenter() const {
	Line l0(getVertices().at(0), getSides().at(1).GetAlpha() + 90, 1);
        Line l1(getVertices().at(1), getSides().at(2).GetAlpha() + 90, 1);
        return intersect_point(l1, l0);
}

Line Triangle::EulerLine() const {
       return Line(csCircle().center(), orthocenter()); 
}       

Circle Triangle::ninePointsCircle() const {
	return Circle(EulerLine().medium(), csCircle().radius() / 2);
} 




