
/*
	OpenGLPro100
	Menampilkan beberapa objek bangun dasar seperti garis, kotak, lingkaran, dan segi-8.

	Author: Albertus Kelvin / 13514100
*/

#include <math.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h> // hanya untuk OS Windows
#include <GL\glew.h>
#include <GL\freeglut.h> // include glu.h dan gl.h

using namespace std;

/** VARIABEL GLOBAL **/

const double pi = 4 * atan(1.0);

// asumsi nilai gravitasi
const double g = 9.8;

// variabel yang menyatakan status window apakah dalam fullscreen atau tidak
bool fullScreenMode = true; 

// variabel yang menyimpan nilai panjang dan lebar window
int windowWidth = 640;
int windowHeight = 480;

// variabel yang menyimpan nilai posisi titik ujung kiri atas saat aplikasi pertama kali dijalankan
int windowPosX = 50;
int windowPosY = 50;

// variabel yang menyimpan jumlah masing-masing objek yang dibentuk
int numLine, numSquare, numCircle, numOctagon;         

// variabel yang menyimpan kecepatan gerak awal maksimum
double v_max = 1;     

// variabel yang menyimpan nilai waktu gerak yang ada pada rumus v = s / t
double dt = 0.01;     

// variabel yang menyimpan nilai waktu simulasi
double t;             

int step_number;      // time step number

// variabel yang menyimpan apakah user ingin warna objek ditentukan sendiri atau random
int fillColorSquare, fillColorCircle, fillColorOctagon, fillColorLine;

// variabel yang menyimpan posisi hasil translasi untuk kotak pemantul
GLfloat sqBouncerPosX = 0.0f, sqBouncerPosY = 0.0f;

// variabel yang menyimpan batas-batas daerah untuk menampilkan objek
//GLfloat ballXMin, ballXMax, ballYMin, ballYMax;
GLfloat circleMinPosX, circleMaxPosX, circleMinPosY, circleMaxPosY;
GLfloat squareMinPosX, squareMaxPosX, squareMinPosY, squareMaxPosY;
GLfloat octagonMinPosX, octagonMaxPosX, octagonMinPosY, octagonMaxPosY;

// Current rotational angle of the shapes
GLfloat angle = 0.0f;  


/*
	Class: Circle
	Membentuk objek berupa lingkaran dengan atribut berupa
	posisi awal lingkaran (x, y) dan kecepatan gerak berdasarkan sumbu x (vx) dan sumbu y (vy)
*/
class Circle {

public:

	GLfloat R = 0.0f, G = 0.0f, B = 0.0f;
	double x, vx, y, vy;

	Circle(double x, double vx, double y, double vy) : x(x), vx(vx), y(y), vy(vy) {}

	void step(double dt) {
		x += vx * dt;
		y += vy * dt;
		vx = vx;
		vy -= g * dt;

		if (x > circleMaxPosX) vx = -abs(vx);
		if (x < circleMinPosX) vx = abs(vx);
		if (y < circleMinPosY) vy = abs(vy);
	}

	void setObjColor() {
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

};

/*
	Class: Square
	Membentuk objek berupa kotak yang memiliki atribut berupa
	posisi awal objek (x, y) dan kecepatan gerak berdasarkan sumbu x (vx) dan sumbu y (vy)
*/
class Square {

public:

	GLfloat R = 0.0f, G = 0.0f, B = 0.0f;
	double x, vx, y, vy;

	Square(double x, double vx, double y, double vy) : x(x), vx(vx), y(y), vy(vy) {}

	void step(double dt) {
		x += vx * dt;
		y += vy * dt;
		vx = vx;
		vy -= g * dt;

		if (x > squareMaxPosX) vx = -abs(vx);
		if (x < squareMinPosX) vx = abs(vx);
		if (y < squareMinPosY) vy = abs(vy);
	}

	void setObjColor() {
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
};

/*
	Class: Octagon
	Membentuk objek berupa segi delapan yang memiliki atribut berupa
	posisi awal objek (x, y) dan kecepatan gerak berdasarkan sumbu x (vx) dan sumbu y (vy)
*/
class Octagon {

public:

	GLfloat R = 0.0f, G = 0.0f, B = 0.0f;
	double x, vx, y, vy;

	Octagon(double x, double vx, double y, double vy) : x(x), vx(vx), y(y), vy(vy) {}

	void step(double dt) {
		x += vx * dt;
		y += vy * dt;
		vx = vx;
		vy -= g * dt;

		if (x > octagonMaxPosX) vx = -abs(vx);
		if (x < octagonMinPosX) vx = abs(vx);
		if (y < octagonMinPosY) vy = abs(vy);
	}

	void setObjColor() {
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
};


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

	// input bagian LINE
	cout << "[Line]" << endl;
	cout << "Jumlah line (garis): ";
	cin >> numLine;

	if (numLine < 0) {
		cout << "Input jumlah tidak valid. Jumlah line dibuat default: 1" << endl;
		numLine = 1;
	}

	if (numLine > 0) {
		cout << "Pewarnaan objek: 0. Random; 1. Tentukan sendiri --- [0/1]: ";
		cin >> fillColorLine;
	}

	cout << endl << endl;

	t = 0;
	step_number = 0;
}

/*
	Prosedur membentuk objek lingkaran
*/
Circle **circles;    // pointer to and array of ball pointers

void setUserCircle(int idx);

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


/*
	Prosedur membentuk objek kotak
*/
Square **squares;

void setUserSquare(int idx);

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

/*
Prosedur membentuk objek segi delapan
*/
Octagon **octagons;

void setUserOctagon(int idx);

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

// move each object by one time step dt
void step() {
	// circle
	for (int i = 0; i < numCircle; i++) {
		circles[i]->step(dt);
	}
	// square
	for (int i = 0; i < numSquare; i++) {
		squares[i]->step(dt);
	}
	// octagon
	for (int i = 0; i < numOctagon; i++) {
		octagons[i]->step(dt);
	}
	t += dt;
	++step_number;
}

/*
	Prosedur untuk mengecek bila terjadi tumbukan antar objek, maka
	arah gerak objek akan berubah
*/
void checkCollisionAct() {
	
	// cek tumbukan antara circle dengan kotak pemantul (bouncer)
	for (int i = 0; i < numCircle; i++) {
		if (sqrt(pow(circles[i]->x - sqBouncerPosX, 2) + pow(circles[i]->y + 1.0, 2)) <= 0.5) {
			// jika pantulan terjadi di bagian atas sisi kiri
			if (circles[i]->x < sqBouncerPosX) {
				circles[i]->vx = -abs(circles[i]->vx);
				circles[i]->vy = abs(circles[i]->vy);
			}
			// jika pantulan terjadi di bagian atas sisi kanan atau tengah
			else {
				circles[i]->vx = abs(circles[i]->vx);
				circles[i]->vy = abs(circles[i]->vy);
			}
		}
	}

	//o.5^2 + 0.1^2 = 1/4 + 1/100 = 26/100 = sqrt(26)/10 = 0.5

	// cek tumbukan antara circle dengan kotak
	for (int i = 0; i < numCircle; i++) {
		for (int j = 0; j < numSquare; j++) {
			if (sqrt(pow(circles[i]->x - squares[j]->x, 2) + pow(circles[i]->y - squares[j]->y, 2)) <= 0.24) {
				if (circles[i]->x < squares[j]->x && circles[i]->y > squares[j]->y) {
					circles[i]->vx = -abs(circles[i]->vx);
					circles[i]->vy = abs(circles[i]->vy);
					squares[j]->vx = abs(squares[j]->vx);
					squares[j]->vy = -abs(squares[j]->vy);
				}
				else if (circles[i]->x < squares[j]->x && circles[i]->y < squares[j]->y) {
					circles[i]->vx = -abs(circles[i]->vx);
					circles[i]->vy = -abs(circles[i]->vy);
					squares[j]->vx = abs(squares[j]->vx);
					squares[j]->vy = abs(squares[j]->vy);
				}
				else if (circles[i]->x > squares[j]->x && circles[i]->y < squares[j]->y) {
					circles[i]->vx = abs(circles[i]->vx);
					circles[i]->vy = -abs(circles[i]->vy);
					squares[j]->vx = -abs(squares[j]->vx);
					squares[j]->vy = abs(squares[j]->vy);
				}
				else if (circles[i]->x > squares[j]->x && circles[i]->y > squares[j]->y) {
					circles[i]->vx = abs(circles[i]->vx);
					circles[i]->vy = abs(circles[i]->vy);
					squares[j]->vx = -abs(squares[j]->vx);
					squares[j]->vy = -abs(squares[j]->vy);
				}
			}
		}
	}

	//0.1akar2 + 0.1 = 0.24

	// cek tumbukan antara circle dengan circle
	for (int i = 0; i < numCircle; i++) {
		for (int j = 0; j < numCircle; j++) {
			if (j != i) {
				if (sqrt(pow(circles[i]->x - circles[j]->x, 2) + pow(circles[i]->y - circles[j]->y, 2)) <= 0.2) {
					
					if (circles[i]->x < circles[j]->x && circles[i]->y < circles[j]->y) {
						circles[i]->vx = -abs(circles[i]->vx);
						circles[i]->vy = -abs(circles[i]->vy);
						circles[j]->vx = abs(circles[j]->vx);
						circles[j]->vy = abs(circles[j]->vy);
					}
					else if (circles[i]->x > circles[j]->x && circles[i]->y < circles[j]->y) {
						circles[i]->vx = abs(circles[i]->vx);
						circles[i]->vy = -abs(circles[i]->vy);
						circles[j]->vx = -abs(circles[j]->vx);
						circles[j]->vy = abs(circles[j]->vy);
					}
					else if (circles[i]->x > circles[j]->x && circles[i]->y > circles[j]->y) {
						circles[i]->vx = abs(circles[i]->vx);
						circles[i]->vy = abs(circles[i]->vx);
						circles[j]->vx = -abs(circles[j]->vx);
						circles[j]->vy = -abs(circles[j]->vy);
					}
					else if (circles[i]->x < circles[j]->x && circles[i]->y > circles[j]->y) {
						circles[i]->vx = -abs(circles[i]->vx);
						circles[i]->vy = abs(circles[i]->vy);
						circles[j]->vx = abs(circles[j]->vx);
						circles[j]->vy = -abs(circles[j]->vy);
					}

				}
			}
		}
	}
}

double frames_per_second = 30;   // for animation in real time

void animation_step() {
	double start = t;
	clock_t start_time = clock();
	step();
	double one_per_fsec = 1.0 / frames_per_second;
	while (t - start < one_per_fsec)

		// menggerakkan objek
		step();
	
		// melakukan pengecekan terhadap tumbukan antar objek
		checkCollisionAct();
	
	while ((double(clock()) - start_time) / CLOCKS_PER_SEC < one_per_fsec);
	glutPostRedisplay();
}

void drawText(const string &str, double x, double y) {
	glRasterPos2d(x, y);
	int len = str.find('\0');
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str[i]);
}

// Glut callback function to update the display
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);     // To operate on Model-View matrix
	glLoadIdentity();               // Reset the model-view matrix

	// membentuk objek numCircle buah lingkaran
	glPushMatrix();
	for (int i = 0; i < numCircle; i++) {
		glBegin(GL_TRIANGLE_FAN);
			// memilih warna objek 
			if (fillColorCircle == 0) {
				if (circles[i]->R == 0.0f && circles[i]->G == 0.0f && circles[i]->B == 0.0f) {
					circles[i]->setObjColor();
				}
			}
			glColor3f(circles[i]->R, circles[i]->G, circles[i]->B);
			glVertex2d(circles[i]->x, circles[i]->y);
			double phi = 2 * pi / 24;
			for (int j = 0; j < 25; j++)
				glVertex2d(circles[i]->x + 0.1 * cos(phi*j), circles[i]->y + 0.1 * sin(phi*j));
		glEnd();
	}
	glPopMatrix();

	// membentuk objek numSquare buah kotak
	glPushMatrix();
	for (int i = 0; i < numSquare; i++) {
		//glRotatef(angle, 1.0f, 1.0f, 0.0f); // rotate by angle in degrees
		glTranslatef(squares[i]->x, squares[i]->y, 0.0f);
		glBegin(GL_QUADS);
			// memilih warna objek
			if (fillColorSquare == 0) {
				if (squares[i]->R == 0.0f && squares[i]->G == 0.0f && squares[i]->B == 0.0f) {
					squares[i]->setObjColor();
				}
			}
			glColor3f(squares[i]->R, squares[i]->G, squares[i]->B);
			glVertex2f(-0.2f, 0.0f);
			glVertex2f(0.0f, 0.0f);
			glVertex2f(0.0f, 0.2f);
			glVertex2f(-0.2f, 0.2f);
		glEnd();
	}
	glPopMatrix();
	
	// membentuk objek numOctagon buah segi delapan
	glPushMatrix();
	for (int i = 0; i < numOctagon; i++) {
		glTranslatef(octagons[i]->x, octagons[i]->y, 0.0f);
		glBegin(GL_POLYGON);
			// memilih warna objek
			if (fillColorOctagon == 0) {
				if (octagons[i]->R == 0.0f && octagons[i]->G == 0.0f && octagons[i]->B == 0.0f) {
					octagons[i]->setObjColor();
				}
			}
			glColor3f(octagons[i]->R, octagons[i]->G, octagons[i]->B);
			glVertex2f(-0.2f, -0.2f);
			glVertex2f(-0.25f, -0.1f);
			glVertex2f(-0.2f, 0.0f);
			glVertex2f(-0.1f, 0.05f);
			glVertex2f(0.0f, 0.0f);
			glVertex2f(0.05f, -0.1f);
			glVertex2f(0.0f, -0.2f);
			glVertex2f(-0.1f, -0.25f);
		glEnd();
	}
	glPopMatrix();


	// 0.05^2 + 0.1^2 = 1/400 + 1/100 = sqrt(5/400) = sqrt(5)/20 
	// sqrt(5)/20 = 2x^2 - 2x^2cos45 
	// sqrt(5)/20 = 2x^2 - x^2sqrt(2) = x^2 (2 - sqrt(2))
	// x^2 = (sqrt(5/400)) / (2-sqrt(2))
	// x^2 = (sqrt(5/400)) / 0.59 = 0.19
	// x = sqrt(0.19) = 0.435

	// 0.44^2 - 5/1600 = 0.189 - 5/1600 = 0.186
	// sqrt(0.186) = 0.431


	/*
		Objek yang dibuat oleh aplikasi saat dijalankan (bukan dari user)
	*/
	// membentuk kotak abu-abu di tengah yang berotasi dan resize
	glPushMatrix();                     
	//glTranslatef(-0.7f, -0.5f, 0.0f);   
	glRotatef(angle, 0.0f, 0.0f, 1.0f); 
	glBegin(GL_QUADS);
		glColor3f(0.5f, 0.5f, 0.5f); 
		glVertex2f(-0.2f, 0.2f);
		glVertex2f(0.2f, 0.2f);
		glVertex2f(0.2f, 0.6f);
		glVertex2f(-0.2f, 0.6f);
	glEnd();
	glPopMatrix();                   

	// membentuk objek kotak pemantul abu-abu
	glPushMatrix();
	glTranslatef(sqBouncerPosX, sqBouncerPosY, 0.0f);
	glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(-0.5f, -1.0f);
		glVertex2f(0.5f, -1.0f);
		glVertex2f(0.5f, -0.8f);
		glVertex2f(-0.5f, -0.8f);
	glEnd();
	glPopMatrix();




	/////////////////////////////////////

	

	/////////////////////////////////////



	glutSwapBuffers();

	// perubahan sudut rotasi 
	angle += 2.0f;
}

