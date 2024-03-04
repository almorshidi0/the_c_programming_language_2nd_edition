#include <stdio.h>

int htoi(char str[]);

void main(void){
    printf("%d\n", htoi("0xF7a"));
}

int htoi(char str[]){
    int i =0;
    int n = 0;
    for(i = 0; str[i] != '\0'; i++){
        if((str[i] >= '0') & (str[i] <= '9')){
            if(!((i == 0) & (str[i] == 0)))
                n = n * 10 + str[i] - '0';
        }
        else if((str[i] >= 'A') & (str[i] <= 'F'))
            n = n * 10 + str[i] - 'A' + 10;
        else if((str[i] >= 'a') & (str[i] <= 'f'))
            n = n * 10 + str[i] - 'a' + 10;
    }
    return n;
}