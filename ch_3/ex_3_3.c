#include <stdio.h>

#define TESTS_SIZE 8
#define SIZE 100

void expand(const char *s1, char *s2);

void main(){
    char *tests[TESTS_SIZE] = {"a", "a-", "a-z", "A-Z", "0-9", "a-cX-Z0-2", "abc", ""};
    char result[SIZE]; // Adjust the size based on your needs

    for(int i = 0; i < TESTS_SIZE; i++){
        expand(tests[i], result);
        printf("Test Case %d: %s\n%s\n\n", i, tests[i], result);
    }
}

void expand(const char *s1, char *s2){
    int i, j;
    char c, start, end;
    for(i = j = 0; s1[i] != '\0'; i++, j++){
        if(((s1[i] != '-') || s1[i + 1] == '\0') ||
          !((((s1[i - 1] >= 'a') && (s1[i - 1] <= 'z')) ||
             ((s1[i - 1] >= 'A') && (s1[i - 1] <= 'Z')) ||
             ((s1[i - 1] >= '0') && (s1[i - 1] <= '9'))) &&
            (((s1[i + 1] >= 'a') && (s1[i + 1] <= 'z')) ||
             ((s1[i + 1] >= 'A') && (s1[i + 1] <= 'Z')) ||
             ((s1[i + 1] >= '0') && (s1[i + 1] <= '9'))))
          ){
            s2[j] = s1[i];
            continue;
        }
        start = s1[i - 1] + 1;
        end = s1[i + 1] - 1;
        for(c = start; c <= end; c++){
            s2[j] = c;
            if(c != end)
                j++;
        }
    }
    s2[j] = '\0';
}