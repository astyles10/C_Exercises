#include <limits.h>
#include <float.h>
#include <stdio.h>
#define UNSIGNED_MIN 0

int main (void) {
    // Char range
    printf("unsigned char - Min: %u Max: %u\n", UNSIGNED_MIN, UCHAR_MAX);
    printf("signed char - Min: %d Max: %d\n", CHAR_MIN, CHAR_MAX);

    printf("unsigned short - Min: %d Max: %u\n", UNSIGNED_MIN, USHRT_MAX);
    printf("signed short - Min: %d Max: %d\n", SHRT_MIN, SHRT_MAX);

    // Int range
    printf("unsigned int - Min: %d Max: %u\n", UNSIGNED_MIN, UINT_MAX);
    printf("signed int - Min: %d Max: %d\n", INT_MIN, INT_MAX); 

    // Long range
    printf("unsigned long - Min: %d Max: %u\n", UNSIGNED_MIN, ULONG_MAX);
    printf("signed long - Min: %ld Max: %ld\n", LONG_MIN, LONG_MAX);

    // Float range
    printf("Float min: %.10e Float max: %.10e\n", FLT_MIN, FLT_MAX);
    printf("Double min: %.10e Double max: %.10e\n", DBL_MIN, DBL_MAX);
}