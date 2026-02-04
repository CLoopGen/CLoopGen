#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *levels;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to maintain coverage
    for (int i = 0; i < 30; i += 2) {
        if (i / 2 < 15) {
            levels[i / 2] = -100.;
        }
    }
}
