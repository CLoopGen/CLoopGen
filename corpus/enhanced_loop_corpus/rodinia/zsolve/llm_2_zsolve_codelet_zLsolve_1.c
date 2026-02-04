#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

extern u_int dim;
extern u_int i;
extern complex *b_ent;
extern complex *out_ent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < dim; i += 2) {
        if (!((b_ent[i]).re == 0. && (b_ent[i]).im == 0.))
            break;
        else {
            out_ent[i].re = out_ent[i].im = 0.;
            // Also handle the case where i+1 is within bounds
            if (i + 1 < dim) {
                out_ent[i + 1].re = out_ent[i + 1].im = 0.;
            }
        }
    }
    // Handle remaining element if dim is odd
    if (dim % 2 == 1 && i >= dim) {
        i = dim - 1;
        if ((b_ent[i]).re == 0. && (b_ent[i]).im == 0.) {
            out_ent[i].re = out_ent[i].im = 0.;
        }
    }
}
