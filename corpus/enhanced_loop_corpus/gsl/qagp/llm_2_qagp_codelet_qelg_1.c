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
    // Instead of strided access (every 2nd element), we process elements in consecutive order
    // We adjust indexing to write to contiguous locations, improving cache locality
    size_t limit = newelm + 1;
    for (i = 0; i < limit; i++) {
        epstab[i] = epstab[i + 2];
    }
}
