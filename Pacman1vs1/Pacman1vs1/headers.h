#pragma once
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Point {
public:
	int x;
	int y;
	virtual vector <vector<char>> place(vector <vector<char>>) = 0;
};

class Player :public Point {
public:
	virtual vector <vector<char>> place(vector <vector<char>>);

	Player();
};

class Krok {
	public:

	int x;
	int y;

	Krok();
	Krok(int a, int b);
};

class Bot :public Point {
public:
	virtual vector <vector<char>> place(vector <vector<char>>);

	Bot();
	stack<Krok> bfs(vector<vector<char>>, Bot);
};


class Punkt :public Point {
public:
	virtual vector <vector<char>> place(vector <vector<char>>);

	Punkt();
};


void show(vector <vector<char>>);
vector<vector<char>> read_map(string);
int gra();
void menu();
void help();
void aut();
