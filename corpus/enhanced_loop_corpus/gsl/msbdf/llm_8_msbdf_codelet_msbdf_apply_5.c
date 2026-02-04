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
    for (i = 0; i < dim; i += 2) {
        if (i + 1 < dim) {
            z[1 * dim + i] *= h;
            z[1 * dim + i + 1] *= h;
        } else {
            z[1 * dim + i] *= h;
        }
    }
}
