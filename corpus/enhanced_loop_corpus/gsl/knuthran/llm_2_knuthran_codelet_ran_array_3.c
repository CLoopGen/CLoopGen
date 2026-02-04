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
    // Variant 1: Strided memory access with increased stride on both arrays
    for (; i < 100; i++, j += 2) {
        ran_x[i] = (((aa[j - 100 + (i % 3)])) - (ran_x[i - 37])) & ((1L << 30) - 1);
    }
}
