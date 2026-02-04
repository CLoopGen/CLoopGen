#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int order;
extern float *out;
extern float *out2;
extern int i;
extern float buffer1[37];
extern float buffer2[37];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access pattern
    // Iterates from 'order' down to 0 to modify memory access direction
    // This changes temporal and spatial locality, potentially useful in pipelined systems
    for (i = order; i >= 0; i--) {
        out2[i] = out2[i] * 0.5625 + buffer1[i];
        out[i] = out2[i] + buffer2[i];
    }
}
