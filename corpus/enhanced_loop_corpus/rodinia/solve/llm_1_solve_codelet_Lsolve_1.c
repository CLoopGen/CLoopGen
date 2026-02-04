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
    u_int outer_i;
    u_int step = 1;
    for (outer_i = 0; outer_i < dim; outer_i += step) {
        i = outer_i;  // Maintain original variable usage
        if (b_ent[i] != 0.)
            break;
        else
            out_ent[i] = 0.;
    }
}
