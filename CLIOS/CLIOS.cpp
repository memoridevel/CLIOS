#include "Header.h"

int main() {
	/*setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);*/

	string login, password, input;
	const string cliosLogo[] {
		"============   CCCC  L      III  OOOO   SSSSS",
		"|          |  C    C L       I  O    O S",
		"| >>       |  C      L       I  O    O  SSSS",
		"|          |  C    C L       I  O    O      S",
		"+----------+   CCCC  LLLLLL III  OOOO  SSSSS"
	},
		commands[] { "crypt", "paint", "sample", "field", "ttt", "meow" },
		logins[]{ "c{_'-!&$'", "!'\\uts!'" };
	byte userRule;
	hash<string> hasher;
	unordered_map<string, long long> passwords;
	passwords.insert({ logins[0], hasher("lwiegy`r!$!") });
	passwords.insert({ logins[1], hasher("=/>>=3") });

	printLogo(cliosLogo, size(cliosLogo));
	userRule = logon(login, password, logins, passwords, hasher);
	system("cls");
	printTitle("CLIOS", "0.99999");

	while (true) {
		cout << "\n" + login + " >> ";
		cin >> input;
		for (int i = 0; i < input.length(); i++) {
			input[i] = tolower(input[i]);
		}
		if (input != "quit" && input != "exit") {
			cout << "<< ";
			run(input, commands, size(commands), login, userRule);
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
