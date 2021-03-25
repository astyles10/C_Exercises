#include <stdio.h>

void expand (char s1[], char s2[]);

int main (void) {
    char string1[] = { 'z', '-', 'f', '-', '-', 'z', '0', '-', '9', '\n', '\0' };
    char string2[100];

    expand(string1, string2);
    printf("%s", string2);

    return 0;
}

void expand (char s1[], char s2[]) {
    int i, j, x, size;
    i = j = x = 0;

    for (x = 0; s1[x] != '\0'; x++)
        ;

    size = x - 1;
    unsigned char c;
    while ((c = s1[i]) != '\0') {
        if (c == '-') {
            if (i == 0) {
                s2[j++] = c;
                i++; continue;
            } else if (i == size) {
                s2[j++] = c;
                break;
            }

            unsigned char from = s1[i-1];
            unsigned char to = s1[i+1];

            if ((from < 'a' || from > 'z') && (from < '0' || from > '9')) {
                s2[j++] = c;
                i++;
                continue;
            } else if ((to < 'a' || to > 'z') && (to < '0' || to > '9')) {
                s2[j++] = c;
                i++;
                continue;
            }

            if (from <= to) {
                for (j, from; from <= to && from != to; j++, from++) {
                    s2[j] = from;
                }
            }
            i++;
        } else if (s1[i+1] == '-') {
            i++;
        } else {
            s2[j++] = c;
            i++;
        }
    }

    s2[j] = '\0';
}