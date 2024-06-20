#include "headers.h"

using namespace std;

void menu() {
		system("CLS");
		cout << "PACMAN 1vs1" << endl;
		cout << "1 - GRAJ" << endl << "2 - POMOC" << endl << "3 - AUTORZY" << endl << "4 - WYJSCIE" << endl;
}

void help() {
	system("CLS");
	cout << "1. Poruszasz sie za pomoca klawiszy w a s d\n2. Twoim zadaniem jest zebranie 30 punktow przed twoim przeciwnikiem\n3. Znakiem '#' oznaczone sa sciany\n4. Twoja postac oznaczona jest symbolem 'P'\n5. Przeciwnik oznaczony jest symbolem 'E'\n";
	system("Pause");
}

void aut() {
	system("CLS");
	cout << "Autorzy projektu:" << endl << "Mateusz Baginski" << endl << "Maciej Sztucki" << endl;
	system("Pause");
}

string menu_map() {
	system("CLS");
	char in = 'a';
	while (in != '1' || in != '2' || in != '3') {
		system("CLS");
		cout << "Wybierz mape: 1, 2 lub 3" << endl;
		cin >> in;
		if (in == '1')
			return "1.txt";
		else if (in == '2')
			return "2.txt";
		else if (in == '3')
			return "3.txt";
	}
}