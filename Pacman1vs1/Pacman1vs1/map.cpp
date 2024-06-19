#include "headers.h"
#include <fstream>
#include <iostream>

using namespace std;

vector<vector<char>> read_map(string name, vector<vector<char>> vr) {
	ifstream plik(name);

	char c = '@'; //zmienna przyjmujaca obecny znak w pliku
	vector <char> vc; // wektor odpowiedzialny za przechowywanie linijki

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			plik >> c;
			vc.push_back(c);
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