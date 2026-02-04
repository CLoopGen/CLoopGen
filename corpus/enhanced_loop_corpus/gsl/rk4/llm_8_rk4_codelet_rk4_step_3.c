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
    size_t j;
    for (i = 0; i < dim; i += 2) {
        if (i + 1 < dim) {
            y[i] += h / 6. * k[i];
            y[i+1] += h / 6. * k[i+1];
        } else {
            y[i] += h / 6. * k[i];
        }
    }
}
