#include <stdio.h>

/* print Celsius-Fahrenheit table for celsius = 0, 20, ..., 300;
    floating−point version */
void main(void){
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    celsius = lower;
    printf("Celsius\tFahr\n");
    while(celsius <= upper){
        fahr = ((9.0 / 5.0) * celsius) + 32.0;
        printf("%7.1f\t%4.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}