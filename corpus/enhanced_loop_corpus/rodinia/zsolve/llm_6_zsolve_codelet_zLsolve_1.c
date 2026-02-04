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
    complex temp_re, temp_im;
    for (i = 0; i < dim; i++) {
        temp_re = b_ent[i];
        temp_im = b_ent[i];
        if (!(temp_re.re == 0. && temp_re.im == 0.))
            break;
        else {
            out_ent[i].re = 0.;
            out_ent[i].im = 0.;
        }
    }
}
