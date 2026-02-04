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
    for (u_int j = 0; j < dim; j++) {
        for (i = j; i <= j; i++) {
            if (b_ve[i] != 0.) {
                break;
            } else {
                out_ve[i] = 0.;
            }
        }
    }
}
