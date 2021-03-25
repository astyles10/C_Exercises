#include <stdio.h>
#define MAXLINE 20

int exGetLine(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];
    int c;

    max = 0;
 
    while ((len = exGetLine(line, MAXLINE)) > 1) {
        printf("Length: %d\n", len);
        if (line[len - 1] != '\n') {
            while((c = getchar()) != EOF) {
                if (c == '\n') {
                    len++;
                    break;
                }
                len++;
            }
        }
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    printf("Max value: %d\n", max);
    if (max > 0)
        printf("Longest line: %s\n", longest);

    printf("%d\n", line[len]);
    return 0;
}

int exGetLine(char s[], int lim) {
    int c;
    int i;

    for (i = 0; i < lim-1 && ((c = getchar()) != EOF) && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i++] = c;
    }

    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i = 0;

    while ((to[i] = from[i]) != '\0')
        ++i;
}