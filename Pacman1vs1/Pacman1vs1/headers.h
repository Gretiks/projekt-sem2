#pragma once
#include <iostream>

class Map {
	char map_table[11][11];

public:
	Map(); //stworzy pust� map� - do test�w
	//Map(string name); //wczyta map� o zadanej nazwie z pliku
	virtual ~Map();

	void show(); //wy�wietli map�
};