#include <iostream>
#include "StrSplit.h"

using namespace std;
// this main area is for testing purposes
int main()
{
	StrSplit sp;
	word *w = NULL;

	w = sp.splitByToken("On various occasions you may need to clear the unwanted buffer so as to get the next input in the desired container and not in the buffer of previous variable. For example, in case of C after encountering “scanf()” , if we need to input a character array or character ,and in case of C++, after encountering“cin” statement, we require to input a character array or a string , we require to clear the input buffer or else the desired input is occupied by buffer of previous variable, not by the desired container.On pressing “Enter” (carriage return) on output screen after the first input , as the buffer of previous variable was the space for new container(as we did’nt clear it) , the program skips the following input of container.", "the");
	while(w != NULL)
	{
		cout<<w->data<<endl;
		w = w->next;
	}

	// converting following values to strings
	// integer 1234 to string
	cout<<sp.setToString(1234)<<endl;

	// double 12345.45678 to string
	cout<<sp.setToString(12345.45678)<<endl;;

	// float 0.234 to string
	cout<<sp.setToString(0.234)<<endl;

	char cStr[] = "char array will be converterd in to a String";
	
	int sSize = sizeof(cStr)/sizeof(char);
	cout<<sSize<<endl;

	string s = sp.setToString(cStr);
	cout<<s<<endl;

	cout<<"12345678 to integer: "<<sp.strToInt("12345678")<<endl;

	// cout<<"10 to the power of 1: "<<sp.getNumberPower(10, 1)<<endl;

	return 0;
}	