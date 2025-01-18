#include "Header.h"

void sample() {
	printTitle("Анимация зарядки", "0.unknown");

	const int n = 100;
	int m[n + 1], tmp = 115;

	system("pause>nul");
	for (int i = 0; i <= n; i++) {
		m[i] = i;
	}
	for (int i = 0; i <= n; i++) {
		system("cls");
		printLine(X_END, "+", "-");
		if (m[i] < 10) {
			tmp = 9;
		}
		else if (m[i] < 100) {
			tmp = 8;
		}
		else {
			tmp = 7;
		}
		tmp += n - i;
		printLine(X_END, "|", " ");
		printSymbol("|");
		printSymbolN(m[i], "#");
		printSymbolN(tmp, " ");
		cout << m[i] << "%";
		printSymbolN(7, " ");
		printSymbol("|\n");
		printLine(X_END, "|", " ");
		printLine(X_END, "+", "-");
		printBattery(m[i] / 10);
		this_thread::sleep_for(chrono::milliseconds(50));
	}
}
