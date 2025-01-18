#pragma once
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <conio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int X_BEGIN = 1, X_END = 118, Y_BEGIN = 3, Y_END = 28;
const string commands[] = { "crypt", "paint", "sample", "field" };

void run(string input);
void printTitle(string name, string version);

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

void field();
void ban();