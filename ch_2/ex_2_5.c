#include <stdio.h>

#define SIZE 1000

int any(const char s1[], const char s2[]);

void main(void){
    char s[SIZE] = "Arbitrary: Each time a non-c occurs, it is copied into the current j position.";
    int index = any(s, "aeiouAEIOU");
    printf("%d\n", index);
}

int any(const char s1[], const char s2[]){
    int i = -1;
    int j;
    for(i = 0; s1[i] != '\0'; i++){
        for (j = 0; s2[j] != '\0'; j++){
            if (s1[i] == s2[j]){
                return i;
            }
        }
    }
    return -1;
}