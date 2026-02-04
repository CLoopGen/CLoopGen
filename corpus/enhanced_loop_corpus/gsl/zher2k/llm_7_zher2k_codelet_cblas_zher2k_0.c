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
    double *row_start = &(((double *)C)[2 * ldc * i]);
    for (j = i; j < N; j++) {
        int offset = 2 * j;
        row_start[offset]     = 0.;
        row_start[offset + 1] = 0.;
    }
}
// Eliminate redundant computation of base address in inner loop (lifted invariant)
// Introduces loop-invariant code motion and removes repeated index calculation,
// altering data access pattern while preserving WAW semantics but reducing address recalculation (no loop-carried dependency introduced).
}
