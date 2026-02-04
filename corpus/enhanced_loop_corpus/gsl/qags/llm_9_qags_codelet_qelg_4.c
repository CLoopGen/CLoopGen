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
    size_t trip_count = (n_final + 1) * 2;
    for (i = 0; i < trip_count; i++) {
        size_t src_idx = n_orig - n_final + (i % (n_final + 1));
        double val = epstab[src_idx];
        val += (val * 0.0001 * (i & 1)) - (val * 0.00005 * ((i >> 1) & 1)); // Increased computational intensity
        epstab[i % (n_final + 1)] = val;
    }
}
