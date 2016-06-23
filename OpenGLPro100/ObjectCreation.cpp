/*
	ObjectCreation
	Header implementation
*/

#include "ObjectCreation.h"

using namespace std;

void create_circle() {
	double alpha;

	if (numCircle > 0) {
		circles = new Circle*[numCircle];
		if (fillColorCircle == 1) {
			cout << "[Penentuan warna objek lingkaran]" << endl;
			cout << "Masukkan kode warna R, G, dan B dari 0 sampai dengan 1" << endl;
			cout << "Invalid code: < 0, > 1, R=G=B=0, dan R=G=B=1" << endl;
		}
		for (int i = 0; i < numCircle; i++) {
			alpha = pi * rand() / double(RAND_MAX);
			circles[i] = new Circle(0, v_max * cos(alpha), 0, v_max * sin(alpha));
			// user memasukkan kode warna RGB jika memilih untuk menentukan warna sendiri
			if (fillColorCircle == 1) {
				setUserCircle(i);
			}
		}
	}
}

void create_square() {
	double alpha;

	if (numSquare > 0) {
		squares = new Square*[numSquare];
		if (fillColorSquare == 1) {
			cout << "[Penentuan warna objek kotak]" << endl;
			cout << "Masukkan kode warna R, G, dan B dari 0 sampai dengan 1" << endl;
			cout << "Invalid code: < 0, > 1, R=G=B=0, dan R=G=B=1" << endl;
		}
		for (int i = 0; i < numSquare; i++) {
			alpha = pi * rand() / double(RAND_MAX);
			squares[i] = new Square(0, v_max * cos(alpha), 0, v_max * sin(alpha));
			// user memasukkan kode warna RGB jika memilih untuk menentukan warna sendiri
			if (fillColorSquare == 1) {
				setUserSquare(i);
			}
		}
	}
}

void create_octagon() {
	double alpha;

	if (numOctagon > 0) {
		octagons = new Octagon*[numOctagon];
		if (fillColorOctagon == 1) {
			cout << "[Penentuan warna objek segi delapan]" << endl;
			cout << "Masukkan kode warna R, G, dan B dari 0 sampai dengan 1" << endl;
			cout << "Invalid code: < 0, > 1, R=G=B=0, dan R=G=B=1" << endl;
		}
		for (int i = 0; i < numOctagon; i++) {
			alpha = pi * rand() / double(RAND_MAX);
			octagons[i] = new Octagon(0, v_max * cos(alpha), 0, v_max * sin(alpha));
			// user memasukkan kode warna RGB jika memilih untuk menentukan warna sendiri
			if (fillColorOctagon == 1) {
				setUserOctagon(i);
			}
		}
	}
}
