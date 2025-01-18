#pragma once
#include <iostream>
#include <Windows.h>
#include <clocale>
#include <chrono>
#include <thread>
#include <conio.h>

using namespace std;

void runCommand(string input);

void crypt();
void encrypt(string& input);
void decrypt(string& input);

void paint();
void gotoxy(short x, short y);
void border();

void sample();
void printLine(int n, string c1, string c2);
void printSymbol(string c);
void printSymbolN(int n, string c);
void printBattery(int z);
