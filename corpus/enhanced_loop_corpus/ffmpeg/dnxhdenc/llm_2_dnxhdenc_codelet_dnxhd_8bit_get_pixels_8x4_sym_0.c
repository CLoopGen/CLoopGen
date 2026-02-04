#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *restrict block;
extern  uint8_t *pixels;
extern ptrdiff_t line_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolling
    int16_t *b = block;
    uint8_t *p = pixels;
    for (i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            b[j] = p[j];
        }
        p += line_size;
        b += 8;
    }
}
