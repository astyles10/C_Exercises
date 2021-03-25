#include <stdio.h>
#define MAXLINE 50

const char escapeSequences[] = {
    '\a', '\b', '\e', '\f',
    '\n', '\r', '\t', '\v',
    '\\', '\'', '\"', '\?'
};

const char escapeCharMap[] = {
    'a', 'b', 'e', 'f',
    'n', 'r', 't', 'v',
    '\\', '\'', '\"', '\?'
};

int exGetLine(char s[], int lim);
void copy (char s[], char t[]);
int escape (char c, char t[], int pos);

int main (void) {
    int len;
    char line[MAXLINE];
    char escapedString[MAXLINE];
 
    while ((len = exGetLine(line, MAXLINE)) > 1) {
        copy(line, escapedString);
        printf("%s\n", escapedString);
    }

    printf("%s\n", escapedString);
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

void copy (char s[], char t[]) {
    int i, j;
    i = j = 0;

    while (s[i] != '\0') {
        if (s[i] <= 92) {
            j = escape(s[i], t, j);
            i++; j++;
        } else {
            t[j++] = s[i++];
        }
    }
    t[j] = '\0';
}

int escape (char c, char t[], int pos) {
    int i = 0;
    while (escapeSequences[i] != '\0') {
        if (escapeSequences[i] == c) {
            t[pos++] = '\\';
            t[pos] = escapeCharMap[i];
            break;
        }
        i++;
    }
    return pos;
}

int unescape (char c, char t[], int pos) {
    char f = 's';
}