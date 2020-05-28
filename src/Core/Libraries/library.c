#include <string.h>

void delchar(char *x,int a, int b)
{
	if ((a+b-1) <= strlen(x))
	{
		strcpy(&x[b-1],&x[a+b-1]);
	}
}

// add a token
void addTok(char tokens[15][1000], char token[], char tok[], int pos){
	// list of tokens
	// lexed token to return
	// token to reset
	// position to insert token

	strcpy(tokens[pos], token); // return token
	strcpy(tok, ""); // reset token
	pos++; // increment insert position
}
