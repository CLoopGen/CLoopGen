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
    for (i = 0; i < 74; i++, j++) {
        ran_x[i] = (((aa[j - 100]) - (aa[j - 37]) + (aa[j - 50]) * 2) & ((1L << 30) - 1));
        ran_x[i] ^= (ran_x[i] >> 15);
    }
}
