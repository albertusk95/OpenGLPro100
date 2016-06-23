/*
	Animation
	Header implementation
*/

#include "Animation.h"

/*
	Prosedur untuk mengecek bila terjadi tumbukan antar objek, maka
	arah gerak objek akan berubah
*/
void checkCollisionAct() {

	/*
	OCTAGON COLLISION CONTROLLER
	*/

	// cek tumbukan antara octagon dengan kotak pemantul (bouncer)
	for (int i = 0; i < numOctagon; i++) {
		if (sqrt(pow(octagons[i]->x - sqBouncerPosX, 2) + pow(octagons[i]->y + 1.0, 2)) <= sqrt(pow(0.5, 2) + pow(0.15, 2))) {
			currentPoint = currentPoint + 3;
			// jika pantulan terjadi di bagian atas sisi kiri
			if (octagons[i]->x < sqBouncerPosX) {
				octagons[i]->vx = -abs(octagons[i]->vx);
				octagons[i]->vy = abs(octagons[i]->vy);
			}
			// jika pantulan terjadi di bagian atas sisi kanan atau tengah
			else {
				octagons[i]->vx = abs(octagons[i]->vx);
				octagons[i]->vy = abs(octagons[i]->vy);
			}
		}
	}

	// cek tumbukan antara octagon dengan garis tengah window
	for (int i = 0; i < numOctagon; i++) {
		/*
		Garis tengah bagian kiri
		*/
		// jika octagon berada dalam lingkup garis tengah berdasarkan sumbu x
		if (octagons[i]->x > sqGatePosX0 - 0.325 && octagons[i]->x < sqGatePosX0 + 0.325) {
			// jika octagon berada dalam posisi dekat dengan garis tengah dilihat dari sumbu y
			if (abs(octagons[i]->y - sqGatePosY0) <= 0.15) {
				// octagon bertumbukan dengan garis tengah bagian kiri
				if (octagons[i]->x < sqGatePosX0 && octagons[i]->y < sqGatePosY0) {
					octagons[i]->vx = -abs(octagons[i]->vx);
					octagons[i]->vy = -abs(octagons[i]->vy);
				}
				else if (octagons[i]->x > sqGatePosX0 && octagons[i]->y < sqGatePosY0) {
					octagons[i]->vx = abs(octagons[i]->vx);
					octagons[i]->vy = -abs(octagons[i]->vy);
				}
				else if (octagons[i]->x < sqGatePosX0 && octagons[i]->y > sqGatePosY0) {
					octagons[i]->vx = -abs(octagons[i]->vx);
					octagons[i]->vy = abs(octagons[i]->vy);
				}
				else if (octagons[i]->x > sqGatePosX0 && octagons[i]->y > sqGatePosY0) {
					octagons[i]->vx = abs(octagons[i]->vx);
					octagons[i]->vy = abs(octagons[i]->vy);
				}
			}
		}

		/*
		Garis tengah bagian kanan
		*/
		// jika octagon berada dalam lingkup garis tengah berdasarkan sumbu x
		if (octagons[i]->x > sqGatePosX1 - 0.325 && octagons[i]->x < sqGatePosX1 + 0.325) {
			// jika octagon berada dalam posisi dekat dengan garis tengah dilihat dari sumbu y
			if (abs(octagons[i]->y - sqGatePosY1) <= 0.15) {
				// octagon bertumbukan dengan garis tengah bagian kanan
				if (octagons[i]->x < sqGatePosX1 && octagons[i]->y < sqGatePosY1) {
					octagons[i]->vx = -abs(octagons[i]->vx);
					octagons[i]->vy = -abs(octagons[i]->vy);
				}
				else if (octagons[i]->x > sqGatePosX1 && octagons[i]->y < sqGatePosY1) {
					octagons[i]->vx = abs(octagons[i]->vx);
					octagons[i]->vy = -abs(octagons[i]->vy);
				}
				else if (octagons[i]->x < sqGatePosX1 && octagons[i]->y > sqGatePosY1) {
					octagons[i]->vx = -abs(octagons[i]->vx);
					octagons[i]->vy = abs(octagons[i]->vy);
				}
				else if (octagons[i]->x > sqGatePosX1 && octagons[i]->y > sqGatePosY1) {
					octagons[i]->vx = abs(octagons[i]->vx);
					octagons[i]->vy = abs(octagons[i]->vy);
				}
			}
		}
	}

	// cek tumbukan antara octagon dengan octagon
	for (int i = 0; i < numOctagon; i++) {
		for (int j = 0; j < numOctagon; j++) {
			if (j != i) {
				if (sqrt(pow(octagons[i]->x - octagons[j]->x, 2) + pow(octagons[i]->y - octagons[j]->y, 2)) <= 2 * 0.15) {
					if (octagons[i]->x < octagons[j]->x && octagons[i]->y < octagons[j]->y) {
						octagons[i]->vx = -abs(octagons[i]->vx);
						octagons[i]->vy = -abs(octagons[i]->vy);
						octagons[j]->vx = abs(octagons[j]->vx);
						octagons[j]->vy = abs(octagons[j]->vy);
					}
					else if (octagons[i]->x > octagons[j]->x && octagons[i]->y < octagons[j]->y) {
						octagons[i]->vx = abs(octagons[i]->vx);
						octagons[i]->vy = -abs(octagons[i]->vy);
						octagons[j]->vx = -abs(octagons[j]->vx);
						octagons[j]->vy = abs(octagons[j]->vy);
					}
					else if (octagons[i]->x > octagons[j]->x && octagons[i]->y > octagons[j]->y) {
						octagons[i]->vx = abs(octagons[i]->vx);
						octagons[i]->vy = abs(octagons[i]->vx);
						octagons[j]->vx = -abs(octagons[j]->vx);
						octagons[j]->vy = -abs(octagons[j]->vy);
					}
					else if (octagons[i]->x < octagons[j]->x && octagons[i]->y > octagons[j]->y) {
						octagons[i]->vx = -abs(octagons[i]->vx);
						octagons[i]->vy = abs(octagons[i]->vy);
						octagons[j]->vx = abs(octagons[j]->vx);
						octagons[j]->vy = -abs(octagons[j]->vy);
					}
				}
			}
		}
	}

	/*
	SQUARE COLLISION CONTROLLER
	*/

	// cek tumbukan antara square dengan kotak pemantul (bouncer)
	for (int i = 0; i < numSquare; i++) {
		if (sqrt(pow(squares[i]->x - sqBouncerPosX, 2) + pow(squares[i]->y + 1.0, 2)) <= sqrt(pow(0.5, 2) + pow(0.1, 2))) {
			currentPoint = currentPoint + 3;
			// jika pantulan terjadi di bagian atas sisi kiri
			if (squares[i]->x < sqBouncerPosX) {
				squares[i]->vx = -abs(squares[i]->vx);
				squares[i]->vy = abs(squares[i]->vy);
			}
			// jika pantulan terjadi di bagian atas sisi kanan atau tengah
			else {
				squares[i]->vx = abs(squares[i]->vx);
				squares[i]->vy = abs(squares[i]->vy);
			}
		}
	}

	// cek tumbukan antara square dengan garis tengah window
	for (int i = 0; i < numSquare; i++) {
		/*
		Garis tengah bagian kiri
		*/
		// jika square berada dalam lingkup garis tengah berdasarkan sumbu x
		if (squares[i]->x > sqGatePosX0 - 0.325 && squares[i]->x < sqGatePosX0 + 0.325) {
			// jika square berada dalam posisi dekat dengan garis tengah dilihat dari sumbu y
			if (abs(squares[i]->y - sqGatePosY0) <= 0.1) {
				// square bertumbukan dengan garis tengah bagian kiri
				if (squares[i]->x < sqGatePosX0 && squares[i]->y < sqGatePosY0) {
					squares[i]->vx = -abs(squares[i]->vx);
					squares[i]->vy = -abs(squares[i]->vy);
				}
				else if (squares[i]->x > sqGatePosX0 && squares[i]->y < sqGatePosY0) {
					squares[i]->vx = abs(squares[i]->vx);
					squares[i]->vy = -abs(squares[i]->vy);
				}
				else if (squares[i]->x < sqGatePosX0 && squares[i]->y > sqGatePosY0) {
					squares[i]->vx = -abs(squares[i]->vx);
					squares[i]->vy = abs(squares[i]->vy);
				}
				else if (squares[i]->x > sqGatePosX0 && squares[i]->y > sqGatePosY0) {
					squares[i]->vx = abs(squares[i]->vx);
					squares[i]->vy = abs(squares[i]->vy);
				}
			}
		}

		/*
		Garis tengah bagian kanan
		*/
		// jika square berada dalam lingkup garis tengah berdasarkan sumbu x
		if (squares[i]->x > sqGatePosX1 - 0.325 && squares[i]->x < sqGatePosX1 + 0.325) {
			// jika square berada dalam posisi dekat dengan garis tengah dilihat dari sumbu y
			if (abs(squares[i]->y - sqGatePosY1) <= 0.1) {
				// square bertumbukan dengan garis tengah bagian kanan
				if (squares[i]->x < sqGatePosX1 && squares[i]->y < sqGatePosY1) {
					squares[i]->vx = -abs(squares[i]->vx);
					squares[i]->vy = -abs(squares[i]->vy);
				}
				else if (squares[i]->x > sqGatePosX1 && squares[i]->y < sqGatePosY1) {
					squares[i]->vx = abs(squares[i]->vx);
					squares[i]->vy = -abs(squares[i]->vy);
				}
				else if (squares[i]->x < sqGatePosX1 && squares[i]->y > sqGatePosY1) {
					squares[i]->vx = -abs(squares[i]->vx);
					squares[i]->vy = abs(squares[i]->vy);
				}
				else if (squares[i]->x > sqGatePosX1 && squares[i]->y > sqGatePosY1) {
					squares[i]->vx = abs(squares[i]->vx);
					squares[i]->vy = abs(squares[i]->vy);
				}
			}
		}
	}

	// cek tumbukan antara square dengan octagon
	for (int i = 0; i < numSquare; i++) {
		for (int j = 0; j < numOctagon; j++) {
			if (sqrt(pow(squares[i]->x - octagons[j]->x, 2) + pow(squares[i]->y - octagons[j]->y, 2)) <= (0.1*sqrt(2)) + 0.15) {
				if (squares[i]->x < octagons[j]->x && squares[i]->y < octagons[j]->y) {
					squares[i]->vx = -abs(squares[i]->vx);
					squares[i]->vy = -abs(squares[i]->vy);
					octagons[j]->vx = abs(octagons[j]->vx);
					octagons[j]->vy = abs(octagons[j]->vy);
				}
				else if (squares[i]->x > octagons[j]->x && squares[i]->y < octagons[j]->y) {
					squares[i]->vx = abs(squares[i]->vx);
					squares[i]->vy = -abs(squares[i]->vy);
					octagons[j]->vx = -abs(octagons[j]->vx);
					octagons[j]->vy = abs(octagons[j]->vy);
				}
				else if (squares[i]->x > octagons[j]->x && squares[i]->y > octagons[j]->y) {
					squares[i]->vx = abs(squares[i]->vx);
					squares[i]->vy = abs(squares[i]->vx);
					octagons[j]->vx = -abs(octagons[j]->vx);
					octagons[j]->vy = -abs(octagons[j]->vy);
				}
				else if (squares[i]->x < octagons[j]->x && squares[i]->y > octagons[j]->y) {
					squares[i]->vx = -abs(squares[i]->vx);
					squares[i]->vy = abs(squares[i]->vy);
					octagons[j]->vx = abs(octagons[j]->vx);
					octagons[j]->vy = -abs(octagons[j]->vy);
				}
			}
		}
	}

	// cek tumbukan antara square dengan square
	for (int i = 0; i < numSquare; i++) {
		for (int j = 0; j < numSquare; j++) {
			if (j != i) {
				if (sqrt(pow(squares[i]->x - squares[j]->x, 2) + pow(squares[i]->y - squares[j]->y, 2)) <= 2 * 0.1) {
					if (squares[i]->x < squares[j]->x && squares[i]->y < squares[j]->y) {
						squares[i]->vx = -abs(squares[i]->vx);
						squares[i]->vy = -abs(squares[i]->vy);
						squares[j]->vx = abs(squares[j]->vx);
						squares[j]->vy = abs(squares[j]->vy);
					}
					else if (squares[i]->x > squares[j]->x && squares[i]->y < squares[j]->y) {
						squares[i]->vx = abs(squares[i]->vx);
						squares[i]->vy = -abs(squares[i]->vy);
						squares[j]->vx = -abs(squares[j]->vx);
						squares[j]->vy = abs(squares[j]->vy);
					}
					else if (squares[i]->x > squares[j]->x && squares[i]->y > squares[j]->y) {
						squares[i]->vx = abs(squares[i]->vx);
						squares[i]->vy = abs(squares[i]->vx);
						squares[j]->vx = -abs(squares[j]->vx);
						squares[j]->vy = -abs(squares[j]->vy);
					}
					else if (squares[i]->x < squares[j]->x && squares[i]->y > squares[j]->y) {
						squares[i]->vx = -abs(squares[i]->vx);
						squares[i]->vy = abs(squares[i]->vy);
						squares[j]->vx = abs(squares[j]->vx);
						squares[j]->vy = -abs(squares[j]->vy);
					}
				}
			}
		}
	}

	/*
	CIRCLE COLLISION CONTROLLER
	*/

	// cek tumbukan antara circle dengan kotak pemantul (bouncer)
	for (int i = 0; i < numCircle; i++) {
		if (sqrt(pow(circles[i]->x - sqBouncerPosX, 2) + pow(circles[i]->y + 1.0, 2)) <= sqrt(pow(0.5, 2) + pow(circleRadius, 2))) {
			currentPoint = currentPoint + 3;
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

	// cek tumbukan antara circle dengan garis tengah window
	for (int i = 0; i < numCircle; i++) {
		/*
		Garis tengah bagian kiri
		*/
		// jika circle berada dalam lingkup garis tengah berdasarkan sumbu x
		if (circles[i]->x > sqGatePosX0 - 0.325 && circles[i]->x < sqGatePosX0 + 0.325) {
			// jika circle berada dalam posisi dekat dengan garis tengah dilihat dari sumbu y
			if (abs(circles[i]->y - sqGatePosY0) <= circleRadius) {
				// circle bertumbukan dengan garis tengah bagian kiri
				if (circles[i]->x < sqGatePosX0 && circles[i]->y < sqGatePosY0) {
					circles[i]->vx = -abs(circles[i]->vx);
					circles[i]->vy = -abs(circles[i]->vy);
				}
				else if (circles[i]->x > sqGatePosX0 && circles[i]->y < sqGatePosY0) {
					circles[i]->vx = abs(circles[i]->vx);
					circles[i]->vy = -abs(circles[i]->vy);
				}
				else if (circles[i]->x < sqGatePosX0 && circles[i]->y > sqGatePosY0) {
					circles[i]->vx = -abs(circles[i]->vx);
					circles[i]->vy = abs(circles[i]->vy);
				}
				else if (circles[i]->x > sqGatePosX0 && circles[i]->y > sqGatePosY0) {
					circles[i]->vx = abs(circles[i]->vx);
					circles[i]->vy = abs(circles[i]->vy);
				}
			}
		}

		/*
		Garis tengah bagian kanan
		*/
		// jika circle berada dalam lingkup garis tengah berdasarkan sumbu x
		if (circles[i]->x > sqGatePosX1 - 0.325 && circles[i]->x < sqGatePosX1 + 0.325) {
			// jika circle berada dalam posisi dekat dengan garis tengah dilihat dari sumbu y
			if (abs(circles[i]->y - sqGatePosY1) <= circleRadius) {
				// circle bertumbukan dengan garis tengah bagian kanan
				if (circles[i]->x < sqGatePosX1 && circles[i]->y < sqGatePosY1) {
					circles[i]->vx = -abs(circles[i]->vx);
					circles[i]->vy = -abs(circles[i]->vy);
				}
				else if (circles[i]->x > sqGatePosX1 && circles[i]->y < sqGatePosY1) {
					circles[i]->vx = abs(circles[i]->vx);
					circles[i]->vy = -abs(circles[i]->vy);
				}
				else if (circles[i]->x < sqGatePosX1 && circles[i]->y > sqGatePosY1) {
					circles[i]->vx = -abs(circles[i]->vx);
					circles[i]->vy = abs(circles[i]->vy);
				}
				else if (circles[i]->x > sqGatePosX1 && circles[i]->y > sqGatePosY1) {
					circles[i]->vx = abs(circles[i]->vx);
					circles[i]->vy = abs(circles[i]->vy);
				}
			}
		}
	}

	// cek tumbukan antara circle dengan kotak
	for (int i = 0; i < numCircle; i++) {
		for (int j = 0; j < numSquare; j++) {
			if (sqrt(pow(circles[i]->x - squares[j]->x, 2) + pow(circles[i]->y - squares[j]->y, 2)) <= (0.1*sqrt(2)) + circleRadius) {
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

	// cek tumbukan antara circle dengan octagon
	for (int i = 0; i < numCircle; i++) {
		for (int j = 0; j < numOctagon; j++) {
			if (sqrt(pow(circles[i]->x - octagons[j]->x, 2) + pow(circles[i]->y - octagons[j]->y, 2)) <= 0.431 + circleRadius) {
				if (circles[i]->x < octagons[j]->x && circles[i]->y < octagons[j]->y) {
					circles[i]->vx = -abs(circles[i]->vx);
					circles[i]->vy = -abs(circles[j]->vy);
					octagons[j]->vx = abs(octagons[j]->vx);
					octagons[j]->vy = abs(octagons[j]->vy);
				}
				else if (circles[i]->x < octagons[j]->x && circles[i]->y > octagons[j]->y) {
					circles[i]->vx = -abs(circles[i]->vx);
					circles[i]->vy = abs(circles[i]->vy);
					octagons[j]->vx = abs(octagons[j]->vx);
					octagons[j]->vy = -abs(octagons[j]->vy);
				}
				else if (circles[i]->x > octagons[j]->x && circles[i]->y < octagons[j]->y) {
					circles[i]->vx = abs(circles[i]->vx);
					circles[i]->vy = -abs(circles[i]->vy);
					octagons[j]->vx = -abs(octagons[j]->vx);
					octagons[j]->vy = abs(octagons[j]->vy);
				}
				else if (circles[i]->x > octagons[j]->x && circles[i]->y > octagons[j]->y) {
					circles[i]->vx = abs(circles[i]->vx);
					circles[i]->vy = abs(circles[i]->vy);
					octagons[j]->vx = -abs(octagons[j]->vx);
					octagons[j]->vy = -abs(octagons[j]->vy);
				}
			}
		}
	}

	// cek tumbukan antara circle dengan circle
	for (int i = 0; i < numCircle; i++) {
		for (int j = 0; j < numCircle; j++) {
			if (j != i) {
				if (sqrt(pow(circles[i]->x - circles[j]->x, 2) + pow(circles[i]->y - circles[j]->y, 2)) <= circleRadius * 2) {

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

// move each object by one time step dt
void step() {
	// circle
	if (numCircle > 0) {
		for (int i = 0; i < numCircle; i++) {
			circles[i]->step(dt);
		}
	}
	// square
	if (numSquare > 0) {
		for (int i = 0; i < numSquare; i++) {
			squares[i]->step(dt);
		}
	}
	// octagon
	if (numOctagon > 0) {
		for (int i = 0; i < numOctagon; i++) {
			octagons[i]->step(dt);
		}
	}
	t += dt;
	++step_number;
}

/*
	Prosedur menggerakkan 2 buah garis di tengah window
*/
void stepSplitLine() {
	if (stateGate == 'L') {
		if (sqGatePosXM >= splitterMinPosX + 0.325f) {
			sqGatePosXM -= 0.01f;
			sqGatePosX0 -= 0.01f;
			sqGatePosX1 -= 0.01f;
		}
		else {
			stateGate = 'R';
		}
	}
	else {
		if (sqGatePosXM <= splitterMaxPosX - 0.325f) {
			sqGatePosXM += 0.01f;
			sqGatePosX0 += 0.01f;
			sqGatePosX1 += 0.01f;
		}
		else {
			stateGate = 'L';
		}
	}
}

// prosedur menjalankan semua animasi
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

		// perubahan posisi garis penjaga kotak abu-abu tengah
		stepSplitLine();

		// melakukan pengurangan waktu permainan
		if (deltaTime > 0.0f) {
			deltaTime = deltaTime - 0.02f;
		}
		else {
			deltaTime = -0.02f;
			displayFinalState = 1;
		}

	while ((double(clock()) - start_time) / CLOCKS_PER_SEC < one_per_fsec);
	glutPostRedisplay();
}
