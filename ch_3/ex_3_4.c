#include <stdio.h>
#include <string.h>

#define ABS(number)  (((number) < 0)? -(number) : (number))

void reverse(char s[]);
void itoa(int n, char s[]);

void main(){
    // Test Case 1: Positive number
    int num1 = 12345;
    char result1[20];
    itoa(num1, result1);
    printf("Test Case 1: %d -> %s\n", num1, result1);

    // Test Case 2: Negative number
    int num2 = -6789;
    char result2[20];
    itoa(num2, result2);
    printf("Test Case 2: %d -> %s\n", num2, result2);

    // Test Case 3: Zero
    int num3 = 0;
    char result3[20];
    itoa(num3, result3);
    printf("Test Case 3: %d -> %s\n", num3, result3);

    // Test Case 4: Large positive number
    int num4 = 2147483647; // Max value for a 32-bit signed integer
    char result4[20];
    itoa(num4, result4);
    printf("Test Case 4: %d -> %s\n", num4, result4);

    // Test Case 5: Large negative number
    int num5 = -2147483648; // Min value for a 32-bit signed integer
    char result5[20];
    itoa(num5, result5);
    printf("Test Case 5: %d -> %s\n", num5, result5);
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[]){
    int i, sign;

    sign = n;
    i = 0;

    do { /* generate digits in reverse order */
            s[i++] = ABS(n % 10) + '0'; /* get next digit */
    } while ((n /= 10) != 0); /* delete it */

    if (sign < 0)
        s[i++] = '-';
    
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
