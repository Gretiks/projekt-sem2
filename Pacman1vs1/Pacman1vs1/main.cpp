#include "headers.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string map_name = "test.txt";
	char map_table[12][12];
	/*
	for (int i = 0; i < 12; i++) {
		map_table[i][0] = '#';
		map_table[i][11] = '#';
	}
	for (int j = 0; j < 12; j++) {
		map_table[0][j] = '#';
		map_table[11][j] = '#';
	}
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			map_table[i][j] = ' ';
		}
	}
	*/
	read_map(map_name, map_table);
	Player player = Player();
	player.place(map_table);

	show(map_table);

	//map.show();

	return 0;
}