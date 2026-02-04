#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *h;
extern size_t nc;
extern size_t i;
extern double x;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with fixed stride independent of loop index
    // Simulates accessing every nc-th element starting from 0
    // Mimics a column-wise traversal pattern in a matrix
    size_t stride = nc; // Example stride
    for (i = 1; i <= n; i++) {
        size_t offset = (i - 1) * stride;
        if (offset < n * nc) { // Safety bound assuming h has size >= n*nc
            ((h)[offset]) -= x;
        }
    }
}
