#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *is;
extern double *dst;
extern int j;
extern double *interpolated;
extern int *_usr_index;
extern int nb_errors;
extern double *enabled;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing index[j] in natural order, traverse with a stride of 2
    // and handle remaining elements with a second loop for completeness.
    int stride = 2;
    int remainder = nb_errors % stride;

    // First pass: strided access (even indices)
    for (j = 0; j < nb_errors - remainder; j += stride) {
        if (enabled[index[j]]) {
            dst[index[j]] = interpolated[j];
            is[index[j]] = 1;
        }
    }

    // Second pass: handle leftover elements sequentially
    for (j = nb_errors - remainder; j < nb_errors; j++) {
        if (enabled[index[j]]) {
            dst[index[j]] = interpolated[j];
            is[index[j]] = 1;
        }
    }
}
