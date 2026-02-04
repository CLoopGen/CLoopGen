#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    int base_index = ldc * i;
    // Eliminate redundant computations and reorganize to remove some WAW hazards via unrolling-like pattern
    for (j = 0; j <= i; j += 2) {
        int index1 = 2 * (base_index + j);
        ((double *)C)[index1] = 0.;
        ((double *)C)[index1 + 1] = 0.;
        if (j + 1 <= i) {
            int index2 = 2 * (base_index + j + 1);
            ((double *)C)[index2] = 0.;
            ((double *)C)[index2 + 1] = 0.;
        }
    }
    // Introduced WAR by ensuring forward progress in memory stores with non-overlapping assumption
}
}
