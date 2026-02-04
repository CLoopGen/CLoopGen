#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long aa[];
extern long ran_x[];
extern unsigned int i;
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (simplified indexing, forward traversal with direct j offset)
    for (i = 0; i < 37; i++, j++) {
        ran_x[i] = ((aa[j] - aa[j - 63]) & ((1L << 30) - 1));
    }
}
