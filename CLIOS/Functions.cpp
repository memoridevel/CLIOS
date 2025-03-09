#include "Header.h"

void printTitle(string name, string version) {
	string title = name + " v" + version;
	printLine(X_END, "\315", "\315", "\315\n");
	gotoxy(short(X_END - title.length()) / 2, 0);
	cout << " " << title << " \n";
}
void gotoxy(short x, short y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x, y });
}
char* rus(const char* st) {
	static char buf[sizeof(st)];
	CharToOemA(st, buf);
	return buf;
}

void printLogo(const string* cliosLogo, const size_t& n, const byte& length) {
	for (int i = 0; i < n; i++) {
		gotoxy(short(X_END - length) / 2, short((Y_END - 3) / 2 - n / 2 + i));
		cout << cliosLogo[i];
	}
}
byte logon(string& login, string& password, const string* logins, unordered_map<string, long long>& passwords, hash<string>& hasher) {
	gotoxy(X_END - 13, 0);
	cout << "(c) memoridevel";
	gotoxy(0, 0);cout << "Welcome to CLIOS";
	while (true) {
		cout << rus("\nЛогин: ");
		cin >> login;
		if (login == "guest") {
			return 3;
		}
		cout << rus("Пароль: ");
		cin >> password;
		if (login == decrypt(logins[0]) && hasher(encrypt(password)) == passwords.at(logins[0])) {
			return 0;
		}
		else if (login == decrypt(logins[1]) && hasher(encrypt(password)) == passwords.at(logins[1])) {
			return 1;
		}
		else if (login == decrypt(logins[2]) && hasher(encrypt(password)) == passwords.at(logins[2])) {
			return 2;
		}
		else {
			cout << rus("Неверный логин или пароль");
			this_thread::sleep_for(chrono::milliseconds(2000));
		}
	}
}
void run(const string& input, const string* commands, const size_t& nC, const string& name, const byte& userRule, const string* morda, const size_t& nM, const string* hack, const size_t& nH) {
	if (find(&commands[0], &commands[nC], input) != &commands[nC]) {
		system("cls");
		if (input == commands[0]) if (userRule == 0) crypt(); else cout << rus("Отказано в доступе");
		else if (input == commands[1]) paint();
		else if (input == commands[2]) if (userRule != 3) sample(); else cout << rus("Отказано в доступе");
		else if (input == commands[3]) field(name, userRule == 0);
		else if (input == commands[4]) ttt();
		else if (input == commands[5]) if (userRule == 0 || userRule == 1) cat(morda, nM); else ban(hack, nH);
		else cout << rus("404 команда не найдена");
		system("pause>nul & cls & color 07");
	}
	else if (input == "help") {
		cout << rus("Список всех команд:\n");
		for (int i = 0; i < nC; i++) {
			cout << commands[i] << "\n";
		}
	}
	else {
		cout << "\"" + input + rus("\" не является внутренней или внешней командой, исполняемой программой или пакетным файлом.\n");
	}
}

string encrypt(string input) {
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
	return input;
}
string decrypt(string input) {
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
	return input;
}

void border(const int x, const int y, const string ul, const string ud, const string ur, const string lr, const string dl, const string dr) {
	printLine(x, ul, ud, ur);
	for (int i = 0; i < y - 1; i++) {
		gotoxy(short(X_END - 21) / 2, short(Y_END) / 2 - 4);
		printLine(x, "\n" + lr, " ", lr);
	}
	printLine(x, "\n" + dl, ud, dr);
}

void printLine(int n, string c1, string c2, string c3) {
	printSymbol(c1);
	printSymbolN(n, c2);
	printSymbol(c3);
}
void printSymbol(string c) {
	cout << c;
}
void printSymbolN(int n, string c) {
	for (int i = 0; i < n; i++) {
		cout << c;
	}
}
void printBattery(int z) {
	cout << "\n";
	printSymbolN(55, " ");
	printLine(6, "+", "-", "+\n");
	printSymbolN(55, " ");
	switch (z) {
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		printLine(6, "|", " ", "|\n");
		break;
	case 10:
		printLine(6, "|", "#", "|\n");
		break;
	}
	printSymbolN(53, " ");
	switch (z) {
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
		printLine(6, "+-+", " ", "+-+\n");
		break;
	case 9:
	case 10:
		printLine(6, "+-+", "#", "+-+\n");
		break;
	}
	printSymbolN(53, " ");
	int tmp = z;
	if (z > 8) {
		z = 8;
	}
	for (int i = 0; i < 8 - z; i++) {
		printLine(10, "|", " ", "|\n");
		printSymbolN(53, " ");
	}
	for (int i = 0; i < z; i++) {
		printLine(10, "|", "#", "|\n");
		printSymbolN(53, " ");
	}
	printLine(10, "+", "-", "+\n");
}

void instructions() {
	cout << rus("Добро пожаловать на противостояние человека и машины: Крестики-нолики.\n\
		- где человеческий мозг противостоит кремниевому процессору\n\n\
		Сделай ход, введя число от 1 до 9.\n\
		Число соответствует желаемой клетке, как показано на рисунке:\n\n\
		 1 | 2 | 3\n\
		 --+---+--\n\
		 4 | 5 | 6\n\
		 --+---+--\n\
		 7 | 8 | 9\n\n\
		Приготовься, человек. Битва вот-вот начнется.\n\n");
}
char askYN() {
	char c;
	int y = 16;
	cout << rus("Ты будешь ходить первым?\n");
	cout << rus("> Да\n  Нет");
	gotoxy(0, y);
	do {
		c = _getch();
		if (c == 80 || c == 72) {
			cout << ' ';
			if (y == 16) {
				gotoxy(0, ++y);
			}
			else {
				gotoxy(0, --y);
			}
			cout << '>';
			gotoxy(0, y);
		}
	} while (c != 13);
	return y == 16 ? 'y' : 'n';
}
int askNum(int high, int low = 0) {
	int number;
	do {
		cout << rus("Куда ты походишь ? (") << (low + 1) << " - " << (high + 1) << ") : ";
		cin >> number;
		number--;
	} while (number > high || number < low);
	return number;
}
char humanPiece() {
	char goFirst = askYN();
	if (goFirst == 'y') {
		cout << rus("\n\nТогда сделай первый ход. Тебе это понадобится.\n");
		return X;
	}
	cout << rus("\nТвоя храбрость станет твоей погибелью... Я пойду первым.\n");
	return O;
}
char opponent(char piece) {
	if (piece == X) {
		return O;
	}
	return X;
}
void displayBoard(const vector<char>& board) {
	cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
	cout << "\n\t" << "--+---+--";
	cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
	cout << "\n\t" << "--+---+--";
	cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8] << "\n\n";
}
char winner(const vector<char>& board) {
	const int WINNING_ROWS[8][3] = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6} };
	const int TOTAL_ROWS = 8;
	for (int row = 0; row < TOTAL_ROWS; ++row) {
		if ((board[WINNING_ROWS[row][0]] != EMPTY) && (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) && (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]])) {
			return board[WINNING_ROWS[row][0]];
		}
	}
	if (count(board.begin(), board.end(), EMPTY) == 0) {
		return TIE;
	}
	return NO_ONE;
}
bool isLegal(const vector<char>& board, int move) {
	return (board[move] == EMPTY);
}
int humanMove(const vector<char>& board, char human) {
	unsigned int move;
	do {
		move = askNum((int(board.size()) - 1));
		if (!isLegal(board, move)) {
			cout << rus("\nЭта клетка уже занята, глупый человек.\n");
		}
	} while (!isLegal(board, move));
	cout << rus("Хорошо...\n");
	return move;
}
int computerMove(vector<char> board, char computer) {
	unsigned int move = 0;
	bool found = false;
	while (!found && move < board.size()) {
		if (isLegal(board, move)) {
			board[move] = computer;
			found = winner(board) == computer;
			board[move] = EMPTY;
		}
		if (!found) {
			move++;
		}
	}
	if (!found) {
		move = 0;
		char human = opponent(computer);
		while (!found && move < board.size()) {
			if (isLegal(board, move)) {
				board[move] = human;
				found = winner(board) == human;
				board[move] = EMPTY;
			}
			if (!found) {
				move++;
			}
		}
	}
	if (!found) {
		move = 0;
		unsigned int i = 0;
		const int BEST_MOVES[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };
		while (!found && i < board.size()) {
			move = BEST_MOVES[i];
			if (isLegal(board, move)) {
				found = true;
			}
			i++;
		}
	}
	cout << rus("Я займу клетку номер ") << (move + 1) << endl;
	return move;
}
void announceWinner(char winner, char computer, char human) {
	if (winner == computer) {
		cout << winner << rus(" победил!\n\
			Как я и предсказывал, человек, я снова торжествую - доказательство\n\
			того, что компьютеры превосходят людей во всех отношениях.\n");
	}
	else if (winner == human) { // как этого добиться
		cout << winner << rus(" победил!\n\
			Нет, нет! Этого не может быть! Tы каким-то образом обманул меня, человек.\n\
			Но больше никогда! Я, компьютер, клянусь в этом!\n");
	}
	else {
		cout << rus("Это ничья.\n\
			Тебе очень повезло, человек, и каким-то образом тебе удалось поставить ничью.\n\
			Празднуй... потому что это лучшее, чего ты когда-либо достигнешь.\n");
	}
}
