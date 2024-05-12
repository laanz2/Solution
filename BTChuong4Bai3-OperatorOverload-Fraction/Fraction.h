#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

class Fraction {
private:
	int numerator;
	int denominator;
public:

	Fraction();
	Fraction(int n);
	Fraction(int num, int denom);
	Fraction operator+(const Fraction& f);
	Fraction operator-(const Fraction& f);
	Fraction operator*(const Fraction& f);
	Fraction operator/(const Fraction& f);
	bool operator==(const Fraction& fr);
	bool operator!=(const Fraction& fr);
	bool operator>(const Fraction& fr);
	bool operator<(const Fraction& fr);
	friend std::ostream& operator<<(std::ostream& out, const Fraction& frac);
	friend std::istream& operator>>(std::istream& in, Fraction& frac);
	~Fraction();

};

#endif // FRACTION_H
