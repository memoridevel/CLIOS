#include <iostream>
#include <conio.h>

using namespace std;

const int X_BEGIN = 1, X_END = 118, Y_BEGIN = 3, Y_END = 28;

void gotoxy(short x, short y);
void border();

void paint() {
	int c, x = X_END / 2, y = Y_END / 2 + 2, f = 0;

	system("cls");
	cout << "Console Paint v1.15\n";
	cout << " Пробел - Ручка       Delete - Ластик       Escape - Свободное перемещение       Enter - Очистить экран       q - Выход\n";
	border();
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
		else if (c == 13) {
			f = 0;
			gotoxy(X_BEGIN, Y_BEGIN);
			for (int i = Y_BEGIN; i <= Y_END; i++) {
				for (int j = X_BEGIN; j <= X_END; j++) {
					cout << " ";
				}
				gotoxy(X_BEGIN, i);
			}
			x = X_END / 2;
			y = Y_END / 2 + 2;
			gotoxy(x, y);
		}
		else if (c == 27) {
			f = 0;
		}
		else if (c == 32) {
			f = 1;
		}
		else if (c == 83) {
			f = 2;
		}

		if (f == 1) {
			cout << "#";
			x++;
			gotoxy(--x, y);
		}
		else if (f == 2) {
			cout << " ";
			x++;
			gotoxy(--x, y);
		}
	} while (c != 113 && c != 81);
	system("cls");
}

void border() {
	cout << "+";
	for (int i = X_BEGIN; i <= X_END; i++) {
		cout << "-";
	}
	cout << "+\n";
	for (int i = Y_BEGIN; i <= Y_END; i++) {
		cout << "|";
		gotoxy(X_END + 1, i);
		cout << "|\n";
	}
	cout << "+";
	for (int i = X_BEGIN; i <= X_END; i++) {
		cout << "-";
	}
	cout << "+";
}
