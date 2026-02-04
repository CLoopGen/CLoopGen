#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float beta;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *C_ptr = (float *)C;
    int idx1, idx2;
    for (i = 0; i < N; i++) {
        idx1 = 2 * ldc * i;
        for (j = 0; j <= i; j++) {
            idx2 = idx1 + 2 * j;
            if (j < i) {
                C_ptr[idx2] *= beta;
                C_ptr[idx2 + 1] *= beta;
            } else {
                C_ptr[idx2] *= beta;
                C_ptr[idx2 + 1] = 0.0f;
            }
        }
    }
}
