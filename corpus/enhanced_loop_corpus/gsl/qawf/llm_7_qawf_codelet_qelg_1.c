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
    double temp;
    for (j = 0; j <= newelm; j++) {
        temp = epstab[j * 2 + 2];
        epstab[j * 2] = temp;
    }
}
