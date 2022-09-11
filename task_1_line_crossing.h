#pragma once
#include <iostream>
using namespace std;

class line {
private:
	const double x1, y1, x2, y2;
public:
	line(double x1, double y1, double x2, double y2) : x1(x1), x2(x2), y1(y1), y2(y2) {};

	// todo is it xCrossing ?
	double yP(double x) {
		line const& l1 = *this;
		return x * (l1.y2 - l1.y1) / (l1.x2 - l1.x1) + (l1.x2 * l1.y1 - l1.x1 * l1.y2) / (l1.x2 - l1.x1);
	}

	// todo is it xCrossing ?
	double xP(line const& l2) {
		line const& l1 = *this;
		// too long line
		return (l1.x1 * l1.y2 - l1.x1 * l1.x2 - l2.x1 * l2.y2 + l2.x2 * l2.y1) / ((l2.y2 - l2.y1) / (l2.x2 - l2.x1) - (l1.y2 - l1.y1) / (l1.x2 - l1.x1));
	}

	// todo dont belong to line
	bool isEqual(double value1, double value2) {
		if (value1 == value2) return true;
		else return false;
	}

	bool isVertical() {
		return isEqual(l1.x1, l1.x2);
	}

	// todo result must be an point2d
	void findP(line const& l2) {
		line const& l1 = *this; // what does mean const in the position

		if ((!isEqual(l1.x1, l1.x2) && !isEqual(l1.y1, l1.y2)) &&
			(!isEqual(l2.x1, l2.x2) && !isEqual(l2.y1, l2.y2))) {
			cout << "(" << xP(l2) << ";" << yP(xP(l2)) << ")" << endl; // todo method is not about printing
		}
		

		if ((isEqual(l1.y1, l1.y2) && isEqual(l2.y1, l2.y2) && isEqual(l1.y1, l2.y2)) ||
			(isEqual(l1.x1, l1.x2) && isEqual(l2.x1, l2.x2) && isEqual(l1.x1, l2.x2))) {
			cout << " straight lines match" << endl;
		}
		// todo remove or add empty lines for correct style

		if (((isEqual(l1.y1, l1.y2) && isEqual(l2.y1, l2.y2)) && (!isEqual(l1.y1, l2.y1))) ||
			((isEqual(l1.x1, l1.x2) && isEqual(l2.x1, l2.x2)) && (!isEqual(l1.x1, l2.x1)))) {
			cout << "straight lines are parallel" << endl;
		}

		if (isEqual(l1.x1, l1.x2) && isEqual(l2.y1, l2.y2)) {
			cout << "( " << l1.x1 << ";" << l2.y1 << ")" << endl;
		}


		if (isEqual(l1.y1, l1.y2) && isEqual(l2.x1, l2.x2)) {
			cout << "( " << l2.x1 << ";" << l1.y1 << ")" << endl;
		}
	}
};