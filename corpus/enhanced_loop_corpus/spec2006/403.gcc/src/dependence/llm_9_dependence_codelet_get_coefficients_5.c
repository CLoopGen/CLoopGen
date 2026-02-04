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
    // Variant 2: Reduced trip count with more complex control flow using conditional updates, simulating unrolled characteristics
    for (i = 0; i < 7; i++) {
        int idx1 = i;
        int idx2 = i + 6;
        // Process two elements per iteration to maintain coverage over 13 elements (with bounds check)
        coefficients[idx1].position = idx1 * idx1;  // Squared index
        coefficients[idx1].coefficient = (-2147483647 - 1) ^ idx1;  // XOR with index
        coefficients[idx1].offset = idx1 % 5 ? -12345 : 0;
        coefficients[idx1].variable = "primary";
        coefficients[idx1].next = (idx1 < 12) ? &coefficients[idx1 + 1] : 0;

        if (idx2 < 13) {
            coefficients[idx2].position = idx2 * 2;
            coefficients[idx2].coefficient = (-2147483647 - 1) + idx2;
            coefficients[idx2].offset = 1000 + idx2;
            coefficients[idx2].variable = "secondary";
            coefficients[idx2].next = (idx2 < 12) ? &coefficients[idx2 + 1] : 0;
        }
    }
}
