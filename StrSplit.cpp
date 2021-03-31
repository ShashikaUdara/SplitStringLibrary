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
			// add to the string pack
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

	return tBuff;
}

string StrSplit ::setToString(char* val)
{
	int i;
	int count = 0;
	do
	{
		count++;
	}
	while(val[count] != '\0');

	string rStr;

	for (i=0; i < count; i++)
		rStr += val[i];

	return rStr;
}

int StrSplit :: strToInt(string buff)
{
	int i, iRet = 0;
	int iter = buff.length();

	for(i=iter; i>0; i--)
		iRet += ((int)buff[iter - i] - 48) * getNumberPower(10,i-1);

	return iRet;
}

double StrSplit :: strToDuble(string buff)
{
	int i, desPoint = 0;
	int iter = buff.length();
	int iterDesOff;
	double dRet = 0;

	string buffDesOff;

	for(i=0; i<iter; i++)
	{
		if(buff[i] != '.')
		{
			buffDesOff += buff[i];
		}
		else
		{
			desPoint++;
		}
	}

	iterDesOff = buffDesOff.length();

	for(i=iterDesOff; i>0; i--)
		dRet += ((int)buffDesOff[iterDesOff - i] - 48) * getNumberPower(10,i-1);

	return dRet/getNumberPower(10, desPoint);
}

double StrSplit :: getNumberPower(int base, int expo)
{
    int i, tempVal = 1;
    double dRet = 1;


    if(expo < 0)
    	return -1;

    for(i=0; i<expo; i++)
    	dRet = dRet * base;

    return dRet;
}