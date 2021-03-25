#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int fgetline (char line[], int max);
int strindex (char source[], char searchfor[]);

char pattern[] = "could";

int main (void) {
    char line[MAXLINE];
    int found = 0;
    int index = 0;

    while (fgetline(line, MAXLINE) > 0) {
        if ((index = strindex(line, pattern)) >= 0) {
            printf("%s", line);
            printf("Index: %d\n", index);
            found++;
        }
    }
    return found;
}

int fgetline (char line[], int max) {
    int c, i;

    i = 0;
    while (--max > 0 && (c=getchar()) != EOF && c != '\n')
        line[i++] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}

int strindex(char s[], char t[]) {
    int i, j, k;
    i = strlen(s);

    for (i = (strlen(s) - 1); i >= 0; i--) {
        for (j = i, k = (strlen(t) - 1); k > 0 && s[j] == t[k]; j--, k--)
            ;

        if (k == 0)
            return (i - (strlen(t) - 1));
    }
    return -1;
}