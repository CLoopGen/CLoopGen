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
    u_int j;
    for (i = 0; i < dim; i++) {
        j = i + 1;
        if (j < dim && b_ent[j] != 0.)
            break;
        else
            out_ent[i] = 0.;
    }
}
