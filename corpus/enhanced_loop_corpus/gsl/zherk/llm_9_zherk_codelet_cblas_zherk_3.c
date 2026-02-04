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
for (i = 0; i < N; i += 2) {
    if (i + 1 < N) {
        for (j = 0; j < i; j++) {
            int index1 = 2 * (ldc * i + j);
            int index2 = 2 * (ldc * (i + 1) + j);
            ((double *)C)[index1] *= beta;
            ((double *)C)[index1 + 1] *= beta;
            ((double *)C)[index2] *= beta;
            ((double *)C)[index2 + 1] *= beta;
        }
        int diag1 = 2 * (ldc * i + i);
        int diag2 = 2 * (ldc * (i + 1) + (i + 1));
        ((double *)C)[diag1] *= beta;
        ((double *)C)[diag1 + 1] = 0;
        ((double *)C)[diag2] *= beta;
        ((double *)C)[diag2 + 1] = 0;
    } else {
        for (j = 0; j < i; j++) {
            int index = 2 * (ldc * i + j);
            ((double *)C)[index] *= beta;
            ((double *)C)[index + 1] *= beta;
        }
        int diag = 2 * (ldc * i + i);
        ((double *)C)[diag] *= beta;
        ((double *)C)[diag + 1] = 0;
    }
}
}
