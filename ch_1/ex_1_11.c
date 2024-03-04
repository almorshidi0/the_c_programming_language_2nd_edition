#include <stdio.h>
#define IN  0   /* inside a word */
#define OUT 1   /* outside a word */

/* count lines, words, and characters in input */
void main(void)
{
    char c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == ' ' || c == '\n' || c == '\t'){
            state = OUT;
            if (c == '\n')
                ++nl;
        }
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}