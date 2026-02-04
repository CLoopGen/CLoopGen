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
    for (i = 0; i < dim; i += 2) {
        if (i + 1 < dim) {
            if (b_ent[i] != 0.) {
                out_ent[i] = b_ent[i] * b_ent[i];
                out_ent[i+1] = 0.;
                break;
            } else if (b_ent[i+1] != 0.) {
                out_ent[i] = 0.;
                out_ent[i+1] = b_ent[i+1] * b_ent[i+1];
                break;
            } else {
                out_ent[i] = 0.;
                out_ent[i+1] = 0.;
            }
        } else {
            if (b_ent[i] != 0.)
                out_ent[i] = b_ent[i] * b_ent[i];
            else
                out_ent[i] = 0.;
        }
    }
}
