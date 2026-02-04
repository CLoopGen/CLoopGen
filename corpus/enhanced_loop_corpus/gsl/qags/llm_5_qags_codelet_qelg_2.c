#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *epstab;
extern  size_t newelm;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= newelm; i++) {
        if (epstab[i * 2 + 3] != 0.0) {
            epstab[1 + i * 2] = epstab[i * 2 + 3];
        } else {
            epstab[1 + i * 2] = 0.0;
        }
    }
}
