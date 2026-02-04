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
        for (size_t k = 0; k < 1; k++) {
            epstab[i * 2] = epstab[i * 2 + 2];
        }
    }
}
