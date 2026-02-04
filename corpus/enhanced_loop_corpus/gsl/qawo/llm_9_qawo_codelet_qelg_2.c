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
    for (i = 0; i <= newelm * 2; i++) {
        size_t idx = i / 2;
        epstab[1 + idx * 2] = epstab[idx * 2 + 3] + epstab[idx * 2 + 4] - epstab[idx * 2 + 2];
    }
}
