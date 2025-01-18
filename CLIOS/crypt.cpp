#include "Header.h"

void crypt() {
	printTitle("Crypt", "0.9612");

	string choice, input;

	while (true) {
		cout << "\nEncrypt/Decrypt (0/1): ";
		cin >> choice;

		if (choice == "0") {
			cout << "Enter string to encrypt: ";
			cin >> input;
			encrypt(input);
		}
		else if (choice == "1") {
			cout << "Enter string to decrypt: ";
			cin >> input;
			decrypt(input);
		}
		else if (choice == "quit" || choice == "exit") {
			break;
		}
		else {
			cout << "Incorrect input\n";
		}
	};
}
