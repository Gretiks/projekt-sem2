#include "headers.h"

Player::Player() {
	x = 1;
	y = 1;
}

void Player::place(char map_table[12][12]) {
	map_table[x][y] = 'P';
}