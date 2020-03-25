#include "line.h" 
#include "point.h"
#include <cmath> 

Line::Line (Point _p1, Point _p2) : p1(_p1), p2(_p2)
{
  
  length = sqrt (pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
  if (p1 == p2) 
	  alpha = 0;
  else if (p1.y == p2.y) {
	  if(p2.x > p1.x) 
		  alpha = 0;
	  else 
		  alpha = 180; 
  }
  else {
  	alpha = 180 / PI * atan((p2.y - p1.y) / (p2.x - p1.x)); 
	if /*(p2.x > p1.x && p1.y > p2.y) ||*/ (p1.x > p2.x && p1.y > p2.y)
                  alpha = abs(alpha) - 180;
  }
  if (abs(alpha - 0) < 0.00001)
          alpha = 0;

}

Line::Line (Point p, double _alpha, double _length):
 length(_length), p1(p) {
  alpha = _alpha;
  if (abs(alpha - 0) < 0.00001)
      alpha = 0;
  p2.x = p1.x + length * cos(alpha * PI / 180);
  if (abs(p2.x - 0) < 0.00001)
      p2.x = 0;
  p2.y = p1.y + length * sin(alpha * PI / 180);
  if (abs(p2.y - 0) < 0.00001)
      p2.y = 0;


}
bool Line::isCongurentTo(const Line& l) const {
        return length == l.length;
}

bool operator == (const Line& l1, const Line& l2) {
        return l1.p1 == l2.p1 && l1.p2 == l2.p2;
}
bool operator != (const Line& l1, const Line& l2) {
        return !(l1 == l2);
}

ostream& operator<<(ostream& os, const Line& l) {

	os << "start: " << l.p1.x << " " << l.p1.y <<
		", end: " << l.p2.x << " " << l.p2.y << 
		", length: " << l.length << ", alpha: " <<
		l.alpha << endl;
	return os;
}

double Line::GetAlpha() const {
	return alpha;
}
Point Line::begin() {
	if (abs(p1.y - 0) < 0.00001) 
		p1.y = 0;
	if (abs(p1.x - 0) < 0.00001)
                p1.x = 0;       
	return p1; 
}
Point Line::end() {
        if (abs(p2.y - 0) < 0.00001) 
                p2.y = 0;
        if (abs(p2.x - 0) < 0.00001)
                p2.x = 0;
	return p2;
}
double Line::GetLen() const {
	return length;
}
Point intersect_point(Line l1, Line l2) {
        try {
	if (l1.end().x == l1.begin().x && l2.end().x == l2.begin().x) {
		//cout << "1" << endl;
		throw invalid_argument("k1 == k2, lines doesn't intersect");
	}
	else if(l1.end().x == l1.begin().x) {
		//cout << "2" << endl;
		double k2 = (l2.end().y - l2.begin().y) / (l2.end().x - l2.begin().x  + 0.00001);
        	double b2 = l2.end().y - k2 * l2.end().x;
		return Point(l1.end().x, k2 * l1.end().x + b2);
	}
	else if(l2.end().x == l2.begin().x) {
		//cout << "1" << endl;
        	double k1 = (l1.end().y - l1.begin().y) / (l1.end().x - l1.begin().x + 0.00001);
		double b1 = l1.end().y - k1 * l1.end().x;
                return Point(l2.end().x, k1 * l2.end().x + b1);
        }


        double k1 = (l1.end().y - l1.begin().y) / (l1.end().x - l1.begin().x);
        double b1 = l1.end().y - k1 * l1.end().x;
        double k2 = (l2.end().y - l2.begin().y) / (l2.end().x - l2.begin().x);
        double b2 = l2.end().y - k2 * l2.end().x;
        if(k1 == k2)
                throw invalid_argument("k1 == k2, lines doesn't intersect");
        else {
                return Point((b2 - b1) / (k1 - k2), (k1 *(b2 - b1) / (k1 - k2)) + b1);
        }
        } catch(invalid_argument& inv) {
                cout << inv.what() << endl;
		return Point(1000000, 1000000);
        }
}

Point Line::medium() {
	if (p1 == p2)
		return p1;
	return Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
}

bool BelongToLine(Point p, Line l) {
	Line l2(l.begin(), p);
	if (l2.GetAlpha() != l.GetAlpha())
		return false;
	if ((l.begin().x < p.x && l.end().x > p.x) || (l.begin().x > p.x && l.end().x < p.x)) 
		return true;
	return false;
}

bool OnLine(Point p, Line l) {
	if(BelongToLine(p, l) || (p == l.begin()) || (p == l.end()))
		return true;
	return false;
}
