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
    for (i = 0; i < dim; i += 2) {
        if (i < dim && !((b_ve[i]).re == 0. && (b_ve[i]).im == 0.))
            break;
        else if (i < dim)
            out_ve[i].re = out_ve[i].im = 0.;

        if ((i + 1) < dim && !((b_ve[i + 1]).re == 0. && (b_ve[i + 1]).im == 0.))
            break;
        else if ((i + 1) < dim)
            out_ve[i + 1].re = out_ve[i + 1].im = 0.;
    }
}
