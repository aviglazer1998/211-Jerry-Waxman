#include <iostream>
#include <cmath>
using namespace std;

class Rat {

private:

	int n;
	int d;

public:

	Rat() {

		n = 0;
		d = 1;
	}

	Rat(int i, int j) {

		n = i;
		d = j;
	}

	Rat(int i) {

		n = i;
		d = 1;
	}

	int getN() { return n; }
	int getD() { return d; }
	void setN(int i) { n = i; }
	void setD(int i) { d = i; }

	Rat operator+(Rat r) {

		Rat t;

		t.n = n * r.d + d * r.n;
		t.d = d * r.d;

		simplify(t);

		return t;
	}

	Rat operator-(Rat r) {

		Rat t;

		t.n = n * r.d - d * r.n;
		t.d = d * r.d;

		simplify(t);

		return t;
	}

	Rat operator*(Rat r) {

		Rat t;

		t.n = n * r.n;
		t.d = d * r.d;

		simplify(t);

		return t;
	}

	Rat operator/(Rat r) {

		Rat t;

		t.n = n * r.d;
		t.d = d * r.n;

		simplify(t);

		return t;
	}

	void simplify(Rat& t) {

		int theGCD = t.gcd(t.getN(), t.getD());

		t.n /= theGCD;

		t.d /= theGCD;
	}

	void improperFraction(Rat& t) {

		if (t.getN() > t.getD()) {

			t.n %= t.d;
		}
	}

	int gcd(int n, int d) {

		return d == 0 ? n : gcd(d, n % d);
	}

	friend ostream& operator<<(ostream& os, Rat r);
	friend istream& operator>>(istream& is, Rat& r);

};

ostream& operator<<(ostream& os, Rat r) {

	if (r.n == r.d)
		os << 1;

	else if (r.n % r.d == 0)
		os << (r.n) / (r.d);

	else if (r.n == 0)
		os << 0;

	else if (r.n > r.d) {

		int whole;
		int partial;

		whole = r.n / r.d;

		partial = r.n - (whole)*r.d;

		os << whole << " " << partial << "/" << r.d;
	}
	else
		os << r.n << "/" << r.d;

	return os;
}

istream& operator>>(istream& is, Rat& r) {

	is >> r.n >> r.d;

	return is;
}

int main() {

	Rat r1(7,3), r2(5,4);

	cout << "r1: " << r1 << endl;
	cout << "r2: " << r2 << endl;
	cout << "r1 + r2: " << r1 + r2 << endl;
	cout << "r1 - r2: " << r1 - r2 << endl;
	cout << "r1 * r2: " << r1 * r2 << endl;
	cout << "r1 / r2: " << r1 / r2 << endl << endl;



	r1 = r2;
	r2 = r1 * r2;

	cout << "r1: " << r1 << endl;
	cout << "r2: " << r2 << endl;
	cout << "r1 + r2: " << r1 + r2 << endl;
	cout << "r1 - r2: " << r1 - r2 << endl;
	cout << "r1 * r2: " << r1 * r2 << endl;
	cout << "r1 / r2: " << r1 / r2 << endl;

	cout << endl;

	r1 = r2 + r1 * r2 / r1;
	r2 = r2 + r1 * r2 / r1;

	cout << "r1: " << r1 << endl;
	cout << "r2: " << r2 << endl;
	cout << "r1 + r2: " << r1 + r2 << endl;
	cout << "r1 - r2: " << r1 - r2 << endl;
	cout << "r1 * r2: " << r1 * r2 << endl;
	cout << "r1 / r2: " << r1 / r2 << endl;


	system("pause");
	return 0;
}