#ifndef STRSPLIT_H
#define STRSPLIT_H

#include <iostream>
#include <string>
#include <tuple>

using namespace std;

struct word
{
	string data;
	struct word *next;
};

class StrSplit
{
public:
	StrSplit()
	{
		head = NULL;
		tail = NULL;
	}

	// splitting string by token
	word *splitByToken(string, char);
	word *splitByToken(string, string);

	void setPackWord(string);
	string pickString(string, int, int);

	// convert integers/doubles/floats to strings
	string setToString(int val) { return to_string(val); }
	string setToString(double val) { return to_string(val); }
	string setToString(float val) { return to_string(val); }
	string setToString(char* val);

	// converting string to integer
	int strToInt(string);

	// getting exponential of a base
	double getNumberPower(int base, int expo);

private:
	string buff;
	word *head,*tail;
};

#endif