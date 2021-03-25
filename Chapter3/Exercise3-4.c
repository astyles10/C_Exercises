#include <string.h>
#include <stdio.h>
#include <limits.h>

void reverse (char s[]);
void itoa (int n, char s[]);

int main (void) {
    char f = 0x80;
    char g = -(f);
    printf("%d\n", g);

    char s1[15];
    int x = INT_MIN;
    itoa(x, s1);
    reverse(s1);
    printf("%s\n", s1);
    return 0;
}

void itoa (int n, char s[]) {
    int i, sign;
    unsigned int un;

    if ((sign = n) < 0)
        un = -n;
    else
        un = n;

    i = 0;

    do {
        s[i++] = (un % 10) + '0';
    } while ((un /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
}

void reverse (char s[]) {
    int length = strlen(s);
    int c, i, j;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}