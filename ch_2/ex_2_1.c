#include <stdio.h>
#include <limits.h>
#include <float.h>

#define ALL_HIGH_CHAR       ((unsigned char)    (~(0))) // 1111 1111
#define ALL_HIGH_SHORT      ((unsigned short)   (~(0))) // 1111 1111 1111 1111
#define ALL_HIGH_INT        ((unsigned int)     (~(0))) // 1111 1111 1111 1111 1111 1111 1111 1111
#define ALL_HIGH_LONG       ((unsigned long)    (~(0))) // 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111

void main(void){
    printf("Integer Types\nFrom Standard Headers\n");
    printf("signed char max: %hhd\tsigned char min: %hhd\n", SCHAR_MAX, SCHAR_MIN);
    printf("unsigned char max: %hhu\tunsigned char min: %hhu\n", UCHAR_MAX, 0U);
    printf("BY Direct Computations\n");
    printf("signed char max: %hhd\tsigned char min: %hhd\n", ((unsigned char)(ALL_HIGH_CHAR >> 1)), ((signed char)(~(ALL_HIGH_CHAR >> 1))));
    printf("unsigned char max: %hhu\tunsigned char min: %hhu\n\n", ((signed char)(ALL_HIGH_CHAR)), 0U);

    printf("From Standard Headers\n");
    printf("signed short max: %hd\tsigned short min: %hd\n", SHRT_MAX, SHRT_MIN);
    printf("unsigned short max: %hu\tunsigned short min: %hu\n", USHRT_MAX, 0U);
    printf("BY Direct Computations\n");
    printf("signed short max: %hd\tsigned short min: %hd\n", ((signed short)(ALL_HIGH_SHORT >> 1)), ((signed short)(~(ALL_HIGH_SHORT >> 1))));
    printf("unsigned short max: %hu\tunsigned short min: %hu\n\n", ((unsigned short)(ALL_HIGH_SHORT)), 0U);

    printf("From Standard Headers\n");
    printf("signed int max: %d\tsigned int min: %d\n", INT_MAX, INT_MIN);
    printf("unsigned int max: %u\tunsigned int min: %u\n", UINT_MAX, 0U);
    printf("BY Direct Computations\n");
    printf("signed int max: %d\tsigned int min: %d\n", ((signed int)(ALL_HIGH_INT >> 1)), ((signed int)(~(ALL_HIGH_INT >> 1))));
    printf("unsigned int max: %u\tunsigned int min: %u\n\n", ((unsigned int)(ALL_HIGH_INT)), 0U);

    printf("From Standard Headers\n");
    printf("signed long max: %ld\tsigned long min: %ld\n", LONG_MAX, LONG_MIN);
    printf("unsigned long max: %lu\tunsigned long min: %lu\n", ULONG_MAX, 0LU);
    printf("BY Direct Computations\n");
    printf("signed long max: %ld\tsigned long min: %ld\n", ((signed long)(ALL_HIGH_LONG >> 1)), ((signed long)(~(ALL_HIGH_LONG >> 1))));
    printf("unsigned long max: %lu\tunsigned long min: %lu\n\n", ((unsigned long)(ALL_HIGH_LONG)), 0LU);

    printf("Float Types\nFrom Standard Headers\n");
    printf("float max: %f\tfloat min: %f\n", FLT_MAX, FLT_MIN);

    printf("double max: %lf\tdouble min: %lf\n", DBL_MAX, DBL_MIN);

    printf("long double max: %Lf\tlong double min: %Lf\n", LDBL_MAX, LDBL_MIN);
}