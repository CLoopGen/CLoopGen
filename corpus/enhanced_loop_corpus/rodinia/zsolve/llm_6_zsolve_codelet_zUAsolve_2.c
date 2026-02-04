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
extern complex *b_ve;
extern complex *out_ve;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    complex temp;
    for (i = 0; i < dim; i++) {
        temp = b_ve[i];
        if (!(temp.re == 0. && temp.im == 0.))
            break;
        out_ve[i].re = 0.;
        out_ve[i].im = 0.;
    }
}
