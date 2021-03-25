#include <stdio.h>
#define MAX_SIZE 50

int fGetLine (char input[], int limit);
int trim (char input[], int size);

int main () {
    int length;
    char line[MAX_SIZE];
    char c;

    while ((length = fGetLine(line, MAX_SIZE)) > 1) {
        printf("%s", line);
        printf("Size with space: %d\n", length);
        length -= trim(line, length);
        printf("Size without space: %d\n", length);
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

int trim(char s[], int size) {
    int wsCount = 0;
    if (size-2 == 0) {
        s[0] == '\0';
        s[1] == '\0';
        return 2;
    }
    for (int i = (size-2); i >= 0; i--) {
        if (s[i] == '\t' || s[i] == ' ') {
            s[i] = '\0';
            wsCount++;
        } else {
            break;
        }
    }
    return wsCount;
}