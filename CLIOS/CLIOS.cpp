#include <iostream>
#include <Windows.h>
#include "Header.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "");

	bool continued = true;
	string input;
	const string title = " CLIOS v0.7 ";

	cout << "\n ";
	for (int i = 0; i < 118; i++) {
		cout << '=';
	}
	gotoxy((120 - title.length()) / 2, 1);
	cout << title << endl;

	do {
		cout << "\n >> ";
		cin >> input;
		cout << "\n << ";
		start(input);
	} while (input != "quit" && input != "exit");

	cout << "goodbye";
	for (int i = 0; i < 3709; i++) {
		cout << '.';
	}
}

void start(string input) {
	if (input == "crypt") {
		crypt();
	}
	else if (input == "paint") {
		paint();
	}
	else if (input != "quit" && input != "exit") {
		cout << "unknown command\n";
	}
}