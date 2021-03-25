#include <stdio.h>
#define MAXLINE 50

int any (char s[], char c);

int main (void) {
    char s[] = { 'A', 'D', 'C', 'B', '\0' };
    char t[] = { 'F', 'X', 'W', 'B', '\0' };
    int i = 0;

    int charPos = 0;
    while (t[i] != '\0') {
        charPos = any(s, t[i]);
        if (charPos == -1) {
            i++;
        } else {
            break;
        }
    }
    printf("First match: %d\n", charPos);
}

int any (char s[], char c) {
    int i, j, charPos, charPosSet;
    i = charPos = 0;
    charPosSet = -1;

    while (s[i] != '\0') {
        if (s[i] == c) {
            charPos = i;
            charPosSet = 1;
            break;
        }
        i++;
    }
    if (charPosSet == -1)
        return -1;
    return charPos;
}
