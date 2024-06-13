#include "headers.h"

using namespace std;

Map::Map() {
	for (int i = 0; i < 12; i++) {
		map_table[i][0] == '#';
		map_table[i][11] == '#';
	}
	for (int j = 0; j < 12; j++) {
		map_table[0][j] == '#';
		map_table[11][j] == '#';
	}
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			map_table[i][j] == '.';
		}
	}
}

void Map::show() {
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			cout << map_table[i][j];
		}
		cout << endl;
	}
}