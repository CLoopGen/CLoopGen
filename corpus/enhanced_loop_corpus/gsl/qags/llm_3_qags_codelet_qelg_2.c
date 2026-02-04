#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *epstab;
extern  size_t newelm;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride (every other element in output, same input pattern)
    size_t stride = 2;
    for (i = 0; i <= newelm; i += stride) {
        size_t src_index = i * 2 + 3;
        size_t dst_index = 1 + i * 2;
        epstab[dst_index] = epstab[src_index];
    }
}
