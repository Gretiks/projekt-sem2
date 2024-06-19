#pragma once
#include <iostream>

class Character {
public:
	virtual void place(char map_table[12][12]) = 0;
};

class Player :public Character {
	int x;
	int y;

public:
	virtual void place(char map_table[12][12]);

	Player();
};

class Bot :public Character {
	int x;
	int y;

public:
	virtual void place(char map_table[12][12]);

	Bot();
};

void show(char map_table[12][12]);
void read_map(string name, char map_table[12][12])