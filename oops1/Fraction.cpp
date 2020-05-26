#include<iostream>
using namespace std;

class Fraction {

	private : 

		int numerator;
		int denominator;

		int gcd(int a, int b) {
			if(b > a) {
				return gcd(b, a);
			}

			if(b == 0) {
				return a;
			}

			return gcd(b, a%b);
		}		

	public : 

		Fraction(int numerator, int denominator) {

			this->numerator = numerator;
			this->denominator = denominator;

			simplify();
		}

		void simplify() {

			int g = gcd(numerator, denominator);

			numerator /= g;
			denominator /= g;
		}

		void print() {
			cout << numerator << "/" << denominator << endl;
		}

		// void add(Fraction const &f2) {

		// 	int lcm = denominator * f2.denominator;
		// 	int x = lcm / denominator;
		// 	int y = lcm / f2.denominator;

		// 	numerator = x*numerator + y*f2.numerator;
		// 	denominator = lcm;

		// 	simplify();
		// }

		// A slight modification to the function

		Fraction add(Fraction const &f2) const {

			int lcm = this->denominator * f2.denominator;
			int x = lcm / this->denominator;
			int y = lcm / f2.denominator;

			int numerator = x*this->numerator + y*f2.numerator;
			int denominator = lcm;

			Fraction fNew(numerator, denominator);
			// fNew.simplify();

			return fNew;
		}

		// Operator overloading

		Fraction operator+(Fraction const &f2) const {  // f1 + f2 is equivalent to f1.add(f2)

			int lcm = this->denominator * f2.denominator;
			int x = lcm / this->denominator;
			int y = lcm / f2.denominator;

			int numerator = x*this->numerator + y*f2.numerator;
			int denominator = lcm;

			Fraction fNew(numerator, denominator);
			// fNew.simplify();

			return fNew;
		}
		

		// void multiply(Fraction const &f2) {

		// 	numerator = numerator * f2.numerator;
		// 	denominator = denominator * f2.denominator;

		// 	simplify();
		// }

		Fraction multiply(Fraction const &f2) const {

			int numerator = this->numerator * f2.numerator;
			int denominator = this->denominator * f2.denominator;

			Fraction fNew(numerator, denominator);

			return fNew;

			// simplify();
		}

		// Operator overloading 

		Fraction operator*(Fraction const &f2) const {

			int numerator = this->numerator * f2.numerator;
			int denominator = this->denominator * f2.denominator;

			Fraction fNew(numerator, denominator);

			return fNew;
		}

		bool operator==(Fraction const &f2) const {
			return (numerator == f2.numerator && denominator == f2.denominator);
		}

		// Pre increment
		Fraction& operator++() { // We are returning the reference in order to avoid the buffer that will be created while returning the fraction from the given function
			numerator = numerator + denominator;
			simplify();

			return *this;
		}
};

int main() {

	Fraction f1(10, 2);
	Fraction f2(15, 4);

	Fraction f3 = f1.add(f2);

	f1.print();
	f2.print();
	f3.print();

	Fraction f4 = f1 + f2;

	f4.print();

	Fraction f5 = f2.multiply(f1);
	Fraction f6 = f1 * f2;

	f5.print();
	f6.print();

	if(f5 == f2) {
		cout << "Equal" << endl;
	}
	else {
		cout << "Not Equal" << endl;
	}

	Fraction f7(10, 2);
	Fraction f8 = ++(++f7);

	f8.print();
	f7.print();

	return 0;

}