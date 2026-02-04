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
    double sum_re = 0.0, sum_im = 0.0;
    for (i = dim - 1; i >= 0; i--) {
        sum_re += b_ent[i].re;
        sum_im += b_ent[i].im;
        if (!(b_ent[i].re == 0. && b_ent[i].im == 0.)) {
            break;
        } else {
            out_ent[i].re = sum_re;
            out_ent[i].im = sum_im;
        }
    }
}
