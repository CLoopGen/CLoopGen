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
for (i = dim - 1; i >= 0; i--) {
    if ((b_ent[i]).re != 0. || (b_ent[i]).im != 0.)
        break;
    out_ent[i].re = 0.;
    out_ent[i].im = 0.;
}
}
