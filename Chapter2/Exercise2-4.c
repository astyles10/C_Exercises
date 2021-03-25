#include <stdio.h>
#define MAXLINE 50

void squeeze (char s[], char c);

int main (void) {
    char s[] = { 'A', 'B', 'C', 'D', '\0' };
    char t[] = { 'A', 'B', '\0' };

    printf("Before: %s (removing \"%s\")\n", s, t);
    int i = 0;
    while (t[i] != '\0') {
        squeeze(s, t[i]);
        i++;
    }
    printf("After: %s (removing \"%s\")\n", s, t);
}

void squeeze (char s[], char c) {
    int i, j;
    i = j = 0;

    while (s[i] != '\0') {
        if (s[i] != c)
            s[j++] = s[i];
        i++;
    }
    s[j] = '\0';
}
