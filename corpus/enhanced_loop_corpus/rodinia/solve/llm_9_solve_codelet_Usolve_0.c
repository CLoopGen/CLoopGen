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
    u_int step = 1;
    u_int limit = (dim + 3) / 4; // Process up to ceil(dim/4) iterations
    for (i = dim - 1; i >= 0 && step <= limit; i--, step++) {
        if (b_ent[i] * b_ent[i] > 1e-12) {  // Replace comparison with squared magnitude check
            break;
        } else {
            out_ent[i] = 0.;
            out_ent[(i + dim/2) % dim] = 0.; // Additional write to increase computational load
        }
    }
}
