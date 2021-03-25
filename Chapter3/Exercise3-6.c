#include <stdio.h>
#include <string.h>

void itoa (int x, char s[], int minWidth);
void reverse (char s[]);

int main (void) {
    int x = 1234;
    int min = 10;
    char s[100];
    itoa(x, s, min);
    reverse(s);
    printf("%s\n", s);
    return 0;
}

void itoa (int n, char s[], int min) {
    int i, sign, digits;
    unsigned int un;

    if ((sign = n) < 0)
        un = -n;
    else
        un = n;

    i = 0;

    do {
        s[i++] = (un % 10) + '0';
        digits++;
    } while ((un /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';

    if (digits < min) {
        do {
            s[i++] = ' ';
            digits++;
        } while (digits < min);
    }

    s[i] = '\0';
}

void reverse (char s[]) {
    int i, j, c;
    for (i = 0, j = (strlen(s) - 1); i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}