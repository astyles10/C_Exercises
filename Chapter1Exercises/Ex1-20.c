#include <stdio.h>
#define MAX_SIZE 25

int spacesPerTab = 4;
void detab(char s[], char s2[], int spaces);
int fGetLine(char s[], int lim);

int main () {
    int length;
    char line[MAX_SIZE];
    char solution[MAX_SIZE];

    while ((length = fGetLine(line, MAX_SIZE)) > 1) {
        extern int spacesPerTab;
        detab(line, solution, spacesPerTab);
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

void detab(char s[], char ts[], int spacesPerTab) {
    char c;
    int i, j;
    i = j = 0;
    while (s[i] != '\0' && j < MAX_SIZE - 1) {
        if (s[i] == '\t') {
            int numSpaces = determineSpaces(spacesPerTab, j);
            while (numSpaces-- > 0) {
                if (j >= MAX_SIZE) {
                    break;
                }
                ts[j++] = '-';
            }
            i++;
        } else {
            ts[j++] = s[i];
            i++;
        }
    }
    ts[j] = '\0';
}