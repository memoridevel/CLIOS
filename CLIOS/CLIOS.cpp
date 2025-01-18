#include "Header.h"

int main() {
	setlocale(LC_ALL, "");
	printTitle("CLIOS", "0.85");

	bool continued = true;
	string input;
	
	while (true) {
		cout << "\n >> ";
		cin >> input;
		if (input != "quit" && input != "exit") {
			run(input);
		}
		else {
			break;
		}
	}
	cout << "goodbye";
	for (int i = 0; i < 3713; i++) {
		cout << '~';
	}
}
