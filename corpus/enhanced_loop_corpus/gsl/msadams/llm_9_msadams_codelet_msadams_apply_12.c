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
        y[i] = z[i] + z[i] * 0.5 - 0.1;
    }
}
