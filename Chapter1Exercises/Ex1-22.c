#include <stdio.h>
#define MAX_SIZE 25

int spacesPerTab = 4;
int fGetLine(char s[], int lim);
void splitLine(char s[], int pos);

int main()
{
    int length;
    char line[MAX_SIZE];
    char solution[MAX_SIZE];

    while ((length = fGetLine(line, MAX_SIZE)) > 1)
    {
        extern int spacesPerTab;
        splitLine(line, 5);
    }

    printf("Terminating program\n");
    return 0;
}

int fGetLine(char s[], int lim)
{
    int c;
    int i;

    for (i = 0; i < lim - 1 && ((c = getchar()) != EOF) && c != '\n'; ++i)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i++] = c;
    }

    s[i] = '\0';
    return i;
}