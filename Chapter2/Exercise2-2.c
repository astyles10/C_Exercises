#include <stdio.h>

int main (void) {
    int lim = 20;
    char c;
    char s[lim];
    int i;
    for (i = 0; i < lim - 1 && ((c = getchar()) != EOF) && c != '\n'; ++i) {
        s[i] = c;
    }
    s[i++] = '\n';
    s[i] = '\0';

    printf("String 1: %s", s);

    int j = 0;
    char ch;
    char s2[lim];
    while (j < lim-1)
    {
        ch = getchar();
        if (ch == EOF) {
            break;
        } else if (ch == '\n') {
            s2[j] = ch;
            s2[(j+1)] = '\0';
            break;
        }
        s2[j] = ch;
        j++;
    }
    printf("String 2: %s", s2);

    return 0;
}