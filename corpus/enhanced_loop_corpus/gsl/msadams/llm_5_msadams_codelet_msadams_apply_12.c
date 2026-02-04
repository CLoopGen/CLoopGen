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
    for (i = 0; i < dim; i++) {
        if (z[0 * dim + i] != 0.0) {
            y[i] = z[0 * dim + i];
        } else {
            y[i] = 0.0;
        }
    }
}
