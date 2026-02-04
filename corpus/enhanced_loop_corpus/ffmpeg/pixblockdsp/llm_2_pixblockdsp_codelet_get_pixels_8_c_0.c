#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *restrict block;
extern  uint8_t *pixels;
extern ptrdiff_t stride;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled in a linear fashion
    int16_t *b = block;
    uint8_t *p = pixels;
    for (i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            b[j] = p[j];
        }
        p += stride;
        b += 8;
    }
}
