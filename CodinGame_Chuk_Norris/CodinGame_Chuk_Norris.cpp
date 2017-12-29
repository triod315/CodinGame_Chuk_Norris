// CodinGame_Chuk_Norris.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <string>
using namespace std;

string CharToBinary(char c)
{
	string Code = "";
	string BinaryCode = "";
	int number = (int)c;

	while (number > 1)
	{
		Code += (number % 2);
		number /= 2;
	}
	Code += number;
	for (int i = Code.length() - 1; i >= 0; i--)
	{
		BinaryCode += Code[i];
	}
	if (BinaryCode.length() % 7 != 0)
		for (int i = 0; i < BinaryCode.length() % 7; i++) BinaryCode = (char)0 + BinaryCode;
	return BinaryCode;
}

int main()
{
	string MESSAGE;
	getline(cin, MESSAGE);
	string code = "";
	for (int i = 0; i < MESSAGE.length(); i++)
	{
		code += CharToBinary(MESSAGE[i]);
	}
	for (int i = 0; i < code.length(); i++) cout << (int)code[i];
	cout << endl;
	int current_bit = 2;
	for (int i = 0; i < code.length(); i++)
	{
		if ((int)code[i] == current_bit) cout << '0';
		else
		{
			if ((int)code[i] == 1)
			{
				cout << " 0 0";
			}
			else
			{
				cout << " 00 0";
			}
		}
		current_bit = (int)code[i];
	}
	return 0;
}

