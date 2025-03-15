#include "Header.h"

int main() {
	/*setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);*/
	string login, password, input;
	byte rule;
	const string cliosLogo[]{
		"\325\315\315\315\315\315\315\315\315\315\315\270   CCCC  L      III  OOOO   SSSSS",
		"\263          \263  C    C L       I  O    O S",
		"\263 >>       \263  C      L       I  O    O  SSSS",
		"\263          \263  C    C L       I  O    O      S",
		"\300\304\304\304\304\304\304\304\304\304\304\331   CCCC  LLLLLL III  OOOO  SSSSS"
	},
		morda[]{
		"      #             #",
		"     # #           # #",
		"    #   #         #   #",
		"   #     #########     #",
		"  #                     #",
		" #                       #",
		"#                         #",
		"#      ###       ###      #",
		"#       #         #       #",
		"#           ###           #",
		"#            #            #",
		" #        #  #  #        #",
		"  #        #####        #",
		"    #                 #",
		"      ###############"
	},
		/*hack[]{
		"Y   Y  OOO  U   U   H   H  AAA  V   V EEEEE   BBBB  EEEEE EEEEE N   N   H   H  AAA   CCCC K   K EEEEE DDDD",
		" Y Y  O   O U   U   H   H A   A V   V E       B  B  E     E     NN  N   H   H A   A C     K  K  E     D   D",
		"  Y   O   O U   U   HHHHH AAAAA V   V EEEEE   BBBBB EEEEE EEEEE N N N   HHHHH AAAAA C     KKK   EEEEE D   D",
		"  Y   O   O U   U   H   H A   A  V V  E       B   B E     E     N  NN   H   H A   A C     K  K  E     D   D",
		"  Y    OOO   UUU    H   H A   A   V   EEEEE   BBBBB EEEEE EEEEE N   N   H   H A   A  CCCC K   K EEEEE DDDD"
	},*/
		help[]{
		"\311\315\315\315\315\315\315\315 Справка \315\315\315\315\315\315\315\273",
		"\272                       \272",
		rus("\272  Клавиша h - справка  \272"),
		rus("\272  Клавиша q - выход    \272"),
		rus("\272  Клавиша z - \260        \272"),
		rus("\272  Клавиша x - \261        \272"),
		rus("\272  Клавиша c - \262        \272"),
		rus("\272  Клавиша v - \333        \272"),
		rus("\272  Пробел - очистить    \272"),
		rus("\272  Delete - ластик      \272"),
		rus("\272  Escape - курсор      \272"),
		"\272                       \272",
		"\310\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\274"
	},
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
	printTitle("CLIOS", "0.9999999");

	while (true) {
		cout << "\n" + login + " >> ";
		cin >> input;
		for (int i = 0; i < input.length(); i++) {
			input[i] = tolower(input[i]);
		}
		if (input != "quit" && input != "exit") {
			cout << "<< ";
			run(input, commands, size(commands), login, rule, morda, size(morda), help, size(help)/*, hack, size(hack)*/);
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
