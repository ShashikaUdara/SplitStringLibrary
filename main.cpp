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
	return 0;
}	