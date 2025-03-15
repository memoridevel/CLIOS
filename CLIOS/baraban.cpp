#include "Header.h"

void baraban() {
	double sum, old, max;
	int n;
	int baraban[3]{};
	bool continued;
	srand(static_cast<unsigned int>(time(0)));
	printTitle(rus("Барабан"), "0.98");

	cout << rus("Введите сумму: ");
	cin >> sum;
	old = sum;
	max = sum;
	do {
		cout << rus("Сколько раз вращать: ");
		cin >> n;
		for (int i = 0; i < n; i++) {
			system("cls");
			continued = false;
			baraban[0] = rand() % 7 ? rand() % 10 : baraban[2];
			baraban[1] = rand() % 7 ? rand() % 10 : baraban[0];
			baraban[2] = rand() % 7 ? rand() % 10 : baraban[1];
			sum = floor((baraban[0] == baraban[1] && baraban[1] == baraban[2] && baraban[2] == 7 ? sum * 7 : baraban[0] == baraban[1] && baraban[1] == baraban[2] ? sum * 3.5 : baraban[0] == baraban[1] || baraban[0] == baraban[2] || baraban[1] == baraban[2] ? sum * 1.75 : baraban[0] == baraban[1] && baraban[1] == baraban[2] && baraban[2] == 6 ? 0 : sum / 2) * 100) / 100;
			if (sum > max) max = sum;
			cout << baraban[0] << baraban[1] << baraban[2] << "\t\t";
			printf("%.2f\n", sum);
			if (sum < 0.01) {
				cout << rus("Деньги закончились\n");
				break;
			}
		}
	} while (n && sum >= 0.01);
	printf(rus("Счёт: %.2f, Исходный: %.2f, Максимальный: %.2f\n"), sum, old, max);
}