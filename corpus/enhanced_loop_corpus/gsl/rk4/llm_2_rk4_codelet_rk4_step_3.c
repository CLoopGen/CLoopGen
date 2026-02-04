#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *y;
extern  double h;
extern  size_t dim;
extern double *k;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    size_t stride = 2;
    for (i = 0; i < dim; i += stride) {
        y[i] += h / 6. * k[i];
        if (i + 1 < dim) {
            y[i + 1] += h / 6. * k[i + 1];
        }
    }
}
