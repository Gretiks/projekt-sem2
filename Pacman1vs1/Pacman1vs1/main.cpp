#include "headers.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	int opcja = 0;
	opcja = menu();
	if (opcja == 4) {
		return 0;
	}
	
	string map_name = "test.txt";
	vector<vector<char>> v; // przechowuje wektory ktore maja w sobie kolejne linijki planszy
	Punkt pkt = Punkt();

	v = read_map(map_name);
	Player player = Player();
	v = player.place(v);
	v = pkt.place(v);

	show(v);

	system("pause");

	return 0;
}