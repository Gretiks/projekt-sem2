#pragma once
#include <iostream>

class Map {
public:
	
	char map_table[12][12];


	Map(); //stworzy pust� map� - do test�w
	Map(string name); //wczyta map� o zadanej nazwie z pliku
	virtual ~Map();

	void show(); //wy�wietli map�
};