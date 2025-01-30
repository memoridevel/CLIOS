#include "Header.h"

void crypt() {
	printTitle("Crypt", "0.98");

	string input;
	char c;
	int y = 1;

	cout << "> Encrypt\n  Decrypt";
	gotoxy(0, y);
	do {
		c = _getch();
		if (c == 80 || c == 72) {
			cout << ' ';
			if (y == 1) {
				gotoxy(0, ++y);
			}
			else if (y == 2) {
				gotoxy(0, --y);
			}
			cout << '>';
			gotoxy(0, y);
		}
	} while (c != 13 && c != 113 && c != 81);
	if (c == 13) {
		gotoxy(0, 1);
		cout << "         \n         ";
		gotoxy(0, 1);
		cout << "Enter string to ";
		if (y == 1) {
			cout << "encrypt: ";
			cin >> input;
			cout << "Encrypted: " << encrypt(input);
		}
		else {
			cout << "decrypt: ";
			cin >> input;
			cout << "Decrypted: " << decrypt(input);
		}
	}
	system("pause>nul");
}
