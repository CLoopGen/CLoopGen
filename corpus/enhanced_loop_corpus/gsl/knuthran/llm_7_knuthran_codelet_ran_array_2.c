#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long aa[];
extern unsigned long ran_x[];
extern unsigned int i;
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long prev_val = 0;
    for (i = 0; i < 37; i++, j++) {
        unsigned long diff = (aa[j - 100] - aa[j - 37]) & ((1UL << 30) - 1);
        ran_x[i] = diff ^ prev_val; // Introduce WAW and RAW dependency: each write depends on prior write via prev_val
        prev_val = diff;
    }
}
