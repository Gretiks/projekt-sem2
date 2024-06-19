#include "headers.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

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