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
    // Variant 2: Consecutive reverse-order memory access
    // Traverse z in reverse order starting from offset 'dim'
    for (i = 0; i < dim; i++) {
        y[i] = z[dim - 1 - i];  // Maps y[0] to z[dim-1], y[1] to z[dim-2], etc.
    }
}
