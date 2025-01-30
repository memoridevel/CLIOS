#include "Header.h"

int main() {
	//setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string login, password, input;
	bool debug = 0;

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
	gotoxy(0, 0);
	cout << "Welcome to CLIOS";
	gotoxy(X_END - 13, 0);
	cout << "(c) memoridevel\n";

	cout << "Введите логин: ";
	cin >> login;
	if (login == decrypt("c{_'-!&$'")) {
		cout << "Введите пароль: ";
		cin >> password;
		if (password == decrypt("lwiegy`r!$!")) {
			debug = 1;
		}
		else {
			ban();
			login = "vbr%&#@^(";
		}
	}

	system("cls");
	printTitle("CLIOS", "0.95");

	while (true) {
		cout << "\n" + login + " >> ";
		cin >> input;
		for (int i = 0; i < input.length(); i++) {
			input[i] = tolower(input[i]);
		}
		if (input != "quit" && input != "exit") {
			cout << "<< ";
			if (find(begin(commands), end(commands), input) != end(commands)) {
				cout << "запуск " << input << "...";
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
					field(login, debug);
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
