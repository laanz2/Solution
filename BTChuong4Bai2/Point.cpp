#include "Point.h"
#include <cmath>
#include <fstream>

Point::Point(float x_a, float y_a) {
	x = x_a;
	y = y_a;
}

void Point::setX(float x_a) {
	x = x_a;
}

float Point::getX() {
	return x;
}

void Point::setY(float y_a) {
	y = y_a;
}

float Point::getY() {
	return y;
}

std::ostream& operator<<(std::ostream& out, const Point& p) {
	out << "(" << p.x << " ; " << p.y << ")";
	return out;
}

std::istream& operator>>(std::istream& in, Point& p) {
	in >> p.x >> p.y;
	return in;
}

bool Point::operator<(const Point& po) {
	return (this->len() < po.len());
}