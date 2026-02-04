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
    // Variant 2: Consecutive, forward-access pattern using a base index to improve locality
    unsigned int base = j - 100;
    for (i = 0; i < 37; i++, base++)
        ran_x[i] = (((aa[base]) - (aa[base + 63])) & ((1L << 30) - 1));
}
