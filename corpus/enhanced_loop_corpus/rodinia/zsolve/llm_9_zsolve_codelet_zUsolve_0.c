#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

extern u_int dim;
extern int i;
extern complex *b_ent;
extern complex *out_ent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    u_int step = 2;
    u_int start = (dim % 2 == 0) ? dim - 2 : dim - 1;
    for (i = start; i >= 0; i -= step) {
        if (i < dim && !((b_ent[i]).re == 0. && (b_ent[i]).im == 0.)) {
            break;
        } else {
            out_ent[i].re = out_ent[i].im = 0.;
        }
        if (i < step) break;
    }
    // Handle remaining element if skipped due to step size
    if (dim > 0 && start == dim - 2)
        if (!((b_ent[0]).re == 0. && (b_ent[0]).im == 0.))
            out_ent[0] = b_ent[0]; // Different behavior on last element
}
