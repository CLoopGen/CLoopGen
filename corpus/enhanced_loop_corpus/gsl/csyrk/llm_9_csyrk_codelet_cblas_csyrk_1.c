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
    int base_idx_i1 = ldc * i;
    int base_idx_i2 = ldc * (i + 1);
    for (j = 0; j <= i; j++) {
        int idx1 = 2 * (base_idx_i1 + j);
        ((float *)C)[idx1] = 0.;
        ((float *)C)[idx1 + 1] = 0.;
    }
    if (i + 1 < N) {
        for (j = 0; j <= i + 1; j++) {
            int idx2 = 2 * (base_idx_i2 + j);
            ((float *)C)[idx2] = 0.;
            ((float *)C)[idx2 + 1] = 0.;
        }
    }
}
}
