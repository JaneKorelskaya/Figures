#include "polygon.h"
#include <cmath>
Polygon::Polygon( vector<Point> points) {
	for (auto it : points) 
		vertices.push_back(it);
	for (int i = 0; i < vertices.size(); ++i) {
		if (i == vertices.size() - 1)
			sides.push_back(Line(vertices[i], vertices[0]));
		else
			sides.push_back(Line(vertices[i], vertices[i + 1])); 
	} 
}
 
Polygon::Polygon(vector<Line> lines) {
	try{
	for (int i = 0; i < lines.size(); ++i) {
		if (i == lines.size() - 1 && lines[i].end() != lines[0].begin() ) {
			throw invalid_argument("Invlid point 1!");
			break; 
		}
		if (i != lines.size() - 1) {
			if (lines[i].end() != lines[i + 1].begin()) {
				//cout << lines[i].begin() << " " << lines[i].end();
				throw invalid_argument("Invalid point 2!");
				break; 
			}
		} 
		vertices.push_back(lines[i].begin());
		sides.push_back(lines[i]);
	}} catch(invalid_argument& inv) {
		cout << inv.what() << endl;
		sides.clear();
		vertices.clear();
	}
			
}

size_t Polygon::verticesCount() const{
	return vertices.size();
}

vector<Point> Polygon::getVertices() const {
	return vertices;
} 
ostream& operator<<(ostream& os, const Polygon pol) {
	os << "Vertices: " << endl;
	for (auto it : pol.vertices) 
		os << it << " ";
	os << endl;
	os << "Sides: " << endl;
	for (auto it : pol.sides) 
		os << it;
	return os; 
}

double Polygon::perimetr() const {
	double res = 0;
	for (auto it : sides) 
		res += it.GetLen();
	return res; 
}

vector<Line> Polygon::getSides() const {
	return sides;
}

double Polygon::area() const {
	double res = 0;
	for (int i = 0; i < vertices.size(); ++i) {
		if (i == vertices.size() - 1) {
			res += vertices[i].x * vertices[0].y - vertices[i].y * vertices[0].x; 
		}
		else {
			res += vertices[i].x * vertices[i + 1].y - vertices[i].y * vertices[i + 1].x;
		}
	}
	return abs(res) * 0.5;
}

bool Polygon::containsPoint(Point p) const {
	double s = 0;
	for (int i = 0; i < getVertices().size(); ++i) {
		if (i == getVertices().size() - 1) {
			s += Polygon({p, getVertices().at(i), getVertices().at(0)}).area(); 
		}
		else {
			s += Polygon({p, getVertices().at(i), getVertices().at(i + 1)}).area();
		} 
	}
	if (s == area())
		return true;
	return false;
} 

bool Polygon::operator==(const Shape& another) {
        const Polygon& p = dynamic_cast<const Polygon&>(another);
        if (verticesCount() != p.verticesCount()) {
                return false;
        }
        for(int i = 0; i < getVertices().size(); ++i) {
                if (getVertices().at(i) != p.getVertices().at(i)) 
			return false;
        }
        return true;
}

vector<vector<double>> Polygon::MakeSortMatrixDist() const {
	vector<vector<double>> result(vertices.size());

	for(int i = 0; i < vertices.size(); ++i) {
		for(int j = 0; j < vertices.size(); ++j) {
			result[i].push_back(Line(vertices[i], vertices[j]).GetLen()); 
		} 
	}
        //cout << result;
	for(int i = 0; i < result.size(); ++i) 
		sort(result[i].begin(), result[i].end());
	//cout << result;
	return result;
}

bool isFind(vector<double>& v1, vector<vector<double>> matr) {
	//cout << matr.size() << endl;
	for(size_t i = 0; i < matr.size(); i++) {
		if(v1 == matr[i]) {
			//cout << v1 << endl << matr[i] << endl;
			//cout << i << endl;
			return true;
		}
	}
	//cout << "find false" << endl;
	return false; 
}

bool isCong(vector<vector<double>>& v1, vector<vector<double>>& v2) {
	for(int i = 0; i < v1.size(); i++) {
		//cout << v1[i] << endl;
		//cout << v2;
		if(isFind(v1[i], v2) == false)
			return false;
	}
	return true;
}



bool Polygon::isCongurentTo(const Shape& another) const {
        const Polygon& p = dynamic_cast<const Polygon&>(another);
        if (verticesCount() != p.verticesCount()) {
                return false;
        }
	
	vector<vector<double>> matr1 = MakeSortMatrixDist();
	vector<vector<double>> matr2 = p.MakeSortMatrixDist();
	return isCong(matr1, matr2);		
}

ostream& operator<<(ostream& os, vector<vector<double>>& v) {
        for (int i = 0; i < v.size(); i++) {
                for(int j = 0; j < v[i].size(); j++) {
                        os << v[i][j] << " ";
                }       
                os << endl;
        }       
        os << endl;
        return os;
}

ostream& operator<<(ostream& os, vector<double>& v) {
	for(auto it : v) 
		os << it << " ";
	os << endl;
	return os;
}
bool operator==(vector<double>& v1, vector<double>& v2) {
	if(v1.size() != v2.size())
		return false;
	for(int i = 0; i < v1.size(); ++i) {
		//cout << v1[i] << " " << v2[i] << endl; 
		if(abs(v1[i] - v2[i]) > 0.00001) {
			return false;
		}
	}
	return true;
}

bool Polygon::isPolygon() {
	int count = 0;
	for (int k = 0; k < vertices.size(); ++k) {
		if(vertices[k] == vertices[0]) {
			count += 1;
		}
	}
	if(count == vertices.size()) {
		return false;
	}
	for(int i = 0; i < sides.size(); ++i) {
		for (int j = 0; j < sides.size(); ++j) {
			if (i != j) {
				Point p = intersect_point(sides[i], sides[j]);
				//cout << p << endl;
				if (p == Point(1000000, 1000000))
						continue;
				if(BelongToLine(p, sides[i])) {
				       	if(OnLine(p, sides[j]))
						return false;
				}
				else if(BelongToLine(p, sides[j])) {
                                        if(OnLine(p, sides[i]))
                                                return false;
                                }

			}
		}
	}
	return true;
}

bool Polygon::isConvex() {
	if(!isPolygon()) 
		return false;
        for (int i = 0; i < vertices.size(); ++i) {
                vector<Point> v;
                for (int j = 0; j < vertices.size(); ++j) {
                        if (i != j) {
                                v.push_back(vertices[j]);
                        }
                }
                Polygon p(v);
                if (p.containsPoint(vertices[i])) {
                        return false;
                }
        }
        return true; 
}
