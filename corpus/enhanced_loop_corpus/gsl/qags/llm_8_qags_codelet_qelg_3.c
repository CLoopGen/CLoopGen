#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *epstab;
extern  size_t newelm;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i <= newelm + 2; i += 2) {
        epstab[i] = epstab[i + 2];
        epstab[i + 1] = epstab[i + 3]; // Double the operations per iteration
    }
}
