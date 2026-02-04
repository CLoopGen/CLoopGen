#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dx;
extern int w;
extern unsigned int asrc;
extern unsigned int tau;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access (assuming dx == 1 for consecutive)
    // We remove pointer arithmetic stride and access dst as a flat array
    uint8_t *base_dst = dst;
    for (x = 0; x < w; x++) {
        base_dst[x] = (base_dst[x] * tau + asrc) >> 24;
    }
}
