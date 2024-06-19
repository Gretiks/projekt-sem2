#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Character {
public:
	virtual vector <vector<char>> place(vector <vector<char>>) = 0;
};

class Player :public Character {
	int x;
	int y;

public:
	virtual vector <vector<char>> place(vector <vector<char>>);

	Player();
};

class Bot :public Character {
	int x;
	int y;

public:
	virtual vector <vector<char>> place(vector <vector<char>>);

	Bot();
};

void show(vector <vector<char>>);
vector<vector<char>> read_map(string);