#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t dim;
extern double * z;
extern double * l;
extern size_t ord;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Change memory access pattern to consecutive (cache-friendly) by reordering computation
    // We transpose the access to z so that we traverse j (column index) in the outer loop
    // This makes accesses to z[*][j] consecutive in memory when dim is the stride
    for (j = 0; j < dim; j++)
        for (i = 2; i < ord; i++) {
            z[i * dim + j] += l[i] * z[ord * dim + j];
        }
}
