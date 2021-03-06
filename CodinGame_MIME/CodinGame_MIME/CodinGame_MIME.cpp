// CodinGame_MIME.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N; // Number of elements which make up the association table.
void transform_to_correct_order(string &str)
{
	for (int i = 0; i < str.length() / 2; i++)
		swap(str[i], str[str.length() - i - 1]);
}

void SeparateFileName(string &name, string &format, string fname)
{
	int dot_position = -1;
	name = "";
	format = "";
	for (int i = fname.length() - 1; i >= 0; i--)
	{
		if (fname[i] == '.' && dot_position == -1)
		{
			dot_position = i;
			continue;
		}
		if (dot_position == -1 || i > dot_position) format += fname[i]; else name += fname[i];
	}
	transform_to_correct_order(format);
	transform_to_correct_order(name);
	if (dot_position == -1) format = "UNKNOWN";
}

string FindFormat(string format, string * MT, string *EXT)
{
	for (int i = 0; i < N; i++)
		if (format == EXT[i]) return MT[i];
	return "UNKNOWN";

}

int main()
{

	cin >> N; cin.ignore();
	int Q; // Number Q of file names to be analyzed.
	cin >> Q; cin.ignore();

	string * EXT;// file extension
	EXT = new string[N];

	string * MT;
	MT = new string[N];
	for (int i = 0; i < N; i++) {
		cin >> EXT[i] >> MT[i]; cin.ignore();
		transform(EXT[i].begin(), EXT[i].end(), EXT[i].begin(), ::toupper);
	}

	string format, name;
	for (int i = 0; i < Q; i++) {
		string FNAME; // One file name per line.
		getline(cin, FNAME);
		transform(FNAME.begin(), FNAME.end(), FNAME.begin(), ::toupper);
		SeparateFileName(name, format, FNAME);
		cout << FindFormat(format, MT, EXT) << endl;
		//cout<<"UNKNOWN"<<endl;
	}


	delete[] EXT;
	delete[] MT;

}
