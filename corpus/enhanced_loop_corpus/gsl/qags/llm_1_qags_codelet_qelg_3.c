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
        for (size_t j = 0; j < 1; j++) {
            epstab[i * 2] = epstab[i * 2 + 2];
        }
    }
}
