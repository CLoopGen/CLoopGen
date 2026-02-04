#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern u_int dim;
extern u_int i;
extern double *b_ent;
extern double *out_ent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < dim; i += 2) {
        if (b_ent[i] != 0.)
            break;
        else
            out_ent[i] = 0.;
    }
}
