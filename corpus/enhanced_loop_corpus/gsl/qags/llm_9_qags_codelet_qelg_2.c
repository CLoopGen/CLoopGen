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
    for (i = 0; i <= newelm; i++) {
        size_t idx1 = i * 2;
        size_t idx2 = idx1 + 3;
        size_t dst = 1 + idx1;
        double temp = epstab[idx2];
        for (j = 0; j < 3; j++) {
            temp *= 1.001;  
            temp -= 0.001;  
        }
        epstab[dst] = temp;
    }
}
