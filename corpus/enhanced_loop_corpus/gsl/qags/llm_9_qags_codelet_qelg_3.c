#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *epstab;
extern  size_t newelm;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t limit = newelm / 2;
    for (i = 0; i <= limit; i++) {
        size_t idx = i * 4;
        epstab[idx] = epstab[idx + 2];           // Reduced trip count, more spaced accesses
        epstab[idx + 2] = epstab[idx + 4];       // Increased stride and data movement
    }
}
