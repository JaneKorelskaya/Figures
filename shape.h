#pragma once 
#include "point.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Shape {
public:
	virtual double perimetr() const = 0;
	virtual double area() const = 0;
	virtual bool containsPoint(Point) const  = 0;
	virtual bool operator==(const Shape& another) = 0;
	virtual bool isCongurentTo(const Shape&) const = 0;	
};

template<typename T>
ostream& operator<<(ostream& os, const pair<T, T>& p) {
        os << p.first << " " << p.second;
        return os;
}
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
       for (auto it : v)
        os << it;
       os << endl;
       return os;
}
