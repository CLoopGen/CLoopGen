#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern u_int dim;
extern int i;
extern double *b_ent;
extern double *out_ent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_out = 0.0;
    for (i = dim - 1; i >= 0; i--) {
        out_ent[i] = 0.; // Remove conditional, always assign (WAW dependency across iterations)
        if (b_ent[i] != 0.) {
            // Introduce RAW dependency: current use of b_ent[i] depends on prior out_ent write
            out_ent[i] += b_ent[i] * prev_out; // Loop-carried dependency via prev_out
            break;
        }
        prev_out = out_ent[i]; // Carry value forward, creating loop-carried dependency
    }
}
