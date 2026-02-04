#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int16_t *dst;
extern int16_t *b0;
extern int16_t *b1;
extern int16_t *b2;
extern int16_t *b3;
extern int16_t *b4;
extern int16_t *b5;
extern int16_t *b6;
extern int16_t *b7;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_i;
    int inner_i;
    int chunk = (width + 3) / 4; // Divide work into ~4 chunks
    for (outer_i = 0; outer_i < 4; outer_i++) {
        int start = outer_i * chunk;
        int end = start + chunk;
        if (start >= width) continue;
        if (end > width) end = width;
        for (inner_i = start; inner_i < end; inner_i++) {
            dst[inner_i] = ((unsigned int)dst[inner_i] + ((int)(-2 * (b0[inner_i] + (unsigned int)b7[inner_i]) + 10 * (b1[inner_i] + (unsigned int)b6[inner_i]) - 25 * (b2[inner_i] + (unsigned int)b5[inner_i]) + 81 * (b3[inner_i] + (unsigned int)b4[inner_i]) + 128) >> 8));
        }
    }
}
