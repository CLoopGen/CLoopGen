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
    // Variant 1: Consecutive memory access by unrolling and accessing adjacent elements together
    for (i = 0; i < N; i++) {
        int base_idx = 2 * ldc * i;
        for (j = 0; j <= i; j++) {
            int offset = 2 * j;
            ((double *)C)[base_idx + offset]     = 0.;
            ((double *)C)[base_idx + offset + 1] = 0.;
        }
    }
}
