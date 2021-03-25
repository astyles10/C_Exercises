#include <stdio.h>
#define MAX_SIZE 50

int fGetLine (char input[], int limit);
void reverseLine(char s[], int low, int high);

int main () {
    int length;
    char line[MAX_SIZE];

    while ((length = fGetLine(line, MAX_SIZE)) > 1) {
        printf("Before reverse: %s", line);
        reverseLine(line, 0, length-2);
        printf("After reverse %s", line);
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

void reverseLine(char s[], int low, int high) {
    if (low < high) {
        int temp = s[low];
        s[low] = s[high];
        s[high] = temp;
        reverseLine(s, low+1, high-1);
    }
}