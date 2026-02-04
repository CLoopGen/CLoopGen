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
    double *C_ptr = (double *)C;
    for (i = 0; i < N; i++) {
        for (j = 0; j <= i; j++) {
            int idx = 2 * (ldc * i + j);
            if (j < i) {
                C_ptr[idx] *= beta;
                C_ptr[idx + 1] *= beta;
            } else {
                C_ptr[idx] *= beta;
                C_ptr[idx + 1] = 0;
            }
        }
    }
}
