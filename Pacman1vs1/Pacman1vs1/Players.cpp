#include "headers.h"

Player::Player() {
	x = 1;
	y = 9;
}

Bot::Bot() {
	x = 9;
	y = 1;
}

vector <vector<char>> Player::place(vector <vector<char>> v) {
	v[x][y] = 'P';
	return v;
}

vector <vector<char>> Bot::place(vector <vector<char>> v) {
	v[x][y] = 'B';
	return v;
}