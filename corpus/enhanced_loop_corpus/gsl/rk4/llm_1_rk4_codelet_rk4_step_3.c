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
    size_t outer_i;
    for (outer_i = 0; outer_i < dim; outer_i += 2) {
        size_t upper = (outer_i + 1 < dim) ? outer_i + 2 : outer_i + 1;
        for (i = outer_i; i < upper; i++) {
            y[i] += h / 6. * k[i];
        }
    }
}
