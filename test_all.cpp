#include <iostream>
#include "point.h"
#include "line.h"
#include "shape.h"
#include "polygon.h"
#include "rectangle.h"
#include "square.h"
#include "ellipse.h"
#include "circle.h"
#include "triangle.h"
using namespace std;

void TestPoint() {
	cout << "TestPoint" << endl;
	Point a(1, 2);
	Point b(1.00000001, 2);
	Point c(0, 1);
	cout << "1:\t " << (a == b) << endl;
	cout << "1:\t " << (a != c) << endl;
	cout << "0:\t " << (a != b) << endl;
	cout << "0:\t " << (a == c) << endl;
	cout << endl;
}

void TestLine() {
	cout << "TestLine" << endl;
	{
	Line l1(Point(0, 0), Point(0, 4));
	Line l2(Point(0, 4), Point(0, 0));
	Line l3(Point(0, 0), Point(3, 0));
	Line l4(Point(3, 0), Point(0, 0));
	Line l5(Point(5, 5), Point(0, 0));
	cout << l1 << l2 << l3 << l4 << l5;
	cout << (l1 == l1) << " " << (l1 != l2) << " " << l1.isCongurentTo(l2) << endl;
	}
	{
        Line l1(Point(0, 0), Point(4, 0));
	Line l2(Point(0, 5), Point(5, 0));
        Line l3(Point(0, 0), 0, 3);
        Line l4(Point(3, 0), 180, 3);
        Line l5(Point(5, 5), -135, 7.07107);

	cout << l1 << l2 << l3 << l4 << l5;
	//cout << intersect_point(l3, l4) << endl;
	cout << intersect_point(l2, l5) << endl;
	cout << BelongToLine(Point(4, 0), l1) << " " << OnLine(Point(4,0), l1) << endl;
	cout << l1.medium() << endl;
	}
	//cout << intersect_point(line3, line4) << endl;
	//cout << intersect_point(line1, line4) << endl;
	
}

void TestPolygon() {
	cout << "TestPolygon" << endl;
	Polygon a({ Point(0,0), Point(2,0), Point(2,2), Point(0,2) });
	Polygon c({ Point(0,4), Point(2,4), Point(2,6), Point(0, 6)});
	/*for (auto it : a.getVertices())
                cout << it << " ";
        cout << endl;
	for (auto it : a.getSides()) 
		cout << it << " ";
	cout << endl;

	for (auto it : c.getVertices()) 
		cout << it << " ";
	cout << endl;
        for (auto it : c.getSides())
                cout << it << " ";
        cout << endl;
	*/
	cout << "Is Polygon: " <<  a.isPolygon()  << endl;
	cout << "IsCongurentTo a c: " << a.isCongurentTo(c) << endl;
	cout << "isConvex: " << a.isConvex() << endl;
	cout << "8:\t" << a.perimetr() << endl;
	cout << "4:\t" << a.area() << endl;
	Polygon b({ Point(0,4), Point(4,0), Point(4,4), Point(0,0) });
	cout << "IsCongurentTo a b: " << a.isCongurentTo(b) << endl;
	cout << "Is Polygon not: " <<  b.isPolygon() << endl;
	cout << "1:\t" << (a == a) << endl;
	cout << "isConvex: " << b.isConvex() << endl;
	cout << a.containsPoint(Point(1, 1)) << " " << a.containsPoint(Point(2,2)) << " " <<
		a.containsPoint(Point(3, 3)) << endl;

	cout << endl;
}

void TestEllipse() {
	cout << "TestEllipse" << endl;
	Ellipse a(Point(-4, 0), Point(4, 0), 10);
	Ellipse b(Point(1, -4), Point(1, 4), 10);
	Ellipse c(Point(0, -3), Point(0, 3), 10);
	cout << "(0,0):\t" << a.center() << endl;
	cout << "47.1:\t" << a.area() << endl;
	cout << "25.55:\t" << a.perimetr() << endl;
	cout << "1:\t" << (a == a) << endl;
	cout << "0:\t" << (a == b) << endl;
	cout << "0:\t" << (a == c) << endl;
	cout << "1:\t" << a.isCongurentTo(b) << endl;
	cout << "0:\t" << a.isCongurentTo(c) << endl;
	cout << "c1:\t" << a.containsPoint(Point(20, 20)) << endl;
	cout << endl;
}

