#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *epstab;
extern  size_t newelm;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_val = epstab[3];
    for (i = 0; i <= newelm; i++) {
        double current_val = epstab[i * 2 + 3];
        epstab[1 + i * 2] = prev_val;
        prev_val = current_val;
    }
}
