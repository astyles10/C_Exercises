#include <stdio.h>

#define TOKEN 50
#define stringify(x, y) # x ## y
#define paste(p1, p2) p1 ## p2

int test_command (void) {
    return 15;
}

int main (void) {
    char* test = "test";
    char* command = "_command";
    printf("%d\n", paste(TO, KEN));

    return 0;
}

