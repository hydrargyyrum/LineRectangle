#include <iostream>
#include "task_1_line_crossing.h"
#include "square.h"

using namespace std;


class vector {
private:
	const int n;
	int* m;
public:
	vector(int n) : n(n) { m = new int[n]; }

	static vector read(int n) {
		vector v(n);
		v.read();
		return v;
	}

	void sort() {
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (m[j] > m[j + 1]) {
					int tmp = m[j];
					m[j] = m[j + 1];
					m[j + 1] = tmp;
				}
			}
		}
	}

	void read() {
		cout << "Enter elements ->" << endl;
		for (int i = 0; i < n; i++) {
			cin >> m[i];
		}

	}

	void print() { 
		for (int i = 0; i < n; i++) {
			cout << m[i] << " ";
		}
		cout << endl;
	}
};


int main() {
	vector xxx = vector::read(4);
	/*int n = 4;
	vector v = v.create(n);
	v.print();
	v.sort();
	v.print();*/

	//line s1(2, 5, 4, 1);
	//line s2(-3, 1, 2, 0);
	//s1.findP(s2);

	point2d p1(0, 0);
	point2d p2(5, 5);
	point2d p3(1, 1);
	point2d p4(6, 4);
	rectangle r1(p1, p2);
	rectangle r2(p3, p4);
	double w = r1.cross(r2, 0);
	double h = r1.cross(r2, 1);
	cout << w * h;
	return 0;
}