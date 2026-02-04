#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *epstab;
extern  size_t newelm;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling and accessing adjacent elements together
    size_t limit = newelm + 1;
    for (i = 0; i < limit; i += 2) {
        size_t idx1 = i * 2;
        epstab[1 + idx1] = epstab[idx1 + 3];
        if (i + 1 <= newelm) {
            size_t idx2 = (i + 1) * 2;
            epstab[1 + idx2] = epstab[idx2 + 3];
        }
    }
}
