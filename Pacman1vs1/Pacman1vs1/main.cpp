#include "headers.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	char input = 'a';
	menu();
	cin >> input;
	while (input != '4') {
		if (input == '2') {
			help();
			menu();
			cin >> input;
		}
		else if (input == '3') {
			aut();
			menu();
			cin >> input;
		}
		else if (input == '1') {
			string map_name = "test.txt";
			vector<vector<char>> v; // przechowuje wektory ktore maja w sobie kolejne linijki planszy

			gra();

			system("pause");
		}
		else {
			cin >> input;
			menu();
		}
	}
	return 0;
}