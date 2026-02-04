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
    double prev_out = 0.0;
    for (i = 0; i < dim; i++) {
        if (b_ve[i] != 0.)
            break;
        else {
            out_ve[i] = prev_out; // Create RAW dependency: current write depends on previous value read
            prev_out = out_ve[i] + 1.0; // Introduce artificial loop-carried flow dependency via prev_out
        }
    }
}
