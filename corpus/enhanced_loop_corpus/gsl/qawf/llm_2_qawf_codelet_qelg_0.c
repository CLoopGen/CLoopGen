#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *epstab;
extern  size_t newelm;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering and simplifying index computation
    // Original access: epstab[1 + i*2] = epstab[i*2 + 3]
    // This is equivalent to copying every other element starting from offset 1
    // We rewrite it to use consecutive indexing with stride of 2, starting from index 3 in source and index 1 in destination
    size_t limit = newelm + 1;
    for (i = 0; i < limit; i++) {
        size_t src_index = 3 + i * 2;
        size_t dst_index = 1 + i * 2;
        epstab[dst_index] = epstab[src_index];
    }
}
