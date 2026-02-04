#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern ptrdiff_t pitch;
extern int blk_size;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic with pre-computed base pointers
    int16_t *base = out + pitch;
    for (y = 1; y < blk_size; y++, base += pitch) {
        int16_t *row = base;
        for (x = 0; x < blk_size; x++) {
            row[x] = 0;
        }
    }
}
