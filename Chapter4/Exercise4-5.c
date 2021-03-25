#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUMBER '0'
#define PRINT 'P'
#define DUPLICATE 'D'
#define SWAP 'S'
#define CLEAR 'C'
#define BUFSIZE 100

double stack[BUFSIZE];
int stackPtr = 0;

void push(double);
double pop(void);
int getop (char[]);
int getch(void);
void ungetch(int);

int determineCommand(char []);
double getStackTop(void);
void duplicateTop(void);
void swapTop(void);
void clearStack(void);

int main (void) {
    int type;
    double op1, op2;
    char s[BUFSIZE];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case PRINT:
                printf("Get stack top %g\n", getStackTop());
                break;
            case DUPLICATE:
                duplicateTop();
                break;
            case SWAP:
                swapTop();
                break;
            case CLEAR:
                clearStack();
                break;
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                op1 = pop();
                push(op1 - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("Error: cannot divide by zero\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push((int)pop() % (int)op2);
                else
                    printf("Error: cannot divide by zero\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("Error: unknown command %s\n", s);
        }
    }
    return 0;
}

void push(double value) {
    if (stackPtr < BUFSIZE) {
        stack[stackPtr++] = value;
    } else {
        printf("Error: Stack full, cannot push %g\n", value);
    }
}

double pop(void) {
    if (stackPtr > 0) {
        return stack[--stackPtr];
    } else {
        printf("Error: stack empty\n");
        return 0.0;
    }
}

int getop (char s[]) {
    int i, c, sign;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    i = 0;

    if (c == '-') {
        char tempC = c;
        c = getch();
        if (!isdigit(c)) {
            if (c != EOF)
                ungetch(c);
            return tempC;
        }
        s[++i] = c;
    } else if (!isdigit(c) && c != '.') {
        return c; // Run DetermineCommand here
    }
    
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int determineCommand(char s[]) {

}

double getStackTop(void) {
    int tempPtr = stackPtr - 1;
    if (tempPtr >= 0) {
        return stack[tempPtr];
    }
    else {
        printf("getStackTop Error: stack empty\n");
        return 0.0;
    }
}

void duplicateTop (void) {
    push(getStackTop());
}

void swapTop (void) {
    double op1, op2;
    op2 = pop();
    op1 = pop();
    push(op2);
    push(op1);
}

void clearStack (void) {
    for (int i = 0; i < stackPtr; i++) {
        stack[i] = '\0';
    }
    stackPtr = 0;
}