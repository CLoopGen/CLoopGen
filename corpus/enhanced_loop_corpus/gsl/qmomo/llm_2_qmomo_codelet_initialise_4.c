#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *rj;
extern double *rh;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling the loop to access adjacent elements
    for (i = 1; i < 25; i += 4) {
        if (i + 0 < 25) {
            rj[i] *= -1;
            rh[i] *= -1;
        }
        if (i + 2 < 25) {
            rj[i + 2] *= -1;
            rh[i + 2] *= -1;
        }
    }
}
