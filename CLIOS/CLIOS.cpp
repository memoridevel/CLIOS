#include "Header.h"

int main() {
	setlocale(LC_ALL, "");

	bool continued = true;
	string input;
	const string title = " CLIOS v0.77 ";

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

void runCommand(string input) {
	if (input == "crypt") {
		crypt();
	}
	else if (input == "paint") {
		paint();
	}
	else if (input == "sample") {
		sample();
	}
	else if (input != "quit" && input != "exit") {
		cout << "unknown command\n";
	}
}