// Glut callback function to reset the viewing transformation
void reshape(int w, int h) {
	GLfloat clipAreaXLeft, clipAreaXRight;
	GLfloat clipAreaYBottom, clipAreaYTop;

	GLfloat aspect = (GLfloat)w / (GLfloat)h;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w >= h) {
		clipAreaXLeft = -1.0f * aspect;
		clipAreaXRight = 1.0f * aspect;
		clipAreaYBottom = -1.0f;
		clipAreaYTop = 1.0f;
	}
	else {
		clipAreaXLeft = -1.0;
		clipAreaXRight = 1.0;
		clipAreaYBottom = -1.0f / aspect;
		clipAreaYTop = 1.0f / aspect;
	}

	gluOrtho2D(clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop);

	if (numCircle > 0) {
		circleMinPosX = clipAreaXLeft + 0.1f;
		circleMaxPosX = clipAreaXRight - 0.1f;
		circleMinPosY = clipAreaYBottom + 0.1f;
		circleMaxPosY = clipAreaYTop - 0.1f;
	}
	if (numSquare > 0) {
		squareMinPosX = clipAreaXLeft + 0.1f;
		squareMaxPosX = clipAreaXRight - 0.1f;
		squareMinPosY = clipAreaYBottom + 0.1f;
		squareMaxPosY = clipAreaYTop - 0.1f;
	}
	if (numOctagon > 0) {
		octagonMinPosX = clipAreaXLeft + 0.431f;
		octagonMaxPosX = clipAreaXRight - 0.431f;
		octagonMinPosY = clipAreaYBottom + 0.431f;
		octagonMaxPosY = clipAreaYTop - 0.431f;
	}

	


	//gluOrtho2D(-L, L, 0, L / w*(2.0*h));
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

