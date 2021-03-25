#include <stdio.h>

void a_strcat(char*, char*);
int a_strend (char*, char*);

int main (void) {
    char str1[100] = "abcd" ;
    char str2[100] = "defg";
    char str3[100] = "1234";
    a_strcat(str1, str2);
    printf("str1: %s\n", str1);
    int hasEnd = a_strend(str1, str2);
    printf("strend: %d\n", hasEnd);
    hasEnd = a_strend(str1, str3);
    printf("strend: %d\n", hasEnd);
    return 0;
}

void a_strcat (char* s, char* t) {
    while (*s++)
        ;
    *s--;
    while (*s++ = *t++);
        ;
}

int a_strend (char* s, char* t) {

    while (*s)
        s++;
    while (*t)
        t++;

    s--; t--;

    while (*t) {
        if (*s-- != *t--)
            return 0;
    }
    return 1;
}