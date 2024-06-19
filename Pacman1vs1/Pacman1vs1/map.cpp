#include "headers.h"
#include <fstream>
#include <iostream>
#include <string>
#include <random>

using namespace std;

random_device rd; // losowy numer
mt19937 gen(rd()); // seed dla generatora
uniform_int_distribution<> distr(1, 10); // losowy numer od 1 do 10

vector<vector<char>> read_map(string name) {
	ifstream plik(name);
	
	string s = "a"; //zmienna przyjmujaca obecny znak w pliku
	vector<vector<char>> vr;
	vector <char> vc; // wektor odpowiedzialny za przechowywanie linijki

	for (int i = 0; i < 12; i++) {
		getline(plik, s);
		for (int j = 0; j < s.size(); j++) {
			vc.push_back(s[j]);
		}
		vr.push_back(vc);
		vc.clear();
	}

	plik.close();
	return vr;
}

void show(vector <vector<char>> vs) {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			cout << vs[i][j];
		}
		cout << endl;
	}
}

Punkt::Punkt() {
	x = 0;
	y = 0;
}

vector <vector<char>> Punkt::place(vector <vector<char>> v) {
	
	
	x = distr(gen);
	y = distr(gen);

	while (v[x][y] != ' ') {
		x = distr(gen);
		y = distr(gen);
	}
	v[x][y] = '*';
	return v;
}