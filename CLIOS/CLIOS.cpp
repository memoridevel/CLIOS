#include <iostream>
#include <Windows.h>
#include "Header.h"

int main() {
	setlocale(LC_ALL, "");

	bool continued = true;
	string input;
	const string title = " CLIOS v0.75 ";

	cout << "\n ";
	for (int i = 0; i < 118; i++) {
		cout << '=';
	}
	gotoxy(short(120 - title.length()) / 2, 1);
	cout << title << endl;

	do {
		cout << "\n >> ";
		cin >> input;
		cout << "\n << ";
		runCommand(input);
	} while (input != "quit" && input != "exit");

	cout << "goodbye";
	for (int i = 0; i < 3709; i++) {
		cout << '.';
	}
}
