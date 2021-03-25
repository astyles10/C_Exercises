#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]);

int main (void) {
    char s[] = "123.45e-6";
    double val = atof(s);
    printf("Converted value: %f\n", val);
    return 0;
}

double atof(char s[]) {
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10 * val + (s[i] - '0');
        power *= 10.0;
    }

    double convertedValue = sign * val / power;

    if (s[i] == 'e' || s[i] == 'E') {
        printf("Found %c\n", s[i]);
        int exponentSign = s[i+1];
        printf("Exponent sign: %c\n", s[i+1]);
        double exponent;
        i += 2;
        for (exponent = 0.0; isdigit(s[i]); i++)
            exponent = 10 * exponent + (s[i] - '0');

        printf("Exponent: %f\n", exponent);
        if (exponentSign == '+') {
            convertedValue = convertedValue * (pow(10, exponent));
        } else if (exponentSign == '-') {
            convertedValue = convertedValue / (pow(10, exponent));
        } else {
            printf("E was not followed with a valid sign, returning base float number\n");
        }
    }

    return convertedValue;
}