#include "headers.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string map_name = "test.txt";
	vector<vector<char>> v; // przechowuje wektory ktore maja w sobie kolejne linijki planszy


	read_map(map_name, v);
	Player player = Player();
	player.place(v);

	show(v);

	system("pause");

	return 0;
}