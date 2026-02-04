#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t dim;
extern double h;
extern double * z;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (dim == 0) return;
    for (i = 0; i < dim; i++) {
        z[1 * dim + i] *= h;
    }
}
