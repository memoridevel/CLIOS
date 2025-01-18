#include "Header.h"

void field() {
    printTitle("Field of dreams", "1.43");

    string name, pw;
    bool debug = 0;

    cout << "\nEnter your name: ";
    cin >> name;
    if (name == "mik573269") {
        cout << "Enter password: ";
        cin >> pw;
        if (pw == decrypt("lwiegy`r!$!")) {
            debug = 1;
            cout << "Debug mode is ON.\n";
        }
        else {
            ban();
        }
    }

    cout << "\nWelcome to Field of Dreams, " << name << ". Good luck!\n\n";

    const int MAX_WRONG = 8;
    vector<string> words;
    words.push_back(name);
    words.push_back("PROGRAM");
    words.push_back("SYSTEM");
    words.push_back("COMPUTER");
    words.push_back("WATER");
    words.push_back("DREAM");
    words.push_back("FIELD");
    words.push_back("FLOWER");
    words.push_back("TIME");
    words.push_back("MAGIC");
    words.push_back("CAR");
    words.push_back("CHAIR");
    words.push_back("KITTEN");
    words.push_back("CALCULATOR");
    words.push_back("GUESS");
    words.push_back("MOON");
    words.push_back("SCHOOL");
    words.push_back("CHICKEN");
    words.push_back("PHONE");
    words.push_back("LOGIC");
    words.push_back("EARTH");
    words.push_back("WORLD");
    words.push_back("STAR");
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    const string THE_WORD = words[0];
    int wrong = 0;
    string soFar(THE_WORD.size(), '-');
    string used = "";

    if (debug) {
        cout << "MAX_WRONG = " << MAX_WRONG << "\n";
        cout << "THE_WORD = " << THE_WORD << "\n";
        cout << "wrong = " << wrong << "\n";
        cout << "soFar = " << soFar << "\n";
        cout << "used = " << used << "\n";
        cout << "((wrong < MAX_WRONG) && (soFar != THE_WORD)) = " << ((wrong < MAX_WRONG) && (soFar != THE_WORD)) << "\n" << "\n";
    }

    while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
        cout << "\nYou have " << (MAX_WRONG - wrong) << " incorrect guesses left.\n";
        cout << "\nYou've used the following letters: " << used << "\n";
        cout << "\nSo far, the word is: " << soFar << "\n";
        char guess;
        cout << "\nEnter your guess: ";
        cin >> guess;
        guess = toupper(guess);

        if (debug) {
            cout << "\nguess = " << guess << "\n";
            cout << "(used.find(guess) != string::npos) = " << (used.find(guess) != string::npos) << "\n";
        }

        while (used.find(guess) != string::npos) {
            cout << "\nYou've already guessed " << guess << "\n";
            cout << "\nEnter your guess: ";
            cin >> guess;
            guess = toupper(guess);

            if (debug) {
                cout << "\nguess = " << guess << "\n";
                cout << "(used.find(guess) != string::npos) = " << (used.find(guess) != string::npos) << "\n";
            }
        }
        used += guess;

        if (debug) {
            cout << "(THE_WORD.find(guess) != string::npos) = " << (THE_WORD.find(guess) != string::npos) << "\n";
        }

        if (THE_WORD.find(guess) != string::npos) {
            cout << "That's right! " << guess << " is in the word.\n\n";
            for (unsigned int i = 0; i < THE_WORD.length(); ++i) {
                if (debug) {
                    cout << "(THE_WORD[i] == guess) = " << (THE_WORD[i] == guess) << "\n";
                }
                if (THE_WORD[i] == guess) {
                    soFar[i] = guess;
                }
            }
        }
        else {
            cout << "Sorry, " << guess << " isn't in the word.\n\n";
            ++wrong;
        }

        if (debug) {
            cout << "wrong = " << wrong << "\n";
            cout << "soFar = " << soFar << "\n";
            cout << "used = " << used << "\n";
            cout << "((wrong < MAX_WRONG) && (soFar != THE_WORD)) = " << ((wrong < MAX_WRONG) && (soFar != THE_WORD)) << "\n";
        }
    }

    if (debug) {
        cout << "(wrong == MAX_WRONG) = " << (wrong == MAX_WRONG) << "\n";
    }

    if (wrong == MAX_WRONG) {
        cout << "\nYou didn't guess it!";
    }
    else {
        cout << "\nYou guessed it!";
    }
    cout << "\nThe word was " << THE_WORD;

    if (debug) {
        cout << "\nDebug mode is OFF.\n";
    }
    system("pause>nul");
}
