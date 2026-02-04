#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *dst;
extern int stride;
extern int bits;
extern int i;
extern int x;
extern int Ra;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access (remove striding, write to contiguous elements)
    for (i = 0; i < r; i++) {
        if (bits == 8) {
            ((uint8_t *)dst)[i] = Ra;
        } else {
            ((uint16_t *)dst)[i] = Ra;
        }
    }
}
