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
    for (j = i; j < N; j++) {
        int idx1 = 2 * (ldc * i + j);
        int idx2 = idx1 + 1;
        ((double *)C)[idx1] = 0.;
        ((double *)C)[idx2] = 0.;
        ((double *)C)[idx1] += i * j;
        ((double *)C)[idx2] -= i + j;
    }
}
}
