#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "Core/lexer.h"
#include "Core/parser.h"
#include "Core/Libraries/library.h"



int main(int argc, char *argv[]){
    //char line[] = "Hello World!";
    char line[] = "log('string')";

    // current token
    char tok[] = "";
    // current token (to return)
    char token[] = "";
    // current tokens
    char tokens[15][1000];

    // stored string values
    char string[] = ""; // ''
    char string2[] = ""; // ""


    // position to insert new token
    int tokPos = 0;

    // currently commented
    bool commented;

    // current states
    bool strState; // ''
	bool strState2; // ""
    bool charState;
    bool funcState;

    int len = strlen(line);
    for (int i = 0; i < len; i++){
        // current character
        char ch = line[i];

        // add char to token
        strncat(tok, &ch, 1);
        printf("%s\n", tok);


        if (strState){
            strncpy(string, &ch, 1);
        }
        else if (strState2){
            strncpy(string2, &ch, 1);
        }
        else if (ch == '('){
            // create token
            char f[] = "FUNC:";
			printf(tok);
            strcpy(token, f);
            delchar(tok, -1, 1);
        	//strcpy(token, tok); //add function name
            // return token
            strcpy(tokens[tokPos], token);
            strcpy(tok, ""); //reset token
            tokPos++;
        }
        else if (ch == ')'){
			addTok(tokens, "FUNC_END", tok, tokPos);
        }

		else if (ch == '\''){
			if (strState){
                addTok(tokens, "q1", tok, tokPos);
			}
			// invert state
			strState = !strState;
		}
        else if (ch == '\"'){
			if (strState2){
                addTok(tokens, "q2", tok, tokPos);
			}
			// invert state
			strState2 = !strState2;
		}
    }

    // print everything in array
    for (int i = 0; i < tokPos; i++){
        printf("[%s], ", tokens[i]);
    }

    return 0;
}
