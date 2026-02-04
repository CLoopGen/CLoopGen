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
for (i = 0; i < N; i += 2) {
    int limit = (i + 1 < N) ? N : i;
    for (j = i; j < N; j++) {
        int base_idx1 = ldc * i + j;
        int base_idx2 = ldc * (i + 1) + j;
        ((double *)C)[2 * base_idx1] = 0.;
        ((double *)C)[2 * base_idx1 + 1] = 0.;
        if (i + 1 < N) {
            ((double *)C)[2 * base_idx2] = 0.;
            ((double *)C)[2 * base_idx2 + 1] = 0.;
        }
    }
}
}
