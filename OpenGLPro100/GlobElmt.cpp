/*
	GLOBAL VARIABLES
	Header implementation
*/

#include "GlobElmt.h"

// menyatakan apakah animasi sedang berjalan
bool running = false;

const double pi = 4 * atan(1.0);

// for animation in real time
double frames_per_second = 30;

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
int numSquare, numCircle, numOctagon;

// variabel yang menyimpan kecepatan gerak awal maksimum
double v_max = 1;

// variabel yang menyimpan nilai waktu gerak yang ada pada rumus v = s / t
double dt = 0.01;

// variabel yang menyimpan nilai waktu simulasi
double t;

int step_number;      // time step number

// variabel permainan
int isStart = 0;
int totalPoint = 0;
int currentPoint = 0;		// poin yang ditampilkan
int displayFinalState = 0;
float deltaTime = 12.00;

// variabel yang menyimpan apakah user ingin warna objek ditentukan sendiri atau random
int fillColorSquare, fillColorCircle, fillColorOctagon, fillColorLine;

// variabel yang menyimpan posisi hasil translasi untuk kotak pemantul
GLfloat sqBouncerPosX = 0.0f, sqBouncerPosY = 0.0f;

// variabel yang menyimpan posisi hasil translasi garis penjaga kotak abu-abu tengah
GLfloat sqGatePosXM = 0.0f, sqGatePosYM = 0.0f;
GLfloat sqGatePosX0 = -0.575f, sqGatePosY0 = 0.0f;
GLfloat sqGatePosX1 = 0.575f, sqGatePosY1 = 0.0f;
char stateGate = 'L';

// variabel yang menyimpan batas-batas daerah untuk menampilkan objek
GLfloat circleMinPosX, circleMaxPosX, circleMinPosY, circleMaxPosY;
GLfloat squareMinPosX, squareMaxPosX, squareMinPosY, squareMaxPosY;
GLfloat octagonMinPosX, octagonMaxPosX, octagonMinPosY, octagonMaxPosY;
GLfloat splitterMinPosX, splitterMaxPosX;

// sudut rotasi kotak abu-abu penanda total poin dan sisa waktu
GLfloat angle = 0.0f;

// jari-jari lingkaran
GLfloat circleRadius = 0.1f;



