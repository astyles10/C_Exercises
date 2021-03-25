#include <stdio.h>
#include <string.h>
#define MAXLINE 100

int fgetline(char *line, int max);
void appendLine (char *lines[], char *line);
void copy(char to[], char from[]);
int counter = 0;

int main (int argc, char *argv[]) {
    char line[MAXLINE];
    char *lines[MAXLINE];
    int len = 0;
    // Get lines from stdin
    while (len = fgetline(line, MAXLINE) > 1) {
        appendLine(lines, line);
    }
    while (--counter >= 0) {
        printf("%d: %p\n", counter, lines[counter]);
    }

    return 0;
}

int fgetline(char *line, int max) {
    int c, i;

    i = 0;
    while (--max > 0 && (c=getchar()) != EOF && c != '\n')
        line[i++] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}

void appendLine (char *lines[], char *line) {
    char tmpLine[MAXLINE];
    // Need to allocate memory for each char array
    copy(tmpLine, line);
    printf("Line: %p\n", tmpLine);
    lines[counter++] = tmpLine;
}

void copy(char to[], char from[]) {
    int i = 0;
    printf("Copy initialized.\nTo: %p\nFrom: %p\n", to, from);

    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}