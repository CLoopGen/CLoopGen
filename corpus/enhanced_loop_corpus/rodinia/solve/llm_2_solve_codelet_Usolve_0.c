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
    // Variant 1: Strided memory access (stride of 2), traversing backwards with step size 2
    // Ensures alignment and handles odd dim by adjusting starting point if needed
    int start = (dim % 2 == 0) ? dim - 2 : dim - 1;
    for (i = start; i >= 0; i -= 2) {
        if (b_ent[i] != 0.)
            break;
        else
            out_ent[i] = 0.;
    }
    // Handle remaining element at index 0 if dim is odd and not covered
    if (dim > 0 && dim % 2 == 1 && b_ent[0] == 0.)
        out_ent[0] = 0.;
}
