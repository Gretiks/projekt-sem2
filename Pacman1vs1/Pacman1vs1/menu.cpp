#include "headers.h"

using namespace std;

int menu() {
	char in = 'a';
	while (in != 1 || in != 2 || in != 3 || in != 4) {
		system("CLS");
		cout << "PACMAN 1vs1" << endl;
		cout << "1 - GRAJ" << endl << "2 - POMOC" << endl << "3 - AUTORZY" << endl << "4 - WYJSCIE" << endl;
		cin >> in;
		if(in == '2') {
			cout << "Pomoc" << endl;
			system("PAUSE");
			in = 'a';
		}
		if (in == '3') {
			cout << "Autorzy: Maciej Sztucki i Mateusz Baginski";
			system("PAUSE");
			in = 'a';
		}
		if (in == '1') {
			return 1;
		}
		else return 0;
	}	
}