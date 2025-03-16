#include "Header.h"

void field(string login) {
	vector<string> words = {
		"���������",
		"�������",
		"���������",
		"����",
		"�����",
		"����",
		"������",
		"�����",
		"�����",
		"��������������",
		"������",
		"������",
		"�����������",
		"����",
		"�����",
		"�������",
		"�������",
		"������",
		"�����",
		"���",
		"������"
	};
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0];
	const int MAX_WRONG = (int)THE_WORD.length();
	int wrong = 0;
	string soFar(THE_WORD.size(), '-'), used = "";

	printTitle(rus("���� �����"), "0.9");
	cout << rus("����� ���������� � ���� �����, ") << login;
	cout << rus(". �����!\n\n");

	while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
		cout << rus("\n� ��� ���� ") << (MAX_WRONG - wrong);
		cout << rus(" �������.\n\n");
		cout << rus("�� ������������ ��� �����: ") << used;
		cout << rus("\n\n������� �����: ") << soFar;
		char guess;
		cout << rus("\n\n������� �����: ");
		putchar(guess = _getch());
		guess = tolower(guess);

		while (used.find(guess) != string::npos) {
			cout << rus("\n�� ��� ��������� ��� ����� ") << guess;
			cout << rus("\n\n������� �����: ");
			putchar(guess = _getch());
			guess = tolower(guess);
		}
		used += guess;

		if (THE_WORD.find(guess) != string::npos) {
			cout << rus("\n�����! ") << guess;
			cout << rus(" ���� � ���� �����.\n\n");
			for (unsigned int i = 0; i < THE_WORD.length(); ++i) {
				if (THE_WORD[i] == guess) {
					soFar[i] = guess;
				}
			}
		}
		else {
			cout << rus("\n� ���������, ") << guess;
			cout << rus(" ��� � ���� �����.\n\n");
			++wrong;
		}
	}

	if (wrong == MAX_WRONG) {
		cout << rus("\n�� �� ������� �����.");
	}
	else {
		cout << rus("\n�� ������� �����!");
	}
	cout << rus("\n������� �����: ");
	cout << rus(THE_WORD.c_str());
}
	