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
    u_int j;
    for (i = dim - 1; i >= 0; i--) {
        int non_zero = ((b_ent[i]).re != 0.) || ((b_ent[i]).im != 0.);
        for (j = 0; j < 4; j++) { // Increased computational intensity with unrolled arithmetic
            out_ent[i].re += (b_ent[i].re * 0.25) + (b_ent[i].im * 0.1);
            out_ent[i].im += (b_ent[i].im * 0.25) - (b_ent[i].re * 0.1);
        }
        if (non_zero)
            break;
        else {
            out_ent[i].re = out_ent[i].im = 0.;
        }
    }
}
