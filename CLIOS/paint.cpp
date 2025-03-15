#include "Header.h"

void paint(const string* help, const size_t& nH) {
	int c, x = X_END / 2, y = Y_END / 2 + 2, f = 0;
	char paper[Y_END - 1][X_END]{};
	for (int i = 0; i < Y_END - 1; i++) {
		for (int j = 0; j < X_END; j++) {
			paper[i][j] = ' ';
		}
	}
	/*
	260 261 262 263 264 265 266 267
	270 271 272 273 274 275 276 277
	300 301 302 303 304 305 306 307
	310 311 312 313 314 315 316 317
	320 321 322 323 324 325 326 327
	330 331 332 333 334 335 336 337
	*/

	printTitle("Console Paint", "0.9");
	border(X_END, Y_END, "\332", "\304", "\277", "\263", "\300", "\331");
	gotoxy(x, y);
	do {
		c = _getch();
		//printf("%d", c);
		if (c == 77 && x < X_END) {
			gotoxy(++x, y);
		}
		else if (c == 80 && y < Y_END) {
			gotoxy(x, ++y);
		}
		else if (c == 75 && x > X_BEGIN) {
			gotoxy(--x, y);
		}
		else if (c == 72 && y > Y_BEGIN) {
			gotoxy(x, --y);
		}
		else if (c == 32) {
			f = 0;
			for (int i = 0; i < Y_END - 1; i++) {
				for (int j = 0; j < X_END; j++) {
					paper[i][j] = ' ';
				}
			}
			gotoxy(X_BEGIN, Y_BEGIN);
			for (int i = Y_BEGIN; i <= Y_END + 1; i++) {
				for (int j = X_BEGIN; j <= X_END; j++) {
					cout << ' ';
				}
				gotoxy(X_BEGIN, i);
			}
			x = X_END / 2;
			y = Y_END / 2 + 2;
			gotoxy(x, y);
		}
		else if (c == 104) {
			f = 0;
			printLogo(help, nH, 25);
			system("pause>nul");
			for (int i = 0; i < Y_END - 1; i++) {
				gotoxy(1, i + 2);
				for (int j = 0; j < X_END; j++) {
					cout << paper[i][j];
				}
			}
			gotoxy(x, y);
		}
		else if (c == 27) {
			f = 0;
		}
		else if (c == 83) {
			f = 1;
		}
		else if (c == 122) {
			f = 2;
		}
		else if (c == 120) {
			f = 3;
		}
		else if (c == 99) {
			f = 4;
		}
		else if (c == 118) {
			f = 5;
		}

		if (f != 0) {
			if (f == 1) {
				paper[y - 2][x - 1] = ' ';
				cout << " ";
			}
			else if (f == 2) {
				paper[y - 2][x - 1] = '\260';
				cout << "\260";
			}
			else if (f == 3) {
				paper[y - 2][x - 1] = '\261';
				cout << "\261";
			}
			else if (f == 4) {
				paper[y - 2][x - 1] = '\262';
				cout << "\262";
			}
			else if (f == 5) {
				paper[y - 2][x - 1] = '\333';
				cout << "\333";
			}
			x++;
			gotoxy(--x, y);
		}
	} while (c != 113 && c != 81);
}
