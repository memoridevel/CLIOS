#include "Header.h"

void crypt() {
	string choice, input;

	cout << "crypt v0.96\n";
	do {
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
		else if (choice != "quit" && choice != "exit") {
			cout << "Incorrect input\n";
		}
	} while (choice != "quit" && choice != "exit");
}

void encrypt(string& input) {
	reverse(input.begin(), input.end());
	for (unsigned int i = 0; i < input.size(); i += 2) {		// symbol + i + 1
		input[i] += (i + 1);
	}
	reverse(input.begin(), input.end());
	for (unsigned int i = 0; i < input.size(); i++) {			// xor
		input[i] ^= input.size() * 2;
	}
	reverse(input.begin(), input.end());
	for (unsigned int i = 0; i < input.size(); i++) {			// symbol - 1
		if (i % 2 == 0) {
			input[i] -= 1;
		}
	}
	reverse(input.begin(), input.end());
	cout << "Encrypted: " << input << endl;
}

void decrypt(string& input) {
	reverse(input.begin(), input.end());
	for (unsigned int i = 0; i < input.size(); i++) {			// symbol + 1
		if (i % 2 == 0) {
			input[i] += 1;
		}
	}
	reverse(input.begin(), input.end());
	for (unsigned int i = 0; i < input.size(); i++) {			// xor
		input[i] ^= input.size() * 2;
	}
	reverse(input.begin(), input.end());
	for (unsigned int i = 0; i < input.size(); i += 2) {		// symbol - i - 1
		input[i] -= (i + 1);
	}
	reverse(input.begin(), input.end());
	cout << "Decrypted: " << input << endl;
}
