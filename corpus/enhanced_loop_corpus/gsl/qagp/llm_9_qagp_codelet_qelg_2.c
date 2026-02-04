#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *epstab;
extern  size_t newelm;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= newelm * 2; i++) {
        size_t idx = i / 2;
        if (i % 2 == 0 && idx <= newelm) {
            epstab[idx * 2] = epstab[idx * 2 + 2];
        }
    }
}
