#include "StrSplit.h"
#include <iostream>

word *StrSplit :: splitByToken(string buffer, char tok)
{
	// get string length
	int buf_length, i, count = 0;
	string rBuff;
	buf_length = buffer.length();

	// get tocken match count
	for(i = 0; i<buf_length; i++)
	{
		if((buffer[i]) != tok)
		{
			rBuff += buffer[i];
		}
		else
		{
			// should add to the string pack
			cout<<"String ele: "<<rBuff<<endl;
			setPackWord(rBuff);
			rBuff = "";
		}
	}

	struct word *temp_word;
	temp_word = head;
	return temp_word;
}

word *StrSplit :: splitByToken(string buffer, string tok)
{
	int buf_length, tok_length, i, count = 0, tok_count = 0;
	string temp_buff, rBuff;

	// get string length
	buf_length = buffer.length();

	// get tok length
	tok_length = tok.length();

	// get tocken match count
	for(i = 0; i<buf_length; i++)
	{
		temp_buff = pickString(buffer, i, tok_length);

		if(i+1+tok_length != buf_length)
		{
			if(temp_buff != tok)
			{
				rBuff += buffer[i];
			}
			else
			{
				// should add to the string pack
				temp_buff = pickString(rBuff, tok_length-1, rBuff.length()-(tok_length-1));
				setPackWord(temp_buff);
				rBuff = "";
			}
		}
	}

	struct word *temp_word;
	temp_word = head;
	return temp_word;
}



void StrSplit :: setPackWord(string buffer)
{
	word *temp_word = new word;
	temp_word->data = buffer;
	temp_word->next = NULL;

	if (head == NULL)
	{
		head = temp_word;
		tail = temp_word;
	}
	else
	{
		tail->next = temp_word;
		tail = tail->next;
	}
}

string StrSplit :: pickString(string buffer, int s, int e)
{
	int i;
	string rBuff, tBuff;
	for(i = 0; i<e; i++)
	{
		tBuff += buffer[s+i];
	}
	// rBuff = removeSpaces(tBuff);
	return tBuff;
}

// string StrSplit :: removeSpaces(string str)
// {
// 	str.erase(remove(str.begin(), str.end(), ''), str.end());
// 	return str;
// }