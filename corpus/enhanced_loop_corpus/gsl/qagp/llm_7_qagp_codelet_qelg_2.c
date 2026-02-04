#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *epstab;
extern  size_t newelm;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t offset;
    double temp;
    for (offset = 0; offset <= newelm; offset++) {
        temp = epstab[offset * 2 + 2];
        epstab[offset * 2] = temp;
    }
}
