#include <stdio.h>

void main(void){
    char c;
    int blanks = 0;
    int tabs = 0;
    int new_lines = 0;
    while(c != EOF){
        c = getchar();
        if (c == ' ')
            blanks++;
        if (c == '\t')
            tabs++;
        if (c == '\n')
            new_lines++;
    }
    printf("\nblanks\ttabs\tnew lines\n%-6d\t%-4d\t%-9d\n", blanks, tabs, new_lines);
}