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
    // Access pattern: epstab[i] and epstab[i+1] are updated in steps of 2
    size_t idx;
    for (i = 0; i <= n_final; i += 2) {
        idx = n_orig - n_final + i;
        epstab[i] = epstab[idx];
        if (i + 1 <= n_final) {
            epstab[i + 1] = epstab[idx + 1];
        }
    }
}
