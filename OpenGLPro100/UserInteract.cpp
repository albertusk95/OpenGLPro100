/*
	UserInteract
	Header implementation
*/

#include "UserInteract.h"

using namespace std;

void getUserInput() {
	cout << "OpenGLPro100" << endl;
	cout << "--------------------------" << endl;
	cout << "Albertus Kelvin - 13514100" << endl << endl;

	// input bagian SQUARE
	cout << "[Square]" << endl;
	cout << "Jumlah square (kotak): ";
	cin >> numSquare;

	if (numSquare < 0) {
		cout << "Input jumlah tidak valid. Jumlah square dibuat default: 1" << endl;
		numSquare = 1;
	}

	if (numSquare > 0) {
		cout << "Pewarnaan objek: 0. Random; 1. Tentukan sendiri --- [0/1]: ";
		cin >> fillColorSquare;
	}

	cout << endl;

	// input bagian CIRCLE
	cout << "[Circle]" << endl;
	cout << "Jumlah circle (lingkaran): ";
	cin >> numCircle;

	if (numCircle < 0) {
		cout << "Input jumlah tidak valid. Jumlah circle dibuat default: 1" << endl;
		numCircle = 1;
	}

	if (numCircle > 0) {
		cout << "Pewarnaan objek: 0. Random; 1. Tentukan sendiri --- [0/1]: ";
		cin >> fillColorCircle;
	}

	cout << endl;

	// input bagian OCTAGON
	cout << "[Octagon]" << endl;
	cout << "Jumlah octagon (segi-8): ";
	cin >> numOctagon;

	if (numOctagon < 0) {
		cout << "Input jumlah tidak valid. Jumlah octagon dibuat default: 1" << endl;
		numOctagon = 1;
	}

	if (numOctagon > 0) {
		cout << "Pewarnaan objek: 0. Random; 1. Tentukan sendiri --- [0/1]: ";
		cin >> fillColorOctagon;
	}

	cout << endl;

	totalPoint = (numCircle + numSquare + numOctagon) * 3;

	t = 0;
	step_number = 0;
}

void setUserCircle(int idx) {
	cout << "[Circle " << idx << "]" << endl;
	cout << "R: ";
	cin >> circles[idx]->R;
	if (circles[idx]->R < 0 || circles[idx]->R > 1) {
		cout << "Kode tidak valid. Set kode R dengan nilai default: 0.5" << endl;
		circles[idx]->R = 0.5f;
	}
	cout << "G: ";
	cin >> circles[idx]->G;
	if (circles[idx]->G < 0 || circles[idx]->G > 1) {
		cout << "Kode tidak valid. Set kode G dengan nilai default: 0.5" << endl;
		circles[idx]->G = 0.5f;
	}
	cout << "B: ";
	cin >> circles[idx]->B;
	if (circles[idx]->B < 0 || circles[idx]->B > 1) {
		cout << "Kode tidak valid. Set kode B dengan nilai default: 0.5" << endl;
		circles[idx]->B = 0.5f;
	}

	if (((float)circles[idx]->R == 0.0f && (float)circles[idx]->G == 0.0f && (float)circles[idx]->B == 0.0f) || ((float)circles[idx]->R == 1.0f && (float)circles[idx]->G == 1.0f && (float)circles[idx]->B == 1.0f)) {
		cout << "Kode tidak valid. Set kode R, G, dan B untuk circle " << idx << " dengan default: 0.5, 0.5, 0.5" << endl;
		circles[idx]->R = 0.5f;
		circles[idx]->G = 0.5f;
		circles[idx]->B = 0.5f;
	}
}

void setUserSquare(int idx) {
	cout << "[Square " << idx << "]" << endl;
	cout << "R: ";
	cin >> squares[idx]->R;
	if (squares[idx]->R < 0 || squares[idx]->R > 1) {
		cout << "Kode tidak valid. Set kode R dengan nilai default: 0.5" << endl;
		squares[idx]->R = 0.5f;
	}
	cout << "G: ";
	cin >> squares[idx]->G;
	if (squares[idx]->G < 0 || squares[idx]->G > 1) {
		cout << "Kode tidak valid. Set kode G dengan nilai default: 0.5" << endl;
		squares[idx]->G = 0.5f;
	}
	cout << "B: ";
	cin >> squares[idx]->B;
	if (squares[idx]->B < 0 || squares[idx]->B > 1) {
		cout << "Kode tidak valid. Set kode B dengan nilai default: 0.5" << endl;
		squares[idx]->B = 0.5f;
	}

	if (((float)squares[idx]->R == 0.0f && (float)squares[idx]->G == 0.0f && (float)squares[idx]->B == 0.0f) || ((float)squares[idx]->R == 1.0f && (float)squares[idx]->G == 1.0f && (float)squares[idx]->B == 1.0f)) {
		cout << "Kode tidak valid. Set kode R, G, dan B untuk square " << idx << " dengan default: 0.5, 0.5, 0.5" << endl;
		squares[idx]->R = 0.5f;
		squares[idx]->G = 0.5f;
		squares[idx]->B = 0.5f;
	}
}

void setUserOctagon(int idx) {
	cout << "[Octagon " << idx << "]" << endl;
	cout << "R: ";
	cin >> octagons[idx]->R;
	if (octagons[idx]->R < 0 || octagons[idx]->R > 1) {
		cout << "Kode tidak valid. Set kode R dengan nilai default: 0.5" << endl;
		octagons[idx]->R = 0.5f;
	}
	cout << "G: ";
	cin >> octagons[idx]->G;
	if (octagons[idx]->G < 0 || octagons[idx]->G > 1) {
		cout << "Kode tidak valid. Set kode G dengan nilai default: 0.5" << endl;
		octagons[idx]->G = 0.5f;
	}
	cout << "B: ";
	cin >> octagons[idx]->B;
	if (octagons[idx]->B < 0 || octagons[idx]->B > 1) {
		cout << "Kode tidak valid. Set kode B dengan nilai default: 0.5" << endl;
		octagons[idx]->B = 0.5f;
	}

	if (((float)octagons[idx]->R == 0.0f && (float)octagons[idx]->G == 0.0f && (float)octagons[idx]->B == 0.0f) || ((float)octagons[idx]->R == 1.0f && (float)octagons[idx]->G == 1.0f && (float)octagons[idx]->B == 1.0f)) {
		cout << "Kode tidak valid. Set kode R, G, dan B untuk octagon " << idx << " dengan default: 0.5, 0.5, 0.5" << endl;
		octagons[idx]->R = 0.5f;
		octagons[idx]->G = 0.5f;
		octagons[idx]->B = 0.5f;
	}
}

