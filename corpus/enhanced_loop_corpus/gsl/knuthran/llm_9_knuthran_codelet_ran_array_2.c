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
    for (i = 0; i < 18; i++, j += 2) {
        unsigned long diff1 = (aa[j - 100] - aa[j - 37]) & ((1L << 30) - 1);
        unsigned long diff2 = (aa[j - 99] - aa[j - 36]) & ((1L << 30) - 1);
        ran_x[i] = (diff1 + diff2) >> 1;
    }
}
