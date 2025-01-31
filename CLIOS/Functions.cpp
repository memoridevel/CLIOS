#include "Header.h"

void printTitle(string name, string version) {
	string title = name + " v" + version;
	for (int i = 0; i < X_END + 2; i++) {
		cout << '=';
	}
	gotoxy(short(X_END - title.length()) / 2, 0);
	cout << " " << title << " \n";
}
void logo() {
	gotoxy(short(X_END - 45) / 2, short(Y_END - 3) / 2 - 2);
	cout << "============   CCCC  L      III  OOOO   SSSSS";
	gotoxy(short(X_END - 45) / 2, short(Y_END - 3) / 2 - 1);
	cout << "|          |  C    C L       I  O    O S";
	gotoxy(short(X_END - 45) / 2, short(Y_END - 3) / 2);
	cout << "| >>       |  C      L       I  O    O  SSSS";
	gotoxy(short(X_END - 45) / 2, short(Y_END - 3) / 2 + 1);
	cout << "|          |  C    C L       I  O    O      S";
	gotoxy(short(X_END - 45) / 2, short(Y_END - 3) / 2 + 2);
	cout << "+----------+   CCCC  LLLLLL III  OOOO  SSSSS";
	gotoxy(X_END - 13, 0);
	cout << "(c) memoridevel";
	gotoxy(0, 0);
}

string encrypt(string input) {
	reverse(input.begin(), input.end());
	for (unsigned int i = 0; i < input.size(); i += 2) {		// symbol + i + 1
		input[i] += (i + 1);
	}
	reverse(input.begin(), input.end());
	for (unsigned int i = 0; i < input.size(); i++) {			// xor
		input[i] ^= input.size() * 2;
	}
	reverse(input.begin(), input.end());
	for (unsigned int i = 0; i < input.size(); i++) {			// symbol - 1
		if (i % 2 == 0) {
			input[i] -= 1;
		}
	}
	reverse(input.begin(), input.end());
	return input;
}
string decrypt(string input) {
	reverse(input.begin(), input.end());
	for (unsigned int i = 0; i < input.size(); i++) {			// symbol + 1
		if (i % 2 == 0) {
			input[i] += 1;
		}
	}
	reverse(input.begin(), input.end());
	for (unsigned int i = 0; i < input.size(); i++) {			// xor
		input[i] ^= input.size() * 2;
	}
	reverse(input.begin(), input.end());
	for (unsigned int i = 0; i < input.size(); i += 2) {		// symbol - i - 1
		input[i] -= (i + 1);
	}
	reverse(input.begin(), input.end());
	return input;
}

void border() {
	const string SPACE = "       ";
	cout << " Пробел - Ручка";
	cout << SPACE;
	cout << "Delete - Ластик";
	cout << SPACE;
	cout << "Escape - Свободное перемещение";
	cout << SPACE;
	cout << "Enter - Очистить экран";
	cout << SPACE;
	cout << "q - Выход\n";

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
void gotoxy(short x, short y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x, y });
}

void printLine(int n, string c1, string c2) {
	printSymbol(c1);
	printSymbolN(n, c2);
	printSymbol(c1);
	cout << "\n";
}
void printSymbol(string c) {
	cout << c;
}
void printSymbolN(int n, string c) {
	for (int i = 0; i < n; i++) {
		cout << c;
	}
}
void printBattery(int z) {
	cout << "\n";
	printSymbolN(55, " ");
	printLine(6, "+", "-");
	printSymbolN(55, " ");
	switch (z) {
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		printLine(6, "|", " ");
		break;
	case 10:
		printLine(6, "|", "#");
		break;
	}
	printSymbolN(53, " ");
	switch (z) {
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
		printLine(6, "+-+", " ");
		break;
	case 9:
	case 10:
		printLine(6, "+-+", "#");
		break;
	}
	printSymbolN(53, " ");
	int tmp = z;
	if (z > 8) {
		z = 8;
	}
	for (int i = 0; i < 8 - z; i++) {
		printLine(10, "|", " ");
		printSymbolN(53, " ");
	}
	for (int i = 0; i < z; i++) {
		printLine(10, "|", "#");
		printSymbolN(53, " ");
	}
	printLine(10, "+", "-");
}

//void ban() {
//	system("cls");
//	gotoxy(short(X_END - 28) / 2, short(Y_END - 3) / 2 - 2);
//	cout << "BBBBBBB       A      NN    N\n";
//	gotoxy(short(X_END - 28) / 2, short(Y_END - 3) / 2 - 1);
//	cout << "B     B      A A     N N   N\n";
//	gotoxy(short(X_END - 28) / 2, short(Y_END - 3) / 2);
//	cout << "BBBBBBBB    A   A    N  N  N\n";
//	gotoxy(short(X_END - 28) / 2, short(Y_END - 3) / 2 + 1);
//	cout << "B      B   AAAAAAA   N   N N\n";
//	gotoxy(short(X_END - 28) / 2, short(Y_END - 3) / 2 + 2);
//	cout << "BBBBBBBB  A       A  N    NN\n";
//	gotoxy(0, 0);
//	char c;
//	do {
//		c = _getch();
//	} while (c != 74);
//	cout << "ok, i don't know how you escape from this (i know it, i just rofl)\n";
//	cout << "you crashed my code (no, yo just have broken login)\n";
//	cout << "now you can get admin rights (just go fly a kite)\n";
//	system("pause>nul");
//}
