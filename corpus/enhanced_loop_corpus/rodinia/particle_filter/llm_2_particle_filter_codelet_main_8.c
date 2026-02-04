#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Nparticles;
extern int *seed;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to process two elements per iteration
    int i;
    for (i = 0; i < Nparticles; i += 2) {
        if (i < Nparticles) seed[i] = i;
        if (i + 1 < Nparticles) seed[i + 1] = i + 1;
    }
}
