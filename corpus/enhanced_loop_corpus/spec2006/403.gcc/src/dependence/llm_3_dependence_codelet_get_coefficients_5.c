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
    // Variant 2: Strided memory access with stride of 2, unrolled initialization pattern
    for (i = 0; i < 13; i += 2) {
        // First element in stride
        coefficients[i].position = 0;
        coefficients[i].coefficient = (-2147483647 - 1);
        coefficients[i].offset = (-2147483647 - 1);
        coefficients[i].variable = 0;
        coefficients[i].next = 0;

        // Second element in stride, if within bounds
        if (i + 1 < 13) {
            coefficients[i + 1].position = 0;
            coefficients[i + 1].coefficient = (-2147483647 - 1);
            coefficients[i + 1].offset = (-2147483647 - 1);
            coefficients[i + 1].variable = 0;
            coefficients[i + 1].next = 0;
        }
    }
}
