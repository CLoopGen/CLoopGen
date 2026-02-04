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
    for (i = 0; i < dim; i += 2) {
        if (i + 1 < dim) {
            if (b_ve[i] != 0. || b_ve[i+1] != 0.) {
                out_ve[i] = b_ve[i] * b_ve[i];
                out_ve[i+1] = b_ve[i+1] * b_ve[i+1];
                break;
            } else {
                out_ve[i] = 0.;
                out_ve[i+1] = 0.;
            }
        } else {
            if (b_ve[i] != 0.) {
                out_ve[i] = b_ve[i] * b_ve[i];
                break;
            } else {
                out_ve[i] = 0.;
            }
        }
    }
}
