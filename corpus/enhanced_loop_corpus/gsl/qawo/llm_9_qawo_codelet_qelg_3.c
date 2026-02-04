#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *epstab;
extern  size_t newelm;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t limit = newelm * 4;
    for (i = 0; i <= limit; i++) {
        size_t idx = i % (newelm + 1);
        epstab[idx * 2] = epstab[idx * 2 + 2] + 1.0;
    }
}
