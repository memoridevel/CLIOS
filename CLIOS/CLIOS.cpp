#include "Header.h"

int main() {	// TODO выход из учётки
	/*setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);*/
	string input, login, password = "";
	byte rule;
	const string cliosLogo[]{
		"\325\315\315\315\315\315\315\315\315\315\315\270   CCCC  L      III  OOOO   SSSSS",
		"\263          \263  C    C L       I  O    O S",
		"\263 >>       \263  C      L       I  O    O  SSSS",
		"\263          \263  C    C L       I  O    O      S",
		"\300\304\304\304\304\304\304\304\304\304\304\331   CCCC  LLLLLL III  OOOO  SSSSS"
	},
		/*hack[]{
		"Y   Y  OOO  U   U   H   H  AAA  V   V EEEEE   BBBB  EEEEE EEEEE N   N   H   H  AAA   CCCC K   K EEEEE DDDD",
		" Y Y  O   O U   U   H   H A   A V   V E       B  B  E     E     NN  N   H   H A   A C     K  K  E     D   D",
		"  Y   O   O U   U   HHHHH AAAAA V   V EEEEE   BBBBB EEEEE EEEEE N N N   HHHHH AAAAA C     KKK   EEEEE D   D",
		"  Y   O   O U   U   H   H A   A  V V  E       B   B E     E     N  NN   H   H A   A C     K  K  E     D   D",
		"  Y    OOO   UUU    H   H A   A   V   EEEEE   BBBBB EEEEE EEEEE N   N   H   H A   A  CCCC K   K EEEEE DDDD"
	},*/
		commands[]{ "help", "crypt", "paint", "sample", "field", "ttt", "cat", "baraban" },
		logins[]{ "uoi", "!'\\uts!'", "}}mz" };
	hash<string> hasher;
	unordered_map<string, long long> passwords{
		{ logins[0], hasher("@V48%)#)") },
		{ logins[1], hasher("=/>>=3") },
		{ logins[2], hasher("141") }
	};

	printLogo(cliosLogo, size(cliosLogo), 45);
	rule = logon(login, password, logins, passwords, hasher);
	system("cls");
	printTitle("CLIOS", VERSION);

	do {
		cout << "\n" + login + " >> ";
		getline(cin, input);
		for (int i = 0; i < input.length(); i++) {
			input[i] = tolower(input[i]);
		}

		if (input != "\0" && input != "exit") {
			cout << "<< ";
			run(input, commands, size(commands), login, rule/*, hack, size(hack)*/);
		}
	} while (input != "exit");

	cout << "goodbye";
	for (int i = 0; i < 3713; i++) {
		cout << '~';
	}
}
