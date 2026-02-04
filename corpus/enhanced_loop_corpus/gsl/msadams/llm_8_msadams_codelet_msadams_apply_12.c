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
    for (i = 0; i < dim; i += 2) {
        if (i + 1 < dim) {
            y[i]     = z[0 * dim + i];
            y[i + 1] = z[0 * dim + i + 1];
        } else {
            y[i] = z[0 * dim + i];
        }
    }
}
