#include "Header.h"

void sample() {
	int n = 100, tmp = 115;

	printTitle("temp", VERSION);
	system("pause>nul");

	for (int i = 0; i <= n; i++) {
		system("cls");
		printLine(X_END, "+", "-", "+\n");
		if (i < 10) {
			tmp = 9;
		}
		else if (i < 100) {
			tmp = 8;
		}
		else {
			tmp = 7;
		}
		tmp += n - i;
		printLine(X_END, "|", " ", "|\n");
		printSymbol("|");
		printSymbolN(i, "#");
		printSymbolN(tmp, " ");
		cout << i << "%";
		printSymbolN(7, " ");
		printSymbol("|\n");
		printLine(X_END, "|", " ", "|\n");
		printLine(X_END, "+", "-", "+\n");
		printBattery(i / 10);
	}
}
