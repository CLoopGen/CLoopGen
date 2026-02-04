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
    for (u_int j = 0; j < dim; j++)
        for (i = j; i < dim; i++) {
            if (!((b_ve[i]).re == 0. && (b_ve[i]).im == 0.))
                break;
            else
                out_ve[i].re = out_ve[i].im = 0.;
            break;
        }
}
