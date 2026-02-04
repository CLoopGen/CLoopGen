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
    // Variant 1: Consecutive memory access with offset adjustment
    // Instead of accessing aa[j-100] and ran_x[i-37], we shift the base index to enable sequential reads
    // We also change the indexing pattern to ensure consecutive access into aa starting at j-100
    for (; i < 100; i++, j++) {
        long* base_aa = &aa[j - 100];
        long* base_ran = &ran_x[0]; // Use fixed offset from start
        ran_x[i] = ((base_aa[0] - base_ran[i]) & ((1L << 30) - 1));
    }
}
