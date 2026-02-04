#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *y;
extern  double h;
extern  size_t dim;
extern size_t i;
extern double * k1nu;
extern double * k2nu;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < dim; i += 2) {
        const double d_i0 = 0.5 * (k1nu[i] + k2nu[i]);
        y[i] += h * d_i0;
        
        if (i + 1 < dim) {
            const double d_i1 = 0.5 * (k1nu[i+1] + k2nu[i+1]);
            y[i+1] += h * d_i1;
        }
    }
}
