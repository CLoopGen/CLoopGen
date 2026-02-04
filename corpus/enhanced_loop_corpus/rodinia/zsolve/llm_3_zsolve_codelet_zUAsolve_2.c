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
    // Variant 2: Reverse consecutive memory access
    for (i = dim; i > 0; --i) {
        u_int idx = i - 1; // Reverse index to traverse from end to start
        if (!((b_ve[idx]).re == 0. && (b_ve[idx]).im == 0.))
            break;
        else
            out_ve[idx].re = out_ve[idx].im = 0.;
    }
}
