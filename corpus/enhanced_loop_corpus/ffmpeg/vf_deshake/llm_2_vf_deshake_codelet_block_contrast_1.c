#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int x;
extern int y;
extern int stride;
extern int blocksize;
extern int highest;
extern int lowest;
extern int i;
extern int j;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (flatten and traverse in row-major order)
    uint8_t *base = src + y * stride + x;
    int total_elements = (blocksize * 2 + 1) * 16;
    for (i = 0; i < total_elements; i++) {
        uint8_t val = base[i];
        if (val < lowest)
            lowest = val;
        else if (val > highest)
            highest = val;
    }
}
