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
    size_t j, i;
    for (j = 0; j < 1; j++) {
        for (i = 0; i < dim; i++) {
            y[i] += h / 6. * k[i];
        }
    }
}
