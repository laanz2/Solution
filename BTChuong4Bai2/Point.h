#pragma once
#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point {
private:
	float x;
	float y;

public:

	Point(float x_a, float y_a);
	void setX(float x_a);
	float getX();
	void setY(float y_a);
	float getY();
	float len() const { return sqrt(x * x + y * y); }
	friend std::ostream& operator<<(std::ostream& out, const Point& p);
	friend std::istream& operator>>(std::istream& in, Point& p);
	bool operator<(const Point& po);

};

#endif // "POINT_H"
