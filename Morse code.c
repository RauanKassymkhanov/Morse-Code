#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "function.h"


int main ()
{
    Trnslt table[]= {{'a',".-"},
        {'b',"-...",0},
        {'c',"-.-.",0},
        {'d',"-..",0},
        {'e',".",0},
        {'f',"..-.",0},
        {'g',"--.",0},
        {'h',"....",0},
        {'i',"..",0},
        {'j',".---",0},
        {'k',"-.-",0},
        {'l',".-..",0},
        {'m',"--",0},
        {'n',"-.",0},
        {'o',"---",0},
        {'p',".--.",0},
        {'q',"--.-",0},
        {'r',".-.",0},
        {'s',"...",0},
        {'t',"-",0},
        {'u',"..-",0},
        {'v',"...-",0},
        {'w',".--",0},
        {'x',"-..-",0},
        {'y',"-.--",0},
        {'z',"--..",0},
        {'1',".----",0},
        {'2',"..---",0},
        {'3',"...--",0},
        {'4',"....-",0},
        {'5',".....",0},
        {'6',"-....",0},
        {'7',"--...",0},
        {'8',"---..",0},
        {'9',"----.",0},
        {'0',"-----",0},
        {'.',".-.-.-",0},
        {',',"--..--",0},
        {'?',"..--..",0} //initializing Morse alphabet
    };
    int n,i,menucntrl;
    for (i=0; i!=39; ++i) // English alphabet + {0,1,2,..,9} + {'.' , ',' , '?'}=39
    {
        printf("%c=%s\t",table[i].letter,table[i].morse);
    }
    printf("\n");
    printf("\nGuide: First enter a number of your option and then enter a text that you want code/decode."
           "\nNote: Only the above characters are allowed.\n"
           "\nChoose your option:\n"
           "1.Code text into Morse\n"
           "2.Decode Morse into text (Use a single and double space to separate letters and words)\n"
           "0.Exit\n");
    /* this is menu control which is needed to choose your option. Using do while loop to do each task several time*/
    while (menucntrl!=0)
    {
        scanf("%d",&menucntrl);
        switch (menucntrl)
        {
        case 1:
            code(table);
            break;
        case 2:
            decode(table);
            break;
        case 0:
            printf("The statistics:\n");
            statisticDecd(table);
            statisticEncd();
            break;
        default:
            printf("Please choose a correct option!\n");
            break;
        }
    }
    return 0;
}
