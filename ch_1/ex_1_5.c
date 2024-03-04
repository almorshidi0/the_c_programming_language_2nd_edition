#include <stdio.h>

/* print Fahrenheit−Celsius table for fahr = 0, 20, ..., 300;
    floating−point version
    Reversed Order */
void main(void){
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    fahr = upper;
    printf("Fahr\tCelsius\n");
    while(fahr >= lower){
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%4.0f\t%7.1f\n", fahr, celsius);
        fahr = fahr - step;
    }
}