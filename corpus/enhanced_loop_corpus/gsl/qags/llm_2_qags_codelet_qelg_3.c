#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *epstab;
extern  size_t newelm;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 2;
    for (i = 0; i <= newelm; i += step) {
        if (i <= newelm - step + 1) {
            epstab[i * 2] = epstab[i * 2 + 2];
        }
    }
}
