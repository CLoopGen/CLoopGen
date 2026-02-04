#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;
extern uint8_t invert;
extern uint8_t *planep;
extern int width;
extern int height;
extern int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Modified memory access pattern using consecutive pointer arithmetic
    // Instead of indexing with stride, we pre-calculate the base pointers for current and previous row
    // to enable more sequential access patterns in inner loop.

    uint8_t *prev_row = planep;
    uint8_t *curr_row = planep + stride;

    for (y = 1; y < height; y++) {
        curr_row[0] ^= prev_row[0];
        for (x = 1; x < width; x++) {
            if (curr_row[x - 1] != prev_row[x])
                curr_row[x] ^= invert;
            else
                curr_row[x] ^= curr_row[x - 1];
        }
        prev_row += stride;
        curr_row += stride;
    }
}
