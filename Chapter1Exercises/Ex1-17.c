#include <stdio.h>
#define MAX_SIZE 1000
#define PRINT_THRESHOLD 80

int fGetLine (char input[], int limit);

int main () {
    int length;
    char line[MAX_SIZE];

    while ((length = fGetLine(line, MAX_SIZE)) > 1) {
        if (length >= PRINT_THRESHOLD) {
            printf("%s", line);
        } else {
            printf("Line does not exceed 80 characters\n");
        }
    }
    printf("Terminating program\n");
    return 0;
}

int fGetLine(char s[], int lim) {
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