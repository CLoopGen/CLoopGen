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
    int idx;
    for (i = 0; i < N; i++) {
        for (j = 0; j < i; j++) {
            idx = 2 * (ldc * i + j);
            C_ptr[idx] *= beta;
            C_ptr[idx + 1] *= beta;
        }
        idx = 2 * (ldc * i + i);
        C_ptr[idx] *= beta;
        C_ptr[idx + 1] = 0.0f;
    }
}
