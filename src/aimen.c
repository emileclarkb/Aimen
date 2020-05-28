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

        if (commented){
            strcpy(tok, "");
            continue;
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
    }

    // print everything in array
    for (int i = 0; i < tokPos; i++){
        printf("[%s], ", tokens[i]);
    }
}



// int main(int argc, char *argv[]){
//     // line of code
//     char line[] = "log()";
//
//     // current token
//     char tok[] = "";
//     // all stored tokens
//     char tokens[1000][15];
//     // position to insert new token
//     int tokPos;
//
//     // stored string
//     char string[] = "";
//     // currently commented
//     bool commented;
//
//     // current states
//     bool strState;
//     bool charState;
//     bool funcState;
//
//     // line length
//     int len = strlen(line);
//     // iterate through characters in line
//     for (int i = 0; i < len; i++){
//         // current character
//         char ch = line[i];
//
//         // add char to token
//         strncat(tok, &ch, 1);
//
//         if (commented){
//             tok = "";
//             break;
//         }
//         else if (ch == ')'){
//             printf("FUNC_END");
//             tok = "";
//             tokPos++;
//         }
//     }
// }
