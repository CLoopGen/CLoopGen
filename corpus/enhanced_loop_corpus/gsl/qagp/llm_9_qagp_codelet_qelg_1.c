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
    for (i = 0; i <= newelm * 2; i++) {
        offset = i / 2;
        if (i % 2 == 0 && offset <= newelm) {
            epstab[1 + offset * 2] = epstab[offset * 2 + 3];
        }
    }
}
