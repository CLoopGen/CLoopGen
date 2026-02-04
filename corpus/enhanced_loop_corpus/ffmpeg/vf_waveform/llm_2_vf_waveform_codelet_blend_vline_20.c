#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int height;
extern int linesize;
extern float o1;
extern float o2;
extern int v;
extern int step;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Prefetching Pattern
    // Instead of strided access by linesize, we assume a transposed layout where data is stored consecutively.
    // We process 'step' elements at a time in a row-wise consecutive fashion.
    uint8_t *ptr = dst;
    for (y = 0; y < height; y += step) {
        ptr[0] = v * o1 + ptr[0] * o2;
        ptr += step; // Consecutive access instead of strided by linesize
    }
}
