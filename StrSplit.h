#ifndef STRSPLIT_H
#define STRSPLIT_H

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

private:
	string buff;
	word *head,*tail;
};

#endif