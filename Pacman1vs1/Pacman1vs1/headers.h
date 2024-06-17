#pragma once
#include <iostream>

class Map {
public:
	
	char map_table[12][12];


	Map(); //stworzy pust¹ mapê - do testów
	Map(string name); //wczyta mapê o zadanej nazwie z pliku
	virtual ~Map();

	void show(); //wyœwietli mapê
};