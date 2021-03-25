#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>
#define MAXLINE 4

int htoi(char hex[]);

int main (void) {
    char hex[] = { 'A', 'F', '0', '9' };
    int convertedValue = htoi(hex);
    printf("%s conversion to int: %d\n", hex, convertedValue);
    return 0;
}

int htoi (char hex[]) {
    unsigned int retVal = 0;
    int exponent = MAXLINE - 1;
    for(int i = 0; i < MAXLINE; i++) {
        if (hex[i] >= 'A' && hex[i] <= 'F') {
            int tmp = (10 + (hex[i] - 'A'));
            retVal += tmp * (pow(16, exponent));
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            int tmp = (10 + (hex[i] - 'a'));
            retVal += tmp * (pow(16, exponent));
        } else if (hex[i] >= '0' && hex[i] <= '9') {
            int tmp = (hex[i] - '0');
            retVal += tmp * (pow(16, exponent));
        } else {
            printf("Invalid char %c\n", hex[i]);
        }
        exponent--;
    }
    return retVal;
}