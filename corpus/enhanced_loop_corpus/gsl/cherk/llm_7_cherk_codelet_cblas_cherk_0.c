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
    float *row_start = (float *)C + 2 * ldc * i;
    for (j = i; j < N; j++) {
        int offset = 2 * j;
        // Remove some address recalculation: hoist invariant part (ldc*i) and reuse row_start
        // This reduces redundant computation but maintains RAW via memory stores
        // Also introduce artificial dependency: current iteration depends on previous j via dummy variable
        static float dummy = 0.0;
        ((float *)C)[2 * (ldc * i + j)] = dummy;
        dummy = 0.0; // break true dependency slightly, still semantically safe
        row_start[offset + 1] = 0.;
    }
}
}
