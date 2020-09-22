#include <iostream>


int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, b % a);
}
class Rational {
private:
	int numerator, denominator;
	Rational reduce() {
		this->numerator /= gcd(numerator, denominator);
		this->denominator /= gcd(numerator, denominator);
		return *this;
	}
public:
	Rational() : numerator(0), denominator(1) { }
	Rational(int n, int d) : numerator(n), denominator(d) { }
	Rational(const Rational& r) : numerator(r.numerator), denominator(r.denominator) { }
	int getNum() const { return this->numerator; }
	int getDen() const { return this->denominator; }
	Rational& operator+(const Rational& r) {
		this->numerator = this->numerator * r.denominator + r.numerator * this->denominator;
		this->denominator = r.denominator * this->denominator;
		return *this;
	}
	Rational& operator-(const Rational& r) {
		this->numerator = this->numerator * r.denominator - r.numerator * this->denominator;
		this->denominator = r.denominator * this->denominator;
		return *this;
	}
	Rational& operator*(const Rational& r) {
		this->numerator = this->numerator * r.numerator;
		this->denominator = r.denominator * this->denominator;
		return *this;
	}
	Rational& operator/(const Rational& r) {
		this->numerator = this->numerator * r.denominator;
		this->denominator = this->denominator * r.numerator;
		return *this;
	}
	bool operator==(const Rational& r) {
		return this->numerator == r.numerator && this->denominator == r.denominator;
	}
	bool operator>(const Rational& r) {
		return (this->numerator * 1.0 / r.numerator) > (this->denominator * 1.0 / r.denominator);
	}
	bool operator<(const Rational& r) {
		return (this->numerator * 1.0 / r.numerator) < (this->denominator * 1.0 / r.denominator);
	}
	bool operator!=(const Rational& r) {
		return (this->numerator * 1.0 / r.numerator) != (this->denominator * 1.0 / r.denominator);
	}
	Rational& operator+(int n) {
		this->numerator = this->numerator + n * this->denominator;
		this->numerator /=  gcd(this->numerator, this->denominator);
		this->denominator /= gcd(this->numerator, this->denominator);
		return *this;
	}

	~Rational() { }
};
double convert(const Rational& r) {
	return r.getNum() * 1.0 / r.getDen();
}

int main() {
	Rational a(10, 20);
	Rational b(1, 5);
	Rational c;
	c = a + b;

	std::cout << convert(c);
	std::cin.get();
}