void TestCircle() {
	cout << "TestCircle" << endl;
	Circle a(Point(0,0), 5);
	Circle a1(Point(0, 0), 5);
	Circle b(Point(0, 0), 4);
	Circle c(Point(1, 1), 5);
	cout << "5:\t" << a.radius() << endl;
	cout << "(0,0):\t" << a.center() << endl;
	cout <<  "78.5:\t" << a.area() << endl;
	cout << "31.4:\t" << a.perimetr() << endl;
	cout << "0:\t" << a.isCongurentTo(b) << endl;
	cout << "1:\t" << a.isCongurentTo(c) << endl;
	cout << "0:\t" << (a == c) << endl;
	cout << "0:\t" << (a == b) << endl;
	cout << "1:\t" << (a == a1) << endl;
	cout << "1:\t" << a.containsPoint(Point(0, 4)) << endl;

	cout << endl;
}

void TestRectangle() {
	cout << "TestRectangle" << endl;
	Rectangle a(Point(0, 0), Point(4, 3), 4.0 / 3.0);
	Rectangle b(Point(0, 0), Point(3, 4), 3.0 / 4.0);
	Rectangle c(Point(0, 0), Point(5, 5), 1.0 / 1.0);
	cout << a.diagonals() << endl << b.diagonals() << endl << c.diagonals() << endl;
	cout << "6:\t" << a.area() << endl;
	cout << "14:\t" << a.perimetr() << endl;
	cout << "6:\t" << b.area() << endl;
	cout << "14:\t" << b.perimetr() << endl;
	cout << "(2, 1.5):\t" << a.center() << endl;
	cout << "1:\t" << a.isCongurentTo(b) << endl;
	cout << "4:\t" << a.verticesCount() << endl;
	cout << "1:\t" << (a == a) << endl;
	cout << "0:\t" << (a == b) << endl;
	cout << "0:\t" << (a == c) << endl;
	cout << "1:\t" << a.isConvex() << endl;
	cout << "1:\t" << a.isPolygon() << endl;
	cout << endl;
}

void TestSquare() {
	cout << "TestSquare" << endl;
	Square a(Point(0, 0), Point(4, 4));
	Circle b(Point(2, 2), 2);
	Circle c(Point(2, 2), 2*sqrt(2));
	cout << "(2, 2):\t" << a.center() << endl;
	cout << c.center() << " " << c.radius() << endl;
	cout << "1:\t" << (a.csCircle() == c) << endl;
	cout << "1:\t" << (a.insCircle() == b) << endl;
	cout << endl;
}
void TestTriangle() {
        cout << "TestTriangle" << endl;
        Triangle t1(Point(0, 0), Point(10, 0), Point(3, 7));
	for (auto it : t1.getVertices())
                cout << it << " ";
        cout << endl;
        for (auto it : t1.getSides()) 
                cout << it << " ";
        cout << endl;

	cout << "CsCir: " <<  t1.csCircle().center() << " " << t1.csCircle().radius() << endl;
	cout << "InsCir: " <<  t1.insCircle().center() << " " << t1.insCircle().radius() << endl;
        cout << "Orthocenter: " <<  t1.orthocenter() << endl;
        cout << "Centroid: " << t1.centroid() << endl;
        cout << "Euler line:\t" << t1.EulerLine() << endl;
        {
                Triangle t1(Point(0, 3), Point(0, 0), Point(5, 0));
                Triangle t2(Point(0, 0), Point(3, 0), Point(0, 5));
                cout << "1: " <<  (t1.isCongurentTo(t2)) << endl;
        }
        cout << endl;
}

int main() {
	TestPoint();
	TestLine();
	TestPolygon();
	TestEllipse();
	TestCircle();
	TestRectangle();
	TestSquare();
	TestTriangle();
	return 0;
}
