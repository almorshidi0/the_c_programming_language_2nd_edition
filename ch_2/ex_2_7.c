#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

void main(void){
    printf("%d\n", invert(255, 3, 3));
}

unsigned invert(unsigned x, int p, int n){
    x ^= ((~(~0 << n)) << (p + 1 - n));
    return x;
}