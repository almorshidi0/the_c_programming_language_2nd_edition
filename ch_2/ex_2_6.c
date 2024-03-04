#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, int y);

void main(void){
    printf("%d\t%d\n", 157, setbits(255, 3, 3, 133));
}

unsigned setbits(unsigned x, int p, int n, int y){
    x = (((y & (~(~0 << n))) | ((x >> (p + 1 - n)) & (~0 << n))) << (p + 1 - n)) | (x & (~(~0 << (p + 1 - n))));
    return x;
}