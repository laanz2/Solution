#include "Fraction.h"
#include <cstdlib>
#include <ctime>

int gcn(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

Fraction::Fraction() : numerator(0), denominator(1) {}


Fraction::Fraction(int num, int denom) {
	numerator = num;
	denominator = denom;
}

Fraction::Fraction(int n) {
	numerator = rand() % n;
	denominator = 1 + rand() % n;
}

Fraction Fraction::operator+(const Fraction& f) {
	int num = this->numerator * f.denominator + f.numerator * this->denominator;
	int denom = this->denominator * f.denominator;
	int u = gcn(abs(num), abs(denom));
	Fraction newFrac(num / u, denom / u);
	return newFrac;
}

Fraction Fraction::operator-(const Fraction& f) {
	int num = this->numerator * f.denominator - f.numerator * this->denominator;
	int denom = this->denominator * f.denominator;
	int u = gcn(abs(num), abs(denom));
	Fraction newFrac(num / u, denom / u);
	return newFrac;
}

Fraction Fraction::operator*(const Fraction& f) {
	int num = this->numerator * f.numerator;
	int denom = this->denominator * f.denominator;
	int u = gcn(abs(num), abs(denom));
	Fraction newFrac(num / u, denom / u);
	return newFrac;
}

Fraction Fraction::operator/(const Fraction& f) {
	int num = this->numerator * f.denominator;
	int denom = this->denominator * f.numerator;
	int u = gcn(abs(num), abs(denom));
	Fraction newFrac(num / u, denom / u);
	return newFrac;
}

bool Fraction::operator==(const Fraction& fr) {
	return (Fraction::operator-(fr).numerator == 0);
}

bool Fraction::operator!=(const Fraction& fr) {
	return (Fraction::operator-(fr).numerator != 0);
}

bool Fraction::operator>(const Fraction& fr) {
	return (Fraction::operator-(fr).numerator > 0 && Fraction::operator-(fr).denominator > 0);
}

bool Fraction::operator<(const Fraction& fr) {
	return (Fraction::operator-(fr).numerator < 0 || Fraction::operator-(fr).denominator < 0);
}

std::ostream& operator<<(std::ostream& out, const Fraction& frac) {
	out << frac.numerator << "/" << frac.denominator;
	return out;
}

std::istream& operator>>(std::istream& in, Fraction& frac) {
	in >> frac.numerator;
	in >> frac.denominator;
	return in;
}

Fraction::~Fraction() {}