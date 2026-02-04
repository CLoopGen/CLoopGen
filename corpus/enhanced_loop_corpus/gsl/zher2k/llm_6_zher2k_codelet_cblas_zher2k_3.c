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
    int idx;
    for (i = 0; i < N; i++) {
        idx = 2 * (ldc * i + i);
        c_ptr[idx] *= beta;
        c_ptr[idx + 1] = 0.0;
        for (j = 0; j < i; j++) {
            idx = 2 * (ldc * i + j);
            c_ptr[idx] *= beta;
            c_ptr[idx + 1] *= beta;
        }
    }
}
