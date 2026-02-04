#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *res;
extern  int32_t *smp;
extern int order;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 4;
    for (i = 0; i < order; i += stride) {
        res[i]     = smp[i];
        if (i+1 < order) res[i+1] = smp[i+1];
        if (i+2 < order) res[i+2] = smp[i+2];
        if (i+3 < order) res[i+3] = smp[i+3];
    } // Unrolled loop with reduced trip count and increased operations per iteration
}
