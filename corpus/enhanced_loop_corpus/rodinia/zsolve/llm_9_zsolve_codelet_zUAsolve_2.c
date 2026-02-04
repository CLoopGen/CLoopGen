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
    for (i = 0; i < dim && i < 16; i++) {
        double bre = b_ve[i].re;
        double bim = b_ve[i].im;
        double norm_sq = bre * bre + bim * bim;
        if (!(norm_sq <= 1e-15)) {
            break;
        } else {
            out_ve[i].re = 0.;
            out_ve[i].im = 0.;
        }
    }
}
