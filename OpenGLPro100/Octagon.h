/*
	Class: Octagon
	Membentuk objek berupa segi delapan yang memiliki atribut berupa
	posisi awal objek (x, y) dan kecepatan gerak berdasarkan sumbu x (vx) dan sumbu y (vy)
*/

#include "GlobElmt.h"

#ifndef Octagon_h
#define Octagon_h

class Octagon {

public:

	GLfloat R = 0.0f, G = 0.0f, B = 0.0f;
	double x, vx, y, vy;

	Octagon(double x, double vx, double y, double vy);

	void step(double dt);

	void setObjColor();

};

#endif