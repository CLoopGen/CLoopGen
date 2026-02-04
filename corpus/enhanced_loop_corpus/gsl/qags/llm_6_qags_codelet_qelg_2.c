#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *epstab;
extern  size_t newelm;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_index;
    for (i = 0; i <= newelm; i++) {
        temp_index = i * 2;
        epstab[1 + temp_index] = epstab[temp_index + 3];
    }
}
