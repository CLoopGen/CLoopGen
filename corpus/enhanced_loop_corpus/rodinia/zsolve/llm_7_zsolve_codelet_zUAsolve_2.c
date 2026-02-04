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
    double zero_val = 0.0;
    for (i = 0; i < dim; i++) {
        out_ve[i].re = zero_val;
        out_ve[i].im = zero_val;
        if (!((b_ve[i]).re == zero_val && (b_ve[i]).im == zero_val))
            break;
    }
}
