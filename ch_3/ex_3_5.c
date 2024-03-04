#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ABS(number)  (((number) < 0)? -(number) : (number))

void reverse(char s[]);
int itob(int n, char s[], int b);

void main(){
    int number;
    int base;
    char result[20];

    srand((unsigned int) time(NULL));
    for(int i = 0; i < 10; i++){
        // Test Case
        number = rand() % 1000000;
        base = i % 2 == 0? rand() % 10 : rand() % 40;
        base = i % 4 == 0? rand() % 20 : rand() % 40;
        itob(number, result, base);
        printf("Test Case %d: %d in base %d: %s\n", i + 1, number, base, result);
        // Reset
        for (int i = 0; i < sizeof(result); i++) {
            result[i] = 0;
        }
    }
}

int itob(int n, char s[], int b){
    int digit = 0;
    int i = 0;
    if(b - 10 + 'A' <= 'Z'){
        while(n > 0){
            digit = n % b;
            n /= b;
            if(digit < 10){
                s[i] = digit + '0';
                i++;
            }
            else{
                s[i] = digit - 10 + 'A';
                i++;
            }
        }
    }
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