#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *restrict pixels;
extern int16_t *block;
extern int line_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolling
    uint8_t *p = pixels;
    int16_t *b = block;
    for (i = 0; i < 8; i++) {
        p[0] += b[0]; p[1] += b[1]; p[2] += b[2]; p[3] += b[3];
        p[4] += b[4]; p[5] += b[5]; p[6] += b[6]; p[7] += b[7];
        p += line_size;
        b += 8;
    }
}
