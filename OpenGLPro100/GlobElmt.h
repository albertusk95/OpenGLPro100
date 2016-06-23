/*
	GLOBAL VARIABLES 
	Header definition
*/

#include "LibraryInc.h"

#ifndef GlobElmt_h
#define GlobElmt_h

// menyatakan apakah animasi sedang berjalan
extern bool running;

extern const double pi;

// for animation in real time
extern double frames_per_second;

// asumsi nilai gravitasi
extern const double g;

// variabel yang menyatakan status window apakah dalam fullscreen atau tidak
extern bool fullScreenMode;

// variabel yang menyimpan nilai panjang dan lebar window
extern int windowWidth;
extern int windowHeight;

// variabel yang menyimpan nilai posisi titik ujung kiri atas saat aplikasi pertama kali dijalankan
extern int windowPosX;
extern int windowPosY;

// variabel yang menyimpan jumlah masing-masing objek yang dibentuk
extern int numSquare, numCircle, numOctagon;

// variabel yang menyimpan kecepatan gerak awal maksimum
extern double v_max;

// variabel yang menyimpan nilai waktu gerak yang ada pada rumus v = s / t
extern double dt;

// variabel yang menyimpan nilai waktu simulasi
extern double t;

// time step number
extern int step_number;      

// variabel permainan
extern int isStart;
extern int totalPoint;
extern int currentPoint;		// poin yang ditampilkan
extern int displayFinalState;
extern float deltaTime;

// variabel yang menyimpan apakah user ingin warna objek ditentukan sendiri atau random
extern int fillColorSquare, fillColorCircle, fillColorOctagon, fillColorLine;

// variabel yang menyimpan posisi hasil translasi untuk kotak pemantul
extern GLfloat sqBouncerPosX, sqBouncerPosY;

// variabel yang menyimpan posisi hasil translasi garis penjaga kotak abu-abu tengah
extern GLfloat sqGatePosXM, sqGatePosYM;
extern GLfloat sqGatePosX0, sqGatePosY0;
extern GLfloat sqGatePosX1, sqGatePosY1;
extern char stateGate;

// variabel yang menyimpan batas-batas daerah untuk menampilkan objek
extern GLfloat circleMinPosX, circleMaxPosX, circleMinPosY, circleMaxPosY;
extern GLfloat squareMinPosX, squareMaxPosX, squareMinPosY, squareMaxPosY;
extern GLfloat octagonMinPosX, octagonMaxPosX, octagonMinPosY, octagonMaxPosY;
extern GLfloat splitterMinPosX, splitterMaxPosX;

// sudut rotasi kotak abu-abu penanda total poin dan sisa waktu
extern GLfloat angle;

// jari-jari lingkaran
extern GLfloat circleRadius;

#endif
