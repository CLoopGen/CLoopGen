#include <stdio.h>
#include <inttypes.h>

typedef struct subscript {
    int position;
    int coefficient;
    int offset;
    const char *variable;
    struct subscript *next;
} subscript;

subscript coefficients[13];
int i;

void init_vars() {
    for (i = 0; i < 13; i++) {
        coefficients[i].position = 0;
        coefficients[i].coefficient = (-2147483647 - 1);
        coefficients[i].offset = (-2147483647 - 1);
        coefficients[i].variable = NULL;
        coefficients[i].next = NULL;
    }
}