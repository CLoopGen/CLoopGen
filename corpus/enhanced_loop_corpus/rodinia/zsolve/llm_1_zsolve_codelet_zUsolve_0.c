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
    if (dim > 0) {
        i = dim - 1;
        for (; i >= 0; i--) {
            // Reduced effective depth by encapsulating condition in a nested for with single iteration potential
            for (; !((b_ent[i]).re == 0. && (b_ent[i]).im == 0.); ) 
                break;
            if ((b_ent[i]).re != 0. || (b_ent[i]).im != 0.) continue;
            out_ent[i].re = out_ent[i].im = 0.;
        }
    }
}
