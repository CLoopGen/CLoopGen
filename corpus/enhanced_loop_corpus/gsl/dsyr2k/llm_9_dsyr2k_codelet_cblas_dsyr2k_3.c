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
    for (j = 0; j <= i; j += 2) {
        if (i < N && j <= i) {
            C[ldc * i + j] *= beta;
        }
        if ((i+1) < N && j <= (i+1)) {
            C[ldc * (i+1) + j] *= beta;
        }
        if (i < N && (j+1) <= i) {
            C[ldc * i + (j+1)] *= beta;
        }
        if ((i+1) < N && (j+1) <= (i+1)) {
            C[ldc * (i+1) + (j+1)] *= beta;
        }
    }
}
}
