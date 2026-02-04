#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t dim;
extern double y[];
extern double * z;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < dim; i++) {
        y[i] = z[i] + y[i - 1];
    }
    if (dim > 0) {
        y[0] = z[0];
    }
}
