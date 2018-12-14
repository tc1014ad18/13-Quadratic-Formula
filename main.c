#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

bool GetValueOf(char *varName, double *variable);

int main() {
    double a;
    double b;
    double c;
    double discriminant;

    printf("Hello, matey!  Lemme help you with that Quadratic expression! Lemme see...\n");

    if (!GetValueOf("A", &a)) {
        printf("Not a valid value.  Can't work with that mate.  See you around.\n");
        return 0;
    }
    if (a == 0) {
        printf("If A is 0, then this is not a Quadratic expression.  See you around, mate!\n");
        return 0;
    }

    if (!GetValueOf("B", &b)) {
        printf("Not a valid value.  Can't work with that mate.  See you around.\n");
        return 0;
    }

    if (!GetValueOf("C", &c)) {
        printf("Not a valid value.  Can't work with that mate.  See you around.\n");
        return 0;
    }

    discriminant = pow(b, 2) - 4 * a * c;

    if (discriminant < 0) {
        printf("Both solutions are imaginary.  I cannot give you an answer.");
    } else {
        if (discriminant == 0) {
            double x = -b / (2 * a);
            printf("There is only one solution to your expression, and that is x = %lf\n", x);
        } else {
            double x1 = (-b + sqrt(discriminant)) / (2 * a);
            double x2 = (-b - sqrt(discriminant)) / (2 * a);
            printf("There are two solutions to your expression:\n");
            printf("x1 = %lf\n", x1);
            printf("x2 = %lf\n", x2);
        }
    }

    printf("See you around, mate!\n");

    return 0;
}

bool GetValueOf(char *varName, double *variable) {
    char *trash;
    char number[10];
    printf("Enter the value of %s: ", varName);
    fgets(number, sizeof(number), stdin);
    *variable = strtod(number, &trash);
    return strlen(number) != strlen(trash);
}