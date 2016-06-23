/*
	Animation
	Header definition
*/

#include "GlobElmt.h"
#include "GlobObj.h"

#ifndef Animation_h
#define Animation_h

// mengecek apakah objek saling bertumbukkan
void checkCollisionAct();

// move each object by one time step dt
void step();

// Prosedur menggerakkan 2 buah garis di tengah window
void stepSplitLine();

// prosedur menjalankan semua animasi
void animation_step();

#endif

