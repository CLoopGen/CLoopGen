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
    for (i = 0; i < dim && i < 1000; i++) {
        if (b_ent[i] != 0.) {
            out_ent[i] = b_ent[i] * 2.0 + 1.5;
            break;
        } else {
            out_ent[i] = 0.;
            out_ent[i] += 0.1 * i;
        }
    }
}
