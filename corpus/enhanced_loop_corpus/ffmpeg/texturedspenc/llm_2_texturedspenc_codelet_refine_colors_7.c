#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *block;
extern ptrdiff_t stride;
extern int x;
extern int y;
extern int r;
extern int g;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (reorder indexing to access memory sequentially)
    uint8_t *p = block;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            int offset = y * stride + x * 4;
            r += p[offset + 0];
            g += p[offset + 1];
            b += p[offset + 2];
        }
    }
}
