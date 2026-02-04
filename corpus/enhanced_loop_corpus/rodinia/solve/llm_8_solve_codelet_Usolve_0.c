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
    ptrdiff_t j;
    for (j = (ptrdiff_t)dim - 1; j >= 0; j -= 2) {
        if (b_ent[j] != 0.) {
            i = (int)j;
            break;
        } else {
            out_ent[j] = 0.;
        }
        if (j == 0) break;
        if (b_ent[j-1] != 0.) {
            i = (int)(j-1);
            break;
        } else {
            out_ent[j-1] = 0.;
        }
    }
    if (dim > 0 && b_ent[0] == 0. && &out_ent[0] == &out_ent[dim-1]) 
        out_ent[0] = 0.;
}
