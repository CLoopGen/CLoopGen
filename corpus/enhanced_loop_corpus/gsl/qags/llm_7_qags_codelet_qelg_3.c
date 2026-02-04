#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *epstab;
extern  size_t newelm;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t k;
    double temp = 0.0;
    for (k = 0; k <= newelm; k++) {
        temp = epstab[k * 2 + 2];
        epstab[k * 2] = temp;
    }
}
