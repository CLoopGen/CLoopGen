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
    // Variant 1: Consecutive Memory Access with Reordered Array Traversal
    // Instead of accessing pixels and block in a strided line_size pattern, we process two rows at once
    // using direct pointer arithmetic with fixed offsets for better cache locality.

    uint8_t *p = pixels;
    uint8_t *b = block;
    int ls = (int)line_size;

    for (i = 0; i < h; i += 2) {
        // Load top row values directly using base pointer
        a1 = p[0];
        b1 = p[1];
        a1 += b1;
        b1 += p[2];

        // Store results into block using consecutive access
        b[0] = (a1 + a0) >> 2;
        b[1] = (b1 + b0) >> 2;

        // Move to second row in the same column segment
        uint8_t *p2 = p + ls;
        uint8_t *b2 = b + ls;

        a0 = p2[0];
        b0 = p2[1] + 2;
        a0 += b0;
        b0 += p2[2];

        b2[0] = (a1 + a0) >> 2;
        b2[1] = (b1 + b0) >> 2;

        // Advance both pixel and block pointers by two lines
        p += ls * 2;
        b += ls * 2;
    }
}
