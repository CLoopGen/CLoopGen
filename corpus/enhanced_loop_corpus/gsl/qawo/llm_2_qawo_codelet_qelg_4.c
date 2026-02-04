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
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to process two elements per iteration
    size_t step = 2;
    size_t limit = n_final - (n_final % step); // Make sure we don't overflow
    for (i = 0; i <= limit; i += step) {
        epstab[i] = epstab[n_orig - n_final + i];
        if (i + 1 <= n_final) {
            epstab[i + 1] = epstab[n_orig - n_final + i + 1];
        }
    }
    // Handle any remaining element if n_final is odd
    if (i <= n_final) {
        epstab[i] = epstab[n_orig - n_final + i];
    }
}
