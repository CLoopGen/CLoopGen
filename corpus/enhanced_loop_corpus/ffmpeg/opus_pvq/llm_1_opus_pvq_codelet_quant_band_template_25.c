#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *X;
extern float *lowband_out;
extern int i;
extern uint32_t N0;
extern float n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t outer_i;
    uint32_t block_size = 16;
    for (outer_i = 0; outer_i < N0; outer_i += block_size) {
        for (i = outer_i; i < outer_i + block_size && i < N0; i++)
            lowband_out[i] = n * X[i];
    }
}
