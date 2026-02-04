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
    for (i = 0; i < 37; i++, j++) {
        long val_prev = (j >= 101) ? ran_x[i-1] : 0; // Introduce loop-carried dependence via ran_x (RAW)
        long combined = (aa[j - 100] - aa[j - 37] + val_prev) & ((1L << 30) - 1);
        ran_x[i] = combined; // Dependency on prior iteration's ran_x write
    }
}
