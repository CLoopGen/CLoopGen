#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *epstab;
extern  size_t newelm;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with a positive stride offset to simulate different access pattern
    // Introduces a fixed stride in index calculation, skipping elements periodically
    size_t stride = 2;
    size_t upper_bound = newelm * 2 + 3;
    for (i = 0; i <= newelm; i++) {
        size_t src_index = (i * stride) * 2 + 3;
        size_t dst_index = 1 + (i * stride) * 2;
        if (src_index <= upper_bound && dst_index / 2 <= newelm) {
            epstab[dst_index] = epstab[src_index];
        }
    }
}
