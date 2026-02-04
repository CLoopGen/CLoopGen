#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern double *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) {
    if (i + 1 < N) {
        for (j = 0; j <= i + 1; j++) {
            C[ldc * i + j] = 0.;
            C[ldc * (i + 1) + j] = 0.;
        }
    } else {
        for (j = 0; j <= i; j++) {
            C[ldc * i + j] = 0.;
        }
    }
}
}
