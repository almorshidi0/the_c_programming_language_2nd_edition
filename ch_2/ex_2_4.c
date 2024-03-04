#include <stdio.h>

#define SIZE 1000

void squeeze(char s1[], char s2[]);

void main(void){
    char s[SIZE] = "Arbitrary: Each time a non-c occurs, it is copied into the current j position.";
    squeeze(s, "aeiouAEIOU");
    printf("%s\n", s);
}

void squeeze(char s1[], char s2[]){
    int i, j;
    char k;
    for(k = 0; s2[k] != '\0'; k++){
        for (i = j = 0; s1[i] != '\0'; i++)
            if (s1[i] != s2[k])
                s1[j++] = s1[i];
        s1[j] = '\0';
    }
}