#include <stdio.h>
#define MAX_SIZE 25

int spacesPerTab = 4;
void detab(char s[], char s2[], int spaces);
void entab(char s[], char ts[], int tabWidth);
int fGetLine(char s[], int lim);

int main () {
    int length;
    char line[MAX_SIZE];
    char solution[MAX_SIZE];

    while ((length = fGetLine(line, MAX_SIZE)) > 1) {
        extern int spacesPerTab;
        entab(line, solution, spacesPerTab);
        printf("Old Line: %s", line);
        printf("Solution line: %s", solution);
        printf("\n");
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

int determineSpaces(int tabWidth, int index) {
    return tabWidth - (index % tabWidth);
}

void entab(char s[], char ts[], int spacesPerTab) {
    char c;
    int i, j;
    i = j = 0;
    while (s[i] != '\0') {
        if (s[i] == ' ') {
            int tabStop = determineSpaces(spacesPerTab, i);
            int wsItr = tabStop;
            int wsCount = 0;
            // Determine whether spaces reach next tabstop
            while (wsItr-- > 0) {
                if (s[i] == ' ') {
                    wsCount += 1;
                } else {
                    wsCount = 0;
                    break;
                }
                i++;
            }
            if (wsCount > 1 && wsCount == tabStop) {
                ts[j++] = '#';
            } else {
                ts[j++] = s[i++];
            }
        } else {
            ts[j++] = s[i];
            i++;
        }
    }
    ts[j] = '\0';
}