#include "Header.h"

void field(string login) {
	vector<string> words = {
		"программа",
		"система",
		"компьютер",
		"вода",
		"мечта",
		"поле",
		"цветок",
		"время",
		"магия",
		"ааааавтомобиль",
		"кресло",
		"котёнок",
		"калькулятор",
		"луна",
		"школа",
		"цыплёнок",
		"телефон",
		"логика",
		"земля",
		"мир",
		"звезда"
	};
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0];
	const int MAX_WRONG = (int)THE_WORD.length();
	int wrong = 0;
	string soFar(THE_WORD.size(), '-'), used = "";

	printTitle(rus("Поле чудес"), "0.9");
	cout << rus("Добро пожаловать в Поле чудес, ") << login;
	cout << rus(". Удачи!\n\n");

	while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
		cout << rus("\nУ вас есть ") << (MAX_WRONG - wrong);
		cout << rus(" попыток.\n\n");
		cout << rus("Вы использовали эти буквы: ") << used;
		cout << rus("\n\nТекущее слово: ") << soFar;
		char guess;
		cout << rus("\n\nВведите букву: ");
		putchar(guess = _getch());
		guess = tolower(guess);

		while (used.find(guess) != string::npos) {
			cout << rus("\nВы уже угадывали эту букву ") << guess;
			cout << rus("\n\nВведите букву: ");
			putchar(guess = _getch());
			guess = tolower(guess);
		}
		used += guess;

		if (THE_WORD.find(guess) != string::npos) {
			cout << rus("\nВерно! ") << guess;
			cout << rus(" есть в этом слове.\n\n");
			for (unsigned int i = 0; i < THE_WORD.length(); ++i) {
				if (THE_WORD[i] == guess) {
					soFar[i] = guess;
				}
			}
		}
		else {
			cout << rus("\nК сожалению, ") << guess;
			cout << rus(" нет в этом слове.\n\n");
			++wrong;
		}
	}

	if (wrong == MAX_WRONG) {
		cout << rus("\nВы не угадали слово.");
	}
	else {
		cout << rus("\nВы угадали слово!");
	}
	cout << rus("\nИскомое слово: ");
	cout << rus(THE_WORD.c_str());
}
	