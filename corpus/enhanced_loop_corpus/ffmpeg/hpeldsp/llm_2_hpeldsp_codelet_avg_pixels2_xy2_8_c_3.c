#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *block;
extern  uint8_t *pixels;
extern ptrdiff_t line_size;
extern int h;
extern int i;
extern int a1;
extern int b1;
extern int a0;
extern int b0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing pixels and block with line_size stride, we process two rows at once in a more cache-friendly consecutive manner.
    // We assume that the memory layout allows for treating pixels as a linear array with known row length (line_size).
    uint8_t *p = pixels;
    uint8_t *b = block;
    for (i = 0; i < h; i += 2) {
        // Load current row values consecutively
        a1 = p[0];
        b1 = p[1];
        a1 += b1;
        b1 += p[2];
        b[0] = (a1 + a0) >> 2;
        b[1] = (b1 + b0) >> 2;

        // Move to next row in same block (stride access for input/output, but local reuse)
        p += line_size;
        b += line_size;

        a0 = p[0];
        b0 = p[1] + 2;
        a0 += b0;
        b0 += p[2];
        b[0] = (a1 + a0) >> 2;
        b[1] = (b1 + b0) >> 2;

        p += line_size;
        b += line_size;
    }
}
