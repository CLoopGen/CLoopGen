#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int16_t *b0;
extern int16_t *b1;
extern int16_t *b2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_i;
    int inner_i;
    int chunk_size = (width + 3) / 4; // Divide work into ~4 chunks
    for (outer_i = 0; outer_i < 4; outer_i++) {
        int start = outer_i * chunk_size;
        int end = start + chunk_size;
        if (start >= width) break;
        if (end > width) end = width;
        for (inner_i = start; inner_i < end; inner_i++) {
            b1[inner_i] = (b1[inner_i] + (unsigned int)((int)(b0[inner_i] + (unsigned int)(b2[inner_i]) + 1) >> 1));
        }
    }
}
