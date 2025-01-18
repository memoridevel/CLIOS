#include "Header.h"

void crypt() {
	printTitle("Crypt", "0.962");

	string choice, input;

	while (true) {
		cout << "\nEncrypt/Decrypt (0/1): ";
		cin >> choice;

		if (choice == "0") {
			cout << "Enter string to encrypt: ";
			cin >> input;
			cout << "Encrypted: " << encrypt(input) << "\n";
		}
		else if (choice == "1") {
			cout << "Enter string to decrypt: ";
			cin >> input;
			cout << "Decrypted: " << decrypt(input) << "\n";
		}
		else if (choice == "quit" || choice == "exit") {
			break;
		}
		else {
			cout << "Incorrect input\n";
		}
	};
}
