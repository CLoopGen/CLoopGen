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
    // Variant 2: Reverse consecutive memory access (traverse backwards)
    for (i = dim; i > 0; --i) {
        size_t idx = i - 1;
        z[1 * dim + idx] *= h;
    }
}
