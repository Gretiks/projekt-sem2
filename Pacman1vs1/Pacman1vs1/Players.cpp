#include "headers.h"

Player::Player() {
	x = 1;
	y = 1;
}

void Player::place(vector <vector<char>> v) {
	v[x][y] = 'P';
}