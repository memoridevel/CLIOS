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

const int
	X_BEGIN = 1,
	X_END = 118,
	Y_BEGIN = 3,
	Y_END = 28;
const char
	X = 'X',
	O = 'O',
	EMPTY = ' ',
	TIE = 'T',
	NO_ONE = 'N',
	DEBUG = 'D';

void printTitle(string, string);
void gotoxy(short, short);

void printLogo(const string*, const size_t&);
byte logon(string&, string&, const string*, unordered_map<string, long long>&, hash<string>&);
void run(const string&, const string*, const size_t&, const string&, const byte&);

void crypt();
string encrypt(string);
string decrypt(string);

void paint();
void border();

void sample();
void printLine(int, string, string, string);
void printSymbol(string);
void printSymbolN(int, string);
void printBattery(int);

void field(string, bool);

void ttt();
void instructions();
char askYN();
int askNum(int, int);
char humanPiece();
char opponent(char);
void displayBoard(const vector<char>&);
char winner(const vector<char>&);
bool isLegal(const vector<char>&, int);
int humanMove(const vector<char>&, char);
int computerMove(const vector<char>, char);
void announceWinner(char, char, char);
