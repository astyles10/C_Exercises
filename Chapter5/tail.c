#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <limits.h>
#define MAXLINE 1000
#define MIN_ARGS 2
#define FAIL -1

int printError(char *, ...);
int printTail(char *fname, int numLines);
int parseOptions(char *argv[], int argc, int *argItr, int *numLines);
int parseNumLines(char *arg);

int main(int argc, char *argv[])
{
    int numLines = 5;
    int isSuccess = 0;

    if (argc >= MIN_ARGS)
    {
        int argItr = 1;
        isSuccess = parseOptions(argv, argc, &argItr, &numLines);
        if (isSuccess == FAIL)
            return isSuccess;

        int numFiles = argc - 1;

        while (argItr <= numFiles)
        {
            isSuccess = printTail(argv[argItr++], numLines);
            printf("\n");
        }
    }
    else
        return printError("Usage - tail <numlines> <options> <files>\n", NULL);

    return isSuccess;
}

int printError(char * errs, ...)
{
    va_list pvlist;
    va_start(pvlist, errs);
    char errStr[MAXLINE] = "tail: ";
    char *tmp = errs;

    do {
        if (tmp != NULL)
            strcat(errStr, tmp);
        tmp = va_arg(pvlist, char*);
    } while (tmp != NULL);

    va_end(pvlist);
    printf("%s\n", errStr);

    return FAIL;
}

int printTail(char *fname, int numLines)
{
    printf("Reading %s...\n", fname);
    FILE *filename = fopen(fname, "r");
    if (filename != NULL)
    {
        char line[MAXLINE];
        int numFileLines = 0;

        while (fgets(line, MAXLINE, filename))
            numFileLines++;

        int tmpNumLines = numLines < numFileLines ? numLines : numFileLines;
        rewind(filename);
        while (fgets(line, MAXLINE, filename))
        {
            if (numFileLines <= tmpNumLines)
                printf("%s", line);
            numFileLines--;
        }
    }
    else
    {
        return printError("error: ", strerror(errno), NULL);
    }
}

int parseOptions(char *argv[], int argc, int *argItr, int *numLines)
{
    while (argv[*argItr][0] == '-')
    {
        char *arg = argv[*argItr];
        int opt = arg[1];

        switch (opt)
        {
        case 'n':
            if (strlen(arg) < 3) {
                (*argItr)++;
                if (*argItr == (argc - 1))
                {
                    printf("is it this one?\n");
                    return printError("Usage - tail <numlines> <options> <files>\n", NULL);
                }
                strcat(arg, argv[*argItr]);
            }
            *numLines = parseNumLines(arg);

            if (*numLines < 0)
                return *numLines;
            break;
        default:
            return printError("Invalid option: \'", arg, "\'", NULL);
            break;
        }
        (*argItr)++;
        if (*argItr == argc)
            return printError("Usage - tail <numlines> <options> <files>\n", NULL);
    }
    return 1;
}

// Parse int value following -n
int parseNumLines(char* arg)
{
    unsigned long long int numLines = 0;
    const int nOptLines = 2;

    char *numPtr = &arg[nOptLines];

    // Check if following input is a number
    int x;
    for (x = 0; x < strlen(numPtr); x++)
        if (!isdigit(numPtr[x]))
            return printError("Invalid number of lines: ", numPtr, NULL);

    numLines = atoll(numPtr);
    if (!(numLines <= INT_MAX))
        return printError("Too many lines: ", numPtr, NULL);

    return (int)numLines;
}
