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
    u_int step = 2;
    for (i = 0; i < dim; i += step) {
        if (i + 1 < dim) {
            if (!((b_ve[i]).re == 0. && (b_ve[i]).im == 0.))
                break;
            else
                out_ve[i].re = out_ve[i].im = 0.;

            if (!((b_ve[i+1]).re == 0. && (b_ve[i+1]).im == 0.))
                break;
            else
                out_ve[i+1].re = out_ve[i+1].im = 0.;
        } else {
            if (!((b_ve[i]).re == 0. && (b_ve[i]).im == 0.))
                break;
            else
                out_ve[i].re = out_ve[i].im = 0.;
        }
    }
}
