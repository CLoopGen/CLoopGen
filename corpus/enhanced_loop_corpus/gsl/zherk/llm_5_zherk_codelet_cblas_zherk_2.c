#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double beta;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    int diag_offset = 2 * (ldc * i + i);
    (((double *)C)[diag_offset]) *= beta;
    (((double *)C)[diag_offset + 1]) = 0;

    if (i + 1 < N) {
        for (j = i + 1; j < N; j++) {
            int off = 2 * (ldc * i + j);
            (((double *)C)[off]) *= beta;
            (((double *)C)[off + 1]) *= beta;
        }
    }
}
}
