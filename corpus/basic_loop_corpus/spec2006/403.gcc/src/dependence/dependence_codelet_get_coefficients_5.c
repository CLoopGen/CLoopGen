#include <stdio.h>

#include <inttypes.h>

typedef struct subscript {
    int position;
    int coefficient;
    int offset;
    const char *variable;
    struct subscript *next;
} subscript;

extern subscript coefficients[13];
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 13; i++) {
    coefficients[i].position = 0;
    coefficients[i].coefficient = (-2147483647 - 1);
    coefficients[i].offset = (-2147483647 - 1);
    coefficients[i].variable = 0;
    coefficients[i].next = 0;
}

}
