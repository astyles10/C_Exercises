#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#define MAXLINE 1000

int printError(char *err);
int fgetline(char *line, int max);
int appendLine(char *lines[], char *line);
void copy(char to[], char from[]);
int counter = 0;

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    char *lines[MAXLINE];
    int len = 0;
    int numLines = 0;
    char errString[MAXLINE] = "Invalid option: \'";

    if (argc >= 2)
    {
        int lim = argc - 1;

        // Get options, increment i for each option
        int i = 1;
        while (argv[i][0] == '-')
        {
            int opt = argv[i][1];
            int optItr = 2;
            switch (opt)
            {
            case 'n':
                // Check if anything follows -n
                if (strlen(argv[i]) < 3)
                {
                    strcat(errString, argv[i]);
                    strcat(errString, "\' - Number of lines required");
                    return printError(errString);
                }
                char *numPtr = &argv[i][optItr];

                // Check if following input is a number
                int x;
                for (x = 0; x < strlen(numPtr); x++)
                {
                    if (!isdigit(numPtr[x]))
                    {
                        strcat(errString, argv[i]);
                        strcat(errString, "\' - Invalid number of lines: ");
                        strcat(errString, numPtr);
                        return (printError(errString));
                    }
                }
                numLines = atoi(numPtr);
                break;
            default:
                strcat(errString, argv[i]);
                strcat(errString, "\'");
                return printError(errString);
                break;
            }
            i++;
        }

        while (i <= lim)
        {
            printf("Reading %s...\n", argv[i]);
            FILE *filename = fopen(argv[i++], "r");
            if (filename != NULL)
            {
                int numLines = atoi(argv[1]);
                int numFileLines = 0;

                while (fgets(line, MAXLINE, filename))
                    numFileLines++;
                numLines = numLines < numFileLines ? numLines : numFileLines;
                rewind(filename);
                while (fgets(line, MAXLINE, filename))
                {
                    if (numFileLines <= numLines)
                        printf("%s", line);
                    numFileLines--;
                }
            }
            else
            {
                printf("%s\n", strerror(errno));
            }
            printf("\n");
        }
    }
    else
    {
        printf("%s: Usage - tail <numlines> <options> <files>\n", argv[0]);
        return -1;
    }

    return 0;
}

int printError(char *err)
{
    printf("%s\n", err);
    return -1;
}

int printTail(char *fname)
{
}

int fgetline(char *line, int max)
{
    int c, i;

    i = 0;
    while (--max > 0 && (c = getchar()) != EOF && c != '\n')
        line[i++] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}

int appendLine(char *lines[], char *line)
{
    char *tmpLine = malloc(MAXLINE);
    copy(tmpLine, line);
    lines[counter++] = tmpLine;

    return 1;
}

void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}