#include "Header.h"

int main() {
	setlocale(LC_ALL, "");
	printTitle("CLIOS", "0.87");

	bool continued = true;
	string input;
	
	while (true) {
		cout << "\n>> ";
		cin >> input;
		if (input != "quit" && input != "exit") {
			cout << "<< ";
			if (find(begin(commands), end(commands), input) != end(commands)) {
				cout << "starting " << input << "...";
				system("cls");
				if (input == commands[0]) {
					crypt();
				}
				else if (input == commands[1]) {
					paint();
				}
				else if (input == commands[2]) {
					sample();
				}
				else if (input == commands[3]) {
					field();
				}
				else {
					cout << "command not found";
				}
				system("cls");
			}
			else if (input == "help") {
				cout << "Список всех команд:\n";
				for (int i = 0; i < size(commands); i++) {
					cout << commands[i] << "\n";
				}
			}
			else {
				cout << "\"" + input + "\" не является внутренней или внешней командой, исполняемой программой или пакетным файлом.\n";
			}
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
