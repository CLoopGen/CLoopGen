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
    if (dim > 0) {
        for (i = 0; i < dim; i += 2) {
            y[i] = z[0 * dim + i];
            if (i + 1 < dim) {
                y[i + 1] = z[0 * dim + (i + 1)];
            }
        }
    }
}
