#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int linesize;
extern float o1;
extern float o2;
extern int v;
extern int step;
extern uint16_t *dst;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t local_accum = 0;
    for (y = 0; y < height; y += step) {
        uint16_t current = dst[0];
        local_accum += current; // Introduce loop-carried RAW dependency via local_accum
        dst[0] = (v - current) * o1 + current * o2 + local_accum; // Use accumulated value
        dst += (linesize / 2) * step;
    }
}
