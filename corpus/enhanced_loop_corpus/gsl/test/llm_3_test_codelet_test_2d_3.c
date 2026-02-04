#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t N;
extern size_t tda;
extern size_t i;
extern size_t j;
extern double *data;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing via pointer arithmetic
    // Instead of using two-dimensional indexing directly, we use a base pointer per row and stride through columns
    double *base;
    size_t offset;
    for (i = 0; i < N; i++) {
        base = &data[i * tda];  // Base address of row i
        for (j = N; j < tda; j++) {
            offset = j;
            status |= (base[offset] != (12345. + (i * tda + j)));
        }
    }
}
