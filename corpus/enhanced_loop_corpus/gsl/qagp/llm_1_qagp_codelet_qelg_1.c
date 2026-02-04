#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *epstab;
extern  size_t newelm;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= newelm; i += 2) {
        if (i <= newelm) {
            epstab[1 + i * 2] = epstab[i * 2 + 3];
        }
        if ((i + 1) <= newelm) {
            epstab[1 + (i + 1) * 2] = epstab[(i + 1) * 2 + 3];
        }
    }
}
