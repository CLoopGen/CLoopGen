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
    double prev = 1.0;
    for (i = 0; i < dim; i++) {
        double current = z[1 * dim + i];
        z[1 * dim + i] = current * h + prev;
        prev = current;
    }
}
