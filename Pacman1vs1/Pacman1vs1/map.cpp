#include "headers.h"
#include <fstream>
#include <iostream>

using namespace std;

void read_map(string name, map_table[12][12]) {
	ifstream file(name);

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			file.get(map_table[i][j]);
		}
	}
}



void show(char map_table[12][12]) {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			cout << map_table[i][j];
		}
		cout << endl;
	}
}