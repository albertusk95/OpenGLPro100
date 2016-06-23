/*
	Class: Circle
	Header implementation
*/

#include "Circle.h"

	Circle::Circle(double x, double vx, double y, double vy) : x(x), vx(vx), y(y), vy(vy) {}

	void Circle::step(double dt) {
		x += vx * dt;
		y += vy * dt;
		vx = vx;
		vy -= g * dt;

		if (x > circleMaxPosX) {
			vx = -abs(vx);
		}
		if (x < circleMinPosX) {
			vx = abs(vx);
		}
		if (y < circleMinPosY) {
			vy = abs(vy);
			currentPoint--;
		}
	}

	void Circle::setObjColor() {
		int tmpR = 0, tmpG = 0, tmpB = 0;

		srand((unsigned int)time(NULL));
		while (((float)tmpR == 0.0f && (float)tmpG == 0.0f && (float)tmpB == 0.0f) || ((float)tmpR == 1.0f && (float)tmpG == 1.0f && (float)tmpB == 1.0f)) {
			tmpR = rand() % 2;         // tmpR in the range 0 to 1
			tmpG = rand() % 2;         // tmpG in the range 0 to 1
			tmpB = rand() % 2;         // tmpB in the range 0 to 1
		}
		R = (float)tmpR;
		G = (float)tmpG;
		B = (float)tmpB;
	}

