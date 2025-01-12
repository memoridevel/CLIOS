#include <iostream>
#include <clocale>
#include <chrono>
#include <thread>

using namespace std;

void printLine(int n, string c1, string c2);
void printSymbol(string c);
void printSymbolN(int n, string c);
void printBattery(int z);

void sample()
{
	setlocale(LC_ALL, "");
	cout << "Зарядка...";
	system("pause>nul");
	const int n = 100;
	int m[n + 1], tmp = 115;
	for (int i = 0; i <= n; i++)
	{
		m[i] = i;
	}
	for (int i = 0; i <= n; i++)
	{
		system("cls");
		if (m[i] / 20 > 4)
		{
			system("color 04");
		}
		else if (m[i] / 20 > 3)
		{
			system("color 0c");
		}
		else if (m[i] / 20 > 2)
		{
			system("color 06");
		}
		else if (m[i] / 20 > 1)
		{
			system("color 0e");
		}
		else if (m[i] / 20 > 0)
		{
			system("color 02");
		}
		else
		{
			system("color 0a");
		}
		printLine(118, "+", "-");
		if (m[i] < 10)
		{
			tmp = 9;
		}
		else if (m[i] < 100)
		{
			tmp = 8;
		}
		else
		{
			tmp = 7;
		}
		tmp += n - i;
		printLine(118, "|", " ");
		printSymbol("|");
		printSymbolN(m[i], "#");
		printSymbolN(tmp, " ");
		cout << m[i] << "%";
		printSymbolN(7, " ");
		printSymbol("|");
		printLine(118, "|", " ");
		printLine(118, "+", "-");
		printBattery(m[i] / 10);
		this_thread::sleep_for(chrono::milliseconds(500));
	}
}

void printLine(int n, string c1, string c2)
{
	printSymbol(c1);
	printSymbolN(n, c2);
	printSymbol(c1);
}

void printSymbol(string c)
{
	cout << c;
}

void printSymbolN(int n, string c)
{
	for (int i = 0; i < n; i++)
	{
		cout << c;
	}
}

void printBattery(int z)
{
	cout << "\n\n";
	printSymbolN(55, " ");
	printLine(6, "+", "-");
	cout << "\n";
	printSymbolN(55, " ");
	switch (z)
	{
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
		printLine(6, "|", " ");
		cout << "\n";
		break;
	case 10:
		printLine(6, "|", "#");
		cout << "\n";
		break;
	}
	printSymbolN(53, " ");
	switch (z)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
		printLine(6, "+-+", " ");
		cout << "\n";
		break;
	case 9:
	case 10:
		printLine(6, "+-+", "#");
		cout << "\n";
		break;
	}
	printSymbolN(53, " ");
	int tmp = z;
	if (z > 8)
	{
		z = 8;
	}
	for (int i = 0; i < 8 - z; i++)
	{
		printLine(10, "|", " ");
		cout << "\n";
		printSymbolN(53, " ");
	}
	for (int i = 0; i < z; i++)
	{
		printLine(10, "|", "#");
		cout << "\n";
		printSymbolN(53, " ");
	}
	printLine(10, "+", "-");
	cout << "\n";
}