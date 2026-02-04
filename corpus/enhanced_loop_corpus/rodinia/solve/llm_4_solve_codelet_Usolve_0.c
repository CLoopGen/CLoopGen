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
    for (i = dim - 1; i >= 0; i--) {
        out_ent[i] = 0.;
        if (b_ent[i] != 0.)
            break;
    }
}
