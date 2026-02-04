#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double beta;
extern double *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) {
    for (j = i; j < N; j++) {
        if (i + 1 < N) {
            C[ldc * i + j] *= beta;
            C[ldc * (i + 1) + j] *= beta; // Unrolled outer loop: process two rows per iteration
        } else {
            C[ldc * i + j] *= beta;
        }
    }
}
}
