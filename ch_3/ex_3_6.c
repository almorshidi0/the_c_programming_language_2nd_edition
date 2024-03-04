// Write a version of itoa that accepts three arguments instead of two. The third
// argument is a minimum field width; the converted number must be padded with blanks on the
// left if necessary to make it wide enough.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ABS(number)  (((number) < 0)? -(number) : (number))

void reverse(char s[]);
void itoa(int n, char s[], int w);

void main(){
    int number;
    int width;
    char result[20];

    // Seed the random number generator
    srand((unsigned int) time(NULL));

    for (int i = 0; i < 10; i++){
        // Test Case
        number = rand() % 1000000;
        width = rand() % 10 + 5; // Random width between 5 and 14

        itoa(number, result, width);
        printf("Test Case %d: %d with width %d: %s\n", i + 1, number, width, result);
    }
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[], int w){
    int i, sign;

    sign = n;
    i = 0;

    do { /* generate digits in reverse order */
            s[i++] = ABS(n % 10) + '0'; /* get next digit */
    } while ((n /= 10) != 0); /* delete it */

    if (sign < 0)
        s[i++] = '-';
    
    while (i < w)
        s[i++] = ' '; // Pad with blanks
        
    s[i] = '\0';
    reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[]){
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
