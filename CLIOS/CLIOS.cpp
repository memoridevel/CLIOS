#include "Header.h"

int main() {
	//setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string login, password, input;
	bool admin;
	hash<string> hasher;
	unordered_map<string, long long> logpass;

	logpass.insert({ "c{_'-!&$'", hasher("lwiegy`r!$!") });
	logpass.insert({ "!'\\uts!'", hasher("=/>>=3") });

	logo();
	cout << "Welcome to CLIOS";
	enter:
	cout << "\nЛогин: ";
	cin >> login;
	cout << "Пароль: ";
	cin >> password;
	if (login == decrypt("c{_'-!&$'") && hasher(encrypt(password)) == logpass.at("c{_'-!&$'")) {
		admin = true;
	}
	else if (login == decrypt("!'\\uts!'") && hasher(encrypt(password)) == logpass.at("!'\\uts!'")) {
		admin = false;
	}
	else {
		cout << "Неверный логин или пароль";
		this_thread::sleep_for(chrono::milliseconds(1500));
		goto enter;
	}

	system("cls");
	printTitle("CLIOS", "0.999");

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
					field(login, admin);
				}
				else if (input == commands[4]) {
					ttt();
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