bool running = false;   // is the animation running

// Glut mouse callback function
void mouse(int button, int state, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			if (running) {
				glutIdleFunc(NULL);
				running = false;
			}
			else {
				glutIdleFunc(animation_step);
				running = true;
			}
		}
	}
}

/* Callback handler for special-key event */
void specialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_F1:    // F1: Toggle between full-screen and windowed mode
		fullScreenMode = !fullScreenMode;         // Toggle state
		if (fullScreenMode) {                     // Full-screen mode
			windowPosX = glutGet(GLUT_WINDOW_X); // Save parameters for restoring later
			windowPosY = glutGet(GLUT_WINDOW_Y);
			windowWidth = glutGet(GLUT_WINDOW_WIDTH);
			windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
			glutFullScreen();                      // Switch into full screen
		}
		else {                                         // Windowed mode
			glutReshapeWindow(windowWidth, windowHeight); // Switch into windowed mode
			glutPositionWindow(windowPosX, windowPosX);   // Position top-left corner
		}
		break;
	case GLUT_KEY_RIGHT:    // Right: increase x speed
		sqBouncerPosX = sqBouncerPosX + 0.05f;
		break;
	case GLUT_KEY_LEFT:     // Left: decrease x speed
		sqBouncerPosX = sqBouncerPosX - 0.05f;
		break;

	}
}

void clearAlloc() {

	// deallocate circle's object allocation
	for (int i = 0; i < numCircle; i++) {
		delete[] circles[i];
	}
	delete[] circles;
	cout << "clear alloc for circle done" << endl;

	// deallocate square's object allocation
	for (int i = 0; i < numSquare; i++) {
		delete[] squares[i];
	}
	delete[] squares;
	cout << "clear alloc for square done" << endl;

	// deallocate octagon's object allocation
	for (int i = 0; i < numOctagon; i++) {
		delete[] octagons[i];
	}
	delete[] octagons;
	cout << "clear alloc for octagon done" << endl;
}

int main(int argc, char *argv[]) {

	glutInit(&argc, argv);

	getUserInput();

	create_circle();	// lingkaran
	create_square();	// kotak
	create_octagon();	// segi delapan

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(720, 540);

	glutInitWindowPosition(100, 100);
	glutCreateWindow("Bouncing Balls Animation");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_FLAT);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutSpecialFunc(specialKeys); // Register callback handler for special-key event

	glutMainLoop();

	clearAlloc();

}
