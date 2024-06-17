#include "headers.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string map_name = "test.txt";
	
	Map map = Map(map_name);

	map.show();

	return 0;
}