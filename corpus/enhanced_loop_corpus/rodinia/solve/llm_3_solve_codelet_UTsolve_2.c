#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern u_int dim;
extern u_int i;
extern double *b_ve;
extern double *out_ve;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access from end to start
    for (i = dim - 1; i >= 0; i--) {
        if (b_ve[i] != 0.) {
            break;
        } else {
            out_ve[i] = 0.;
        }
    }
}
