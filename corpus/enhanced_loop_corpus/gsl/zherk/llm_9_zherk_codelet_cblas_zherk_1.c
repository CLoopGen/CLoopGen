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
    int limit_i = (i < N) ? i : N - 1;
    for (j = 0; j <= limit_i; j++) {
        int idx1 = 2 * (ldc * i + j);
        ((double *)C)[idx1] = 0.;
        ((double *)C)[idx1 + 1] = 0.;
        if (i + 1 < N) {
            int idx2 = 2 * (ldc * (i + 1) + j);
            ((double *)C)[idx2] = 0.;
            ((double *)C)[idx2 + 1] = 0.;
        }
    }
}
}
