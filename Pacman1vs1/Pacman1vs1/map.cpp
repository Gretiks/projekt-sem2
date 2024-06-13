#include "headers.h"

using namespace std;

Map::Map() {
	map_table[0][0] = 201;
	map_table[0][11] = 187;
	map_table[11][0] = 200;
	map_table[11][11] = 188;
	for (int i = 1; i < 11; i++) {
		map_table[i][0] = 186;
		map_table[i][11] = 186;
	}
	for (int j = 1; j < 11; j++) {
		map_table[0][j] = 205;
		map_table[11][j] = 205;
	}
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			map_table[i][j] = ' ';
		}
	}
}

Map::~Map() {

}

void Map::show() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			cout << map_table[i][j];
		}
		cout << endl;
	}
}