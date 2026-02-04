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
    u_int step = 2;
    for (i = 0; i < dim; i += step) {
        if (i + 1 < dim) {
            // Process two elements per iteration to increase computational intensity
            int cond1 = !((b_ent[i]).re == 0. && (b_ent[i]).im == 0.);
            int cond2 = !((b_ent[i+1]).re == 0. && (b_ent[i+1]).im == 0.);
            if (cond1)
                break;
            else {
                out_ent[i].re = out_ent[i].im = 0.;
                if (!cond2)
                    out_ent[i+1].re = out_ent[i+1].im = 0.;
                else
                    break;
            }
        } else {
            // Handle last element if dim is odd
            if (!((b_ent[i]).re == 0. && (b_ent[i]).im == 0.))
                break;
            else
                out_ent[i].re = out_ent[i].im = 0.;
        }
    }
}
