/*
	GLRegFunc
	Header implementation
*/

#include "GLRegFunc.h"

void drawText(const char *str, int len_str, double x, double y, string GLUT_BITMAP_TYPE) {
	glRasterPos2d(x, y);
	for (int i = 0; i < len_str; i++)
		if (GLUT_BITMAP_TYPE == "GLUT_BITMAP_TIMES_ROMAN_24") {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)str[i]);
		}
		else {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, (int)str[i]);
		}
}
