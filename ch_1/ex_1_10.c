#include <stdio.h>

void main(void){
    char c;
    while(c != EOF){
        c = getchar();
        if(c != ' '){
            if(c != '\t'){
                if(c != '\\')
                    putchar(c);
                if(c == '\\')
                    printf("\\\\");
            }
            if(c == '\t')
                printf("\\t");
        }
        if(c == ' '){
            printf("\\b");
        }
    }
}