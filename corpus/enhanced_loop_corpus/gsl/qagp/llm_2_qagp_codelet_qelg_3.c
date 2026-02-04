#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *epstab;
extern  size_t n_orig;
extern size_t n_final;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // Processes two elements per iteration, accessing elements in a strided pattern
    size_t j;
    for (j = 0; j <= n_final; j += 2) {
        size_t idx1 = j;
        size_t idx2 = j + 1;
        if (idx1 <= n_final) {
            epstab[idx1] = epstab[n_orig - n_final + idx1];
        }
        if (idx2 <= n_final) {
            epstab[idx2] = epstab[n_orig - n_final + idx2];
        }
    }
}
