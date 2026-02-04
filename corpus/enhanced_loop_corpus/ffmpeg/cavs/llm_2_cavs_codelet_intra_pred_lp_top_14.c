#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *d;
extern uint8_t *top;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing base pointers and accessing d in row-major order
    uint8_t *d_row = d;
    for (y = 0; y < 8; y++) {
        uint8_t *top_offset = top;
        for (x = 0; x < 8; x++) {
            d_row[x] = ((top_offset[x] + 2 * top_offset[x + 1] + top_offset[x + 2] + 2) >> 2);
        }
        d_row += stride;
    }
}
