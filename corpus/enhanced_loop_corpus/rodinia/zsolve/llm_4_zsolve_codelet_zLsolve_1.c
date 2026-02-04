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
for (i = 0; i < dim; i++) {
    double bre = b_ent[i].re;
    double bim = b_ent[i].im;
    if (bre != 0. || bim != 0.)
        break;
    out_ent[i].re = 0.;
    out_ent[i].im = 0.;
}
}
