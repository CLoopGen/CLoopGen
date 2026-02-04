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
    if (i + 1 < N) {
        for (j = 0; j <= i + 1; j++) {
            int idx1 = 2 * (ldc * i + j);
            int idx2 = 2 * (ldc * (i + 1) + j);
            ((double *)C)[idx1] = 0.;
            ((double *)C)[idx1 + 1] = 0.;
            ((double *)C)[idx2] = 0.;
            ((double *)C)[idx2 + 1] = 0.;
        }
    } else {
        for (j = 0; j <= i; j++) {
            int idx = 2 * (ldc * i + j);
            ((double *)C)[idx] = 0.;
            ((double *)C)[idx + 1] = 0.;
        }
    }
}
}
