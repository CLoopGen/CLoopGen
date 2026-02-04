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
    // Variant 1: Strided memory access with stride of 2
    // This processes elements in a non-consecutive, strided pattern.
    // We assume n_final is even for simplicity and full coverage.
    size_t stride = 2;
    for (i = 0; i <= n_final; i += stride) {
        if (n_orig - n_final + i < n_orig) {
            epstab[i] = epstab[n_orig - n_final + i];
        }
        // Handle odd index if within bounds
        if (i + 1 <= n_final && n_orig - n_final + i + 1 < n_orig) {
            epstab[i + 1] = epstab[n_orig - n_final + i + 1];
        }
    }
}
