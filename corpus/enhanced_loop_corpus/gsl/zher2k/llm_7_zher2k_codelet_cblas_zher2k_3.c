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
    double *c_ptr = (double *)C;
    int idx1, idx2;
    for (i = 0; i < N; i++) {
        for (j = 0; j < i; j++) {
            idx1 = 2 * (ldc * i + j);
            idx2 = 2 * (ldc * j + i);
            c_ptr[idx1] *= beta;
            c_ptr[idx1 + 1] *= beta;
            c_ptr[idx2] *= beta;
            c_ptr[idx2 + 1] *= beta;
        }
        idx1 = 2 * (ldc * i + i);
        c_ptr[idx1] *= beta;
        c_ptr[idx1 + 1] = 0.0;
    }
}
