#pragma once
#include <iostream>

class Map {
	char map_table[11][11];

public:
	Map(); //stworzy pust¹ mapê - do testów
	//Map(string name); //wczyta mapê o zadanej nazwie z pliku
	virtual ~Map();

	void show(); //wyœwietli mapê
};