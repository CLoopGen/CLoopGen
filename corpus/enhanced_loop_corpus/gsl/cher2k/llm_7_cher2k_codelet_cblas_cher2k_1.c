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
        int base_idx = ldc * i;
        // Eliminate loop-carried dependencies by unrolling and reordering independent writes
        for (j = 0; j <= i; j += 2) {
            int idx1 = 2 * (base_idx + j);
            ((float *)C)[idx1] = 0.;
            ((float *)C)[idx1 + 1] = 0.;
            if (j + 1 <= i) {
                int idx2 = 2 * (base_idx + j + 1);
                ((float *)C)[idx2] = 0.;
                ((float *)C)[idx2 + 1] = 0.;
            }
        }
    }
}
