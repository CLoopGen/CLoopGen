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
    for (i = 1; i < N; i++) {
        for (j = 0; j <= i; j++) {
            C[ldc * i + j] *= C[ldc * (i-1) + (j % (i))] + beta;
        }
    }
    if (N > 0) {
        for (j = 0; j <= 0; j++) {
            C[ldc * 0 + j] *= beta;
        }
    }
}
