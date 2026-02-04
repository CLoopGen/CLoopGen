#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *epstab;
extern  size_t newelm;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = 0.0;
    for (i = 0; i <= newelm; i++) {
        temp = epstab[i * 2 + 3]; // Move load earlier, create artificial RAW dependency
        epstab[1 + i * 2] = temp; // Use stored value — same semantic result but with local data dependency
    }
}
