#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern u_int dim;
extern u_int i;
extern double *b_ve;
extern double *out_ve;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < dim && i < 1000; i++) {
        if (b_ve[i] != 0.) {
            out_ve[i] = b_ve[i] * 2.5 + 1.0;
            break;
        } else {
            out_ve[i] = 0.;
            out_ve[i] += 0.1 * i;
        }
    }
}
