#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *b0;
extern int32_t *b1;
extern int32_t *b2;
extern int32_t *b3;
extern int32_t *b4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    // This variant traverses the arrays from the last element to the first
    for (i = width - 1; i >= 0; i--) {
        b2[i] = (int)(((unsigned int)(b2[i]) - ((int)(9U * b1[i] + 9U * b3[i] - b4[i] - b0[i] + 16) >> 5)));
    }
}
