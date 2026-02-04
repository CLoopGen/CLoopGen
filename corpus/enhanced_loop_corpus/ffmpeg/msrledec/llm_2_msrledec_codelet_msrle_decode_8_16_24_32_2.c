#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *output;
extern int p1;
extern int i;
extern uint8_t pix[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array indexing instead of pointer arithmetic
    for (i = 0; i < p1; i++) {
        output[3*i + 0] = pix[0];
        output[3*i + 1] = pix[1];
        output[3*i + 2] = pix[2];
    }
}
