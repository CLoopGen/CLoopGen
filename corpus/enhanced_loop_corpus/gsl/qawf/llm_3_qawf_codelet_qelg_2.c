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
    // Variant 2: Consecutive reverse-order access
    // Processes the array from high to low index to modify access pattern
    // while maintaining correctness via reverse traversal.
    for (i = n_final; i != (size_t)-1; i--) {
        epstab[i] = epstab[n_orig - n_final + i];
        // Break condition to prevent underflow (when i reaches 0, next i-- would wrap)
        if (i == 0) break;
    }
}
