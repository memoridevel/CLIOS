#include "Header.h"

void sample() {
	const int n = 100;
	int m[n + 1]{}, tmp = 115;

	printTitle("temp", "0.unknown");
	system("pause>nul");
	for (int i = 0; i <= n; i++) {
		m[i] = i;
	}
	for (int i = 0; i <= n; i++) {
		system("cls");
		printLine(X_END, "+", "-", "+\n");
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
		printLine(X_END, "|", " ", "|\n");
		printSymbol("|");
		printSymbolN(m[i], "#");
		printSymbolN(tmp, " ");
		cout << m[i] << "%";
		printSymbolN(7, " ");
		printSymbol("|\n");
		printLine(X_END, "|", " ", "|\n");
		printLine(X_END, "+", "-", "+\n");
		printBattery(m[i] / 10);
	}
}
