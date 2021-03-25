#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main (void) {
    int x = 7562;
    int b = 11;
    char s[10000];
    itob(x, s, b);
    reverse(s);
    printf("%s\n", s);
    return 0;
}

void itob(int n, char s[], int b) {
    int i, sign, q, r;
    i = 0;
    unsigned int un;

    if ((sign = n) < 0) {
        un = -(n);
    } else {
        un = n;
    }

    do {
        q = un / b; r = un % b;
        if ((r <= 9 && r >= 0)) {
            r += '0';
        } else {
            r = (r-10) + 'a';
        }
        s[i++] = r;

        un = q;
    } while (un > 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
}

void reverse (char s[]) {
    int i, j, c;
    for (i = 0, j = (strlen(s) - 1); i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}