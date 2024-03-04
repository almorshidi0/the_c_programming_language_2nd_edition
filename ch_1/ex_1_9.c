#include <stdio.h>

void main(void){
    char c;
    char lastc = 'a';
    while(c != EOF){
        c = getchar();
        if(c != ' ')
            putchar(c);
        if(c == ' '){
            if(lastc != ' ')
                putchar(c);
        }
        lastc = c;
    }
}