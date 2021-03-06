// Horse-racing_Duals_CodinGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> el_array;
	el_array.clear();
	int N;
	cin >> N; cin.ignore();
	int previos;
	int min_dif = 65535;
	for (int i = 0; i < N; i++) {
		int Pi;
		cin >> Pi; cin.ignore();
		el_array.insert(el_array.end(),Pi);
	}
	sort(el_array.begin(), el_array.end());

	for (int i = 1; i < el_array.size(); i++)
		if (el_array[i] - el_array[i - 1] < min_dif) min_dif = el_array[i] - el_array[i - 1];
	cout << min_dif << endl;
	return 0;
}