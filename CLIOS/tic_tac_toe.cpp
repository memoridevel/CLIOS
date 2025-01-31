#include "Header.h"

//glob const
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';
const char DEBUG = 'D';

void ttt() {
    // стандарт. перем иниц функ ВЕЗДЕ
    // добавить pause заново break
    printTitle("Tic Tac Toe", "0.95");
    int move;
    const int NUM_SQUARES = 9;
    vector<char> board(NUM_SQUARES, EMPTY);
    instructions();
    char human = humanPiece();
    char computer = opponent(human);
    char turn = X;
    displayBoard(board);
    while (winner(board) == NO_ONE) {
        if (turn == human) {
            move = humanMove(board, human);
            board[move] = human;
        }
        else {
            move = computerMove(board, computer);
            board[move] = computer;
        }
        displayBoard(board);
        turn = opponent(turn);
    }
    announceWinner(winner(board), computer, human);
}

void gameVer(string ver) {
    cout << ver;
}

void instructions() {
    cout << "Добро пожаловать на противостояние человека и машины: Крестики-нолики.\n";
    cout << "- где человеческий мозг противостоит кремниевому процессору\n\n";
    cout << "Сделай ход, введя число от 1 до 9.\n";
    cout << "Число соответствует желаемой клетке, как показано на рисунке:\n\n";
    cout << " 1 | 2 | 3\n";
    cout << " ---------\n";
    cout << " 4 | 5 | 6\n";
    cout << " ---------\n";
    cout << " 7 | 8 | 9\n\n";
    cout << "Приготовься, человек. Битва вот-вот начнется.\n\n";
}

char askYN() {
    char c;
    int y = 16;
    cout << "Ты будешь ходить первым?\n";
    cout << "> Да\n  Нет";
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

int askNum(string question, int high, int low) {
    int number;
    do {
        cout << question << " (" << (low + 1) << " - " << (high + 1) << "): ";
        cin >> number;
        --number;
    } while (number > high || number < low);
    return number;
}

char humanPiece() {
    char goFirst = askYN();
    if (goFirst == 'y') {
        cout << "\n\nТогда сделай первый ход. Тебе это понадобится.\n";
        return X;
    }
    else {
        cout << "\nТвоя храбрость станет твоей погибелью... Я пойду первым.\n";
        return O;
    }
}

char opponent(char piece) {
    if (piece == X) {
        return O;
    }
    else {
        return X;
    }
}

void displayBoard(const vector<char>& board) {
    cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
    cout << "\n\t" << "---------";
    cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
    cout << "\n\t" << "---------";
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
    else {
        return NO_ONE;
    }
}

bool isLegal(const vector<char>& board, int move) {
    return (board[move] == EMPTY);
}

int humanMove(const vector<char>& board, char human) {
    int move = askNum("Куда ты походишь?", ((int)board.size() - 1));
    while (!isLegal(board, move)) {
        cout << "\nЭта клетка уже занята, глупый человек.\n";
        move = askNum("Куда ты походишь?", ((int)board.size() - 1));
    }
    cout << "Хорошо...\n";
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
            ++move;
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
                ++move;
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
            ++i;
        }
    }
    cout << "Я займу клетку номер " << (move + 1) << endl;
    return move;
}

void announceWinner(char winner, char computer, char human) {
    if (winner == computer) {
        cout << winner << " победил!\n";
        cout << "Как я и предсказывал, человек, я снова торжествую - доказательство\n";
        cout << "того, что компьютеры превосходят людей во всех отношениях.\n";
    }
    else if (winner == human) {
        cout << winner << " победил!\n";
        cout << "Нет, нет! Этого не может быть! Tы каким-то образом обманул меня, человек.\n";
        cout << "Но больше никогда! Я, компьютер, так клянусь в этом!\n";
    }
    else {
        cout << "Это ничья.\n";
        cout << "Тебе очень повезло, человек, и каким-то образом тебе удалось поставить ничью.\n";
        cout << "Празднуй... потому что это лучшее, чего ты когда-либо достигнешь.\n";
    }
}
