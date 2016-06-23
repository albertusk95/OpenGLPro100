/*
	OpenGLPro100
	Menampilkan beberapa objek bangun dasar seperti garis, kotak, lingkaran, dan segi-8.

	Author: Albertus Kelvin / 13514100
*/

#include "GlobElmt.h"		// global variables
#include "GlobObj.h"		// global objects

#include "UserInteract.h"	// interaksi dengan user

#include "Circle.h"			// class circle
#include "Square.h"			// class square
#include "Octagon.h"		// class octagon

#include "ObjectCreation.h"	// pembentukan objek

#include "Animation.h"		// fungsi animasi

#include "GLRegFunc.h"		// fungsi registrasi GL

using namespace std;

// Prosedur dealokasi memori untuk pembentukan objek
void clearAlloc();

// Prosedur menampilkan objek yang dipanggil oleh sistem setiap ada event baru
void display();

// Prosedur reshape window setelah menangkap suatu event yang berhubungan dengan window
void reshape(int w, int h);

// Callback handler for normal-key event 
void keyboard(unsigned char key, int x, int y);

// Glut mouse callback function
void mouse(int button, int state, int x, int y);

// Callback handler for special-key event 
void specialKeys(int key, int x, int y);

/*
	Fungsi utama
*/
int main(int argc, char *argv[]) {

	glutInit(&argc, argv);

	getUserInput();

	if (numCircle > 0) {
		create_circle();	// lingkaran
	}
	if (numSquare > 0) {
		create_square();	// kotak
	}
	if (numOctagon > 0) {
		create_octagon();	// segi delapan
	}

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(880, 660);

	glutInitWindowPosition(100, 120);
	glutCreateWindow("OpenGLPro100");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_FLAT);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);   // Register callback handler for special-key event
	glutSpecialFunc(specialKeys); // Register callback handler for special-key event

	glutMainLoop();

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

	char aaa;
	cout << "aaa: ";
	cin >> aaa;
}

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
			glVertex2d(circles[i]->x + circleRadius * cos(phi*j), circles[i]->y + circleRadius * sin(phi*j));
		glEnd();
	}
	glPopMatrix();

	// membentuk objek numSquare buah kotak
	glPushMatrix();
	for (int i = 0; i < numSquare; i++) {
		//glTranslatef(squares[i]->x, squares[i]->y, 0.0f);
		//glRotatef(angle, 0.0f, 0.0f, 1.0f); 
		glBegin(GL_QUADS);
		// memilih warna objek
		if (fillColorSquare == 0) {
			if (squares[i]->R == 0.0f && squares[i]->G == 0.0f && squares[i]->B == 0.0f) {
				squares[i]->setObjColor();
			}
		}
		glColor3f(squares[i]->R, squares[i]->G, squares[i]->B);

		/*
		glVertex2f(-0.2f, 0.0f);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.0f, 0.2f);
		glVertex2f(-0.2f, 0.2f);
		*/

		glVertex2f((float)squares[i]->x - 0.1f, (float)squares[i]->y - 0.1f);
		glVertex2f((float)squares[i]->x + 0.1f, (float)squares[i]->y - 0.1f);
		glVertex2f((float)squares[i]->x + 0.1f, (float)squares[i]->y + 0.1f);
		glVertex2f((float)squares[i]->x - 0.1f, (float)squares[i]->y + 0.1f);

		glEnd();
	}
	glPopMatrix();

	// membentuk objek numOctagon buah segi delapan
	glPushMatrix();
	for (int i = 0; i < numOctagon; i++) {
		//glTranslatef(octagons[i]->x, octagons[i]->y, 0.0f);
		glBegin(GL_POLYGON);
		// memilih warna objek
		if (fillColorOctagon == 0) {
			if (octagons[i]->R == 0.0f && octagons[i]->G == 0.0f && octagons[i]->B == 0.0f) {
				octagons[i]->setObjColor();
			}
		}
		glColor3f(octagons[i]->R, octagons[i]->G, octagons[i]->B);
		/*
		glVertex2f(-0.2f, -0.2f);
		glVertex2f(-0.25f, -0.1f);
		glVertex2f(-0.2f, 0.0f);
		glVertex2f(-0.1f, 0.05f);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.05f, -0.1f);
		glVertex2f(0.0f, -0.2f);
		glVertex2f(-0.1f, -0.25f);
		*/

		glVertex2f((float)octagons[i]->x - 0.1f, (float)octagons[i]->y - 0.1f);
		glVertex2f((float)octagons[i]->x - 0.15f, (float)octagons[i]->y);
		glVertex2f((float)octagons[i]->x - 0.1f, (float)octagons[i]->y + 0.1f);
		glVertex2f((float)octagons[i]->x, (float)octagons[i]->y + 0.15f);
		glVertex2f((float)octagons[i]->x + 0.1f, (float)octagons[i]->y + 0.1f);
		glVertex2f((float)octagons[i]->x + 0.15f, (float)octagons[i]->y);
		glVertex2f((float)octagons[i]->x + 0.1f, (float)octagons[i]->y - 0.1f);
		glVertex2f((float)octagons[i]->x, (float)octagons[i]->y - 0.15f);
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

	// sqr(0.15)*2 - sqr(0.15)sqrt(2) = 0.045 - 0.032 = 0.013
	// sqrt(0.013) = 0.114
	// 0.15*0.15 - 0.057*0.057 = 0.019
	// sqrt(0.019) = 0.14

	/*
	Objek yang dibuat oleh aplikasi saat dijalankan (bukan dari user)
	*/

	// posisi titik awal dan akhir garis pertama
	GLfloat firstlineSEPoint[] =
	{
		-0.9f, 0.0f, 0.0f,
		-0.25f, 0.0f, 0.0f
	}; // mid point = -0.575

	// posisi titik awal dan akhir garis kedua
	GLfloat secondlineSEPoint[] =
	{
		0.25f, 0.0f, 0.0f,
		0.9f, 0.0f, 0.0f
	}; // mid point = 0.575

	// membentuk 1 buah garis sambung dan 1 buah garis putus di tengah window
	glPushMatrix();
	glTranslatef(sqGatePosXM, sqGatePosYM, 0.0f);
	glColor3f(1.0f, 0.3f, 0.3f);
	glEnable(GL_LINE_SMOOTH);
	//glEnable(GL_LINE_STIPPLE);
	glPushAttrib(GL_LINE_BIT);
	glLineWidth(10);
	//glLineStipple(1, 0x00FF);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, firstlineSEPoint);
	glDrawArrays(GL_LINES, 0, 2);

	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x00FF);
	glVertexPointer(3, GL_FLOAT, 0, secondlineSEPoint);
	glDrawArrays(GL_LINES, 0, 2);
	glDisableClientState(GL_VERTEX_ARRAY);
	glPopAttrib();
	glDisable(GL_LINE_STIPPLE);
	glDisable(GL_LINE_SMOOTH);
	glPopMatrix();

	// membentuk kotak abu-abu di bagian kiri atas yang berotasi sebagai penanda total point
	glPushMatrix();
	glTranslatef(-1.0f, 0.7f, 0.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(-0.15f, -0.15f);
	glVertex2f(0.15f, -0.15f);
	glVertex2f(0.15f, 0.15f);
	glVertex2f(-0.15f, 0.15f);
	glEnd();
	glPopMatrix();

	// membentuk kotak abu-abu di bagian kanan atas yang berotasi sebagai penanda waktu
	glPushMatrix();
	glTranslatef(1.0f, 0.7f, 0.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(-0.15f, -0.15f);
	glVertex2f(0.15f, -0.15f);
	glVertex2f(0.15f, 0.15f);
	glVertex2f(-0.15f, 0.15f);
	glEnd();
	glPopMatrix();

	// membentuk objek kotak pemantul abu-abu
	glPushMatrix();
	glTranslatef(sqBouncerPosX, sqBouncerPosY, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex2f(-0.5f, -1.0f);
	glVertex2f(0.5f, -1.0f);
	glVertex2f(0.5f, -0.8f);
	glVertex2f(-0.5f, -0.8f);
	glEnd();
	glPopMatrix();

	// membentuk teks sebelum permainan berjalan
	if (isStart == 0) {
		string txt_intro0 = "Klik di sembarang tempat untuk memulai permainan.";
		string txt_intro1 = "Anda menang jika dapat mencapai total poin sebesar";
		string txt_intro2 = to_string(totalPoint);
		glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		drawText(txt_intro0.data(), txt_intro0.size(), -0.57, 0.75, "GLUT_BITMAP_HELVETICA_18");
		drawText(txt_intro1.data(), txt_intro1.size(), -0.58, 0.6, "GLUT_BITMAP_HELVETICA_18");
		drawText(txt_intro2.data(), txt_intro2.size(), 0.0, 0.45, "GLUT_BITMAP_TIMES_ROMAN_24");
		glPopMatrix();
	}

	// membentuk teks selama permainan berjalan: point saat ini dan sisa waktu
	if (deltaTime >= -0.02f) {
		string txt_currentPoint, txt_titlecPoint = "Point"; // variabel teks milik point saat ini
		string txt_deltaTime, txt_titledT = "Time"; // variabel teks milik sisa waktu
		stringstream stream_deltaTime;
		if (deltaTime <= 0.0f) {
			deltaTime = 0.0f;
		}
		glPushMatrix();

		// bagian sisa waktu
		stream_deltaTime << fixed << setprecision(2) << deltaTime;
		txt_deltaTime = stream_deltaTime.str();
		glColor3f(0.0f, 0.0f, 0.0f);
		drawText(txt_titledT.data(), txt_titledT.size(), 0.93, 0.75, "GLUT_BITMAP_HELVETICA_18");
		drawText(txt_deltaTime.data(), txt_deltaTime.size(), 0.91, 0.65, "GLUT_BITMAP_TIMES_ROMAN_24");

		// bagian poin saat ini
		txt_currentPoint = to_string(currentPoint);
		glColor3f(0.0f, 0.0f, 0.0f);
		drawText(txt_titlecPoint.data(), txt_titlecPoint.size(), -1.09, 0.75, "GLUT_BITMAP_HELVETICA_18");
		drawText(txt_currentPoint.data(), txt_currentPoint.size(), -1.03, 0.65, "GLUT_BITMAP_TIMES_ROMAN_24");

		glPopMatrix();
	}

	// final state check
	if (deltaTime <= 0.0f) {
		string txt_finalpoint;
		string txt_finalres;

		glPushMatrix();
		txt_finalpoint = to_string(currentPoint);
		if (currentPoint > 0) {
			txt_finalres = "YOU WIN";
		}
		else {
			txt_finalres = "YOU LOSE";
		}
		glColor3f(1.0f, 1.0f, 1.0f);
		drawText(txt_finalres.data(), txt_finalres.size(), -0.2, 0.5, "GLUT_BITMAP_TIMES_ROMAN_24");
		drawText(txt_finalpoint.data(), txt_finalpoint.size(), -0.07, 0.25, "GLUT_BITMAP_TIMES_ROMAN_24");
		glPopMatrix();
		deltaTime = 0.0f;
		if (displayFinalState == 1) {
			clearAlloc();
			exit(0);
		}
	}


	glutSwapBuffers();


	// perubahan sudut rotasi 
	angle += 2.0f;
}

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
		circleMinPosX = clipAreaXLeft + circleRadius;
		circleMaxPosX = clipAreaXRight - circleRadius;
		circleMinPosY = clipAreaYBottom + circleRadius;
		circleMaxPosY = clipAreaYTop - circleRadius;
	}
	if (numSquare > 0) {
		squareMinPosX = clipAreaXLeft + 0.1f;
		squareMaxPosX = clipAreaXRight - 0.1f;
		squareMinPosY = clipAreaYBottom + 0.1f;
		squareMaxPosY = clipAreaYTop - 0.1f;
	}
	if (numOctagon > 0) {
		octagonMinPosX = clipAreaXLeft + 0.14f;
		octagonMaxPosX = clipAreaXRight - 0.14f;
		octagonMinPosY = clipAreaYBottom + 0.14f;
		octagonMaxPosY = clipAreaYTop - 0.14f;
	}

	splitterMinPosX = clipAreaXLeft + 0.65f;
	splitterMaxPosX = clipAreaXRight - 0.65f;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27:     // ESC key
		clearAlloc();
		exit(0);
		break;
	}
}

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
				isStart = 1;
			}
		}
	}
}

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
