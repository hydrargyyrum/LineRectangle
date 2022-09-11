#pragma once
#include <iostream>
using namespace std;

struct interval_1d {
	double x1, x2;

	interval_1d() : x1(0), x2(0) { }

	interval_1d(double x1, double x2) { 
		if (x1 > x2) {
			double tmp = x1;
			x1 = x2;
			x2 = x1;
		}
		this->x1 = x1;
		this->x2 = x2;
	}

	double length() const {
		return -1; // TODO
	}

	static bool cross(const interval_1d & r1, const interval_1d & r2, interval_1d & rCross) {
		double x1 = max(r1.x1, r2.x1);
		double x2 = min(r1.x2, r2.x2);
		if (x1 > x2)
			return false;
		rCross = interval_1d(x1, x2);
		return true;
	}
};


struct point2d {
	double x, y;
	point2d(double x, double y) : x(x), y(y) {};
};


class rectangle {
public:
	interval_1d rx, ry;
	point2d p1, p2; // can replace using range1d
public:

	rectangle(point2d p1, point2d p2) {
		// todo rx = ; ry =
	};

	// dont belong to rectangle. Functional is not about rectnagle.
	bool inInterval(double a, double b, double c) { 
		if ((a <= c) && (c <= b)) return true;
		return false;
	}

	interval_1d rx() { } // TODO
	interval_1d ry() { } // TODO

	static double cross(rectangle r1, rectangle r2) {
		interval_1d rx;
		interval_1d ry;
		if (interval_1d::cross(r1.rx(), r2.rx(), rx) &&
			interval_1d::cross(r1.ry(), r2.ry(), ry)) {
			return rx.length() * ry.length();
		}
		return 0;
	}

	double cross(const rectangle r, int i) {
		rectangle& r1 = *this;
		rectangle r2 = r;
		switch (i) {
		case 0:
		{
			if (r1.p1.x > r1.p2.x) {
				double tmp = r1.p1.x;
				r1.p1.x = r1.p2.x;
				r1.p2.x = tmp;
			}

			if (r2.p1.x > r2.p2.x) {
				double tmp = r2.p1.x;
				r2.p1.x = r2.p2.x;
				r2.p2.x = tmp;
			}

			if (inInterval(r1.p1.x, r1.p2.x, r2.p1.x) && inInterval(r1.p1.x, r1.p2.x, r2.p2.x)) {
				return (r2.p2.x - r2.p1.x);
			}

			if (inInterval(r2.p1.x, r2.p2.x, r1.p1.x) && inInterval(r2.p1.x, r2.p2.x, r1.p2.x)) {
				return (r1.p2.x - r1.p1.x);
			}

			if (inInterval(r1.p1.x, r1.p2.x, r2.p1.x) && !inInterval(r1.p1.x, r1.p2.x, r2.p2.x)) {
				return (r2.p1.x - r1.p2.x);
			}


			if (inInterval(r2.p1.x, r2.p2.x, r1.p2.x) && !inInterval(r2.p1.x, r2.p2.x, r1.p1.x)) {
				return (r1.p2.x - r2.p1.x);
			}
		}

		case 1:
		{
			if (r1.p1.y > r1.p2.y) {
				double tmp = r1.p1.y;
				r1.p1.y = r1.p2.y;
				r1.p2.y = tmp;
			}

			if (r2.p1.y > r2.p2.y) {
				double tmp = r2.p1.y;
				r2.p1.y = r2.p2.y;
				r2.p2.y = tmp;
			}

			if (inInterval(r1.p1.y, r1.p2.y, r2.p1.y) && inInterval(r1.p1.y, r1.p2.y, r2.p2.y)) {
				return (r2.p2.y - r2.p1.y);
			}

			if (inInterval(r2.p1.y, r2.p2.y, r1.p1.y) && inInterval(r2.p1.y, r2.p2.y, r1.p2.y)) {
				return (r1.p2.y - r1.p1.y);
			}

			if (inInterval(r1.p1.y, r1.p2.y, r2.p1.y) && !inInterval(r1.p1.y, r1.p2.y, r2.p2.y)) {
				return (r2.p1.y - r1.p2.y);
			}


			if (inInterval(r2.p1.y, r2.p2.y, r1.p2.y) && !inInterval(r2.p1.y, r2.p2.y, r1.p1.y)) {
				return (r1.p2.y - r2.p1.y);
			}
		}
		}

	};
};


