/*
	Class: Circle
	Membentuk objek berupa lingkaran dengan atribut berupa
	posisi awal lingkaran (x, y) dan kecepatan gerak berdasarkan sumbu x (vx) dan sumbu y (vy)
*/

#include "GlobElmt.h"

#ifndef Circle_h
#define Circle_h

class Circle {

public:

	GLfloat R = 0.0f, G = 0.0f, B = 0.0f;
	double x, vx, y, vy;

	Circle(double x, double vx, double y, double vy);

	void step(double dt);

	void setObjColor(); 
};

#endif