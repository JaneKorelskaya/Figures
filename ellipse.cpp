#include "ellipse.h" 

using namespace std;

Ellipse::Ellipse(Point p1, Point p2, double _d) : dist(_d) { 
	focus_1.x = p1.x;
	focus_1.y = p1.y;
        focus_2.x = p2.x;
        focus_2.y = p2.y;	
	a = dist / 2;
	b = sqrt(pow(a, 2) - pow(Line(p1, p2).GetLen() / 2, 2));
} 

pair<Point, Point> Ellipse::focuses() const {
	return {focus_1, focus_2};
} 

double Ellipse::eccentricity() const {
	if (focus_1 == focus_2)
		return 0;
	return Line(focus_1, focus_2).GetLen() / dist;
}

Point Ellipse::center() const {
	if (focus_1 == focus_2)
		return focus_1;
	return Line(focus_1, focus_2).medium();
}

double Ellipse::area() const {
	return PI * a * b;
}

double Ellipse::perimetr() const {
	return 4 * (area() + pow(a - b, 2)) / (a + b);
}

bool Ellipse::containsPoint(Point p) const {
	if(Line(focus_1, p).GetLen() + Line(focus_2, p).GetLen() <= dist)
	       return true;
	return false;
} 
bool Ellipse::operator==(const Shape& another) {
	const Ellipse& el = dynamic_cast<const Ellipse&>(another);
	if(abs(el.dist - dist) < 0.000001) {
	      if (el.focus_1 == focus_1 && el.focus_2 == focus_2) {
			return true;
	      }
	      return false;
	}
	return false; 
}
bool Ellipse::isCongurentTo(const Shape& another) const { 
	const Ellipse& el = dynamic_cast<const Ellipse&>(another); 
	//cout << el.dist << " " << dist << endl;
	//cout << el.focus_1 << el.focus_2 << endl;
	//cout << focus_1 << focus_2 << endl;
	
	return (abs(el.a - a) < 0.00001 && abs(el.b - b) < 0.00001);
}
