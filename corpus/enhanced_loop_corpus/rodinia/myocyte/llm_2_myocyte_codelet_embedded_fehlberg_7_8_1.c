#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *initvalu;
extern float *initvalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling by factor of 2
    // Process even indices first, then odd if needed, but keep within bounds
    int i;
    for (i = 0; i < 91; i += 2) {
        initvalu_temp[i] = initvalu[i];
    }
    for (i = 1; i < 91; i += 2) {
        initvalu_temp[i] = initvalu[i];
    }
}
