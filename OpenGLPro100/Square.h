/*
	Class: Square
	Membentuk objek berupa kotak yang memiliki atribut berupa
	posisi awal objek (x, y) dan kecepatan gerak berdasarkan sumbu x (vx) dan sumbu y (vy)
*/

#include "GlobElmt.h"

#ifndef Square_h
#define Square_h

class Square {

public:

	GLfloat R = 0.0f, G = 0.0f, B = 0.0f;
	double x, vx, y, vy;

	Square(double x, double vx, double y, double vy);

	void step(double dt);

	void setObjColor();

};

#endif