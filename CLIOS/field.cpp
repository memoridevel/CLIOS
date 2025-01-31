#include "Header.h"

void field(string name, bool admin) {
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

    printTitle("Поле чудес", "0.718");

    cout << "Добро пожаловать в Поле чудес, " << name << ". Удачи!\n\n";

    if (admin) {
        cout << "MAX_WRONG = " << MAX_WRONG << "\n";
        cout << "THE_WORD = " << THE_WORD << "\n";
        cout << "wrong = " << wrong << "\n";
        cout << "soFar = " << soFar << "\n";
        cout << "used = " << used << "\n";
        cout << "((wrong < MAX_WRONG) && (soFar != THE_WORD)) = " << ((wrong < MAX_WRONG) && (soFar != THE_WORD)) << "\n" << "\n";
    }

    while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
        cout << "\nУ вас есть " << (MAX_WRONG - wrong) << " попыток.\n";
        cout << "\nВы использовали эти буквы: " << used << "\n";
        cout << "\nТекущее слово: " << soFar << "\n";
        char guess;
        cout << "\nВведите букву: ";
        cin >> guess;
        guess = tolower(guess);

        if (admin) {
            cout << "\nguess = " << guess << "\n";
            cout << "(used.find(guess) != string::npos) = " << (used.find(guess) != string::npos) << "\n";
        }

        while (used.find(guess) != string::npos) {
            cout << "\nВы уже угадывали эту букву " << guess << "\n";
            cout << "\nВведите букву: ";
            cin >> guess;
            guess = toupper(guess);

            if (admin) {
                cout << "\nguess = " << guess << "\n";
                cout << "(used.find(guess) != string::npos) = " << (used.find(guess) != string::npos) << "\n";
            }
        }
        used += guess;

        if (admin) {
            cout << "(THE_WORD.find(guess) != string::npos) = " << (THE_WORD.find(guess) != string::npos) << "\n";
        }

        if (THE_WORD.find(guess) != string::npos) {
            cout << "Верно! " << guess << " есть в этом слове.\n\n";
            for (unsigned int i = 0; i < THE_WORD.length(); ++i) {
                if (admin) {
                    cout << "(THE_WORD[i] == guess) = " << (THE_WORD[i] == guess) << "\n";
                }
                if (THE_WORD[i] == guess) {
                    soFar[i] = guess;
                }
            }
        }
        else {
            cout << "К сожалению, " << guess << " нет в этом слове.\n\n";
            ++wrong;
        }

        if (admin) {
            cout << "wrong = " << wrong << "\n";
            cout << "soFar = " << soFar << "\n";
            cout << "used = " << used << "\n";
            cout << "((wrong < MAX_WRONG) && (soFar != THE_WORD)) = " << ((wrong < MAX_WRONG) && (soFar != THE_WORD)) << "\n";
        }
    }

    if (admin) {
        cout << "(wrong == MAX_WRONG) = " << (wrong == MAX_WRONG) << "\n";
    }

    if (wrong == MAX_WRONG) {
        cout << "\nВы не угадали слово.";
    }
    else {
        cout << "\nВы угадали слово!";
    }
    cout << "\nИскомое слово: " << THE_WORD;
    system("pause>nul");
}
