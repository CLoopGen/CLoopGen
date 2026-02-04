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
    // Variant 1: Strided memory access with increased stride on aa[]
    for (i = 0; i < 37; i++, j++)
        ran_x[i] = (((aa[j - 100 + 2*i]) - (aa[j - 37 + 2*i])) & ((1L << 30) - 1));
}
