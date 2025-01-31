#pragma once
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int X_BEGIN = 1, X_END = 118, Y_BEGIN = 3, Y_END = 28;
const string commands[] = { "crypt", "paint", "sample", "field", "ttt" };

void printTitle(string name, string version);
void logo();

void crypt();
string encrypt(string input);
string decrypt(string input);

void paint();
void gotoxy(short x, short y);
void border();

void sample();
void printLine(int n, string c1, string c2);
void printSymbol(string c);
void printSymbolN(int n, string c);
void printBattery(int z);

void field(string name, bool debug);
//void ban();

void ttt();
void gameVer(string ver);
void instructions();
char askYN();
int askNum(string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(const vector<char>& board);
char winner(const vector<char>& board);
bool isLegal(const vector<char>& board, int move);
int humanMove(const vector<char>& board, char human);
int computerMove(const vector<char> board, char computer);
void announceWinner(char winner, char computer, char human);
