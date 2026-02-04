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
    // Variant 2: Strided memory access with precomputed stride and indirect indexing
    float *c_ptr = (float *)C;
    int stride = 2 * ldc;
    for (i = 0; i < N; i++) {
        int offset = 2 * i;
        c_ptr[stride * i + offset] *= beta;
        c_ptr[stride * i + offset + 1] = 0.0f;
        for (j = i + 1; j < N; j++) {
            int flat_idx = stride * i + 2 * j;
            c_ptr[flat_idx] *= beta;
            c_ptr[flat_idx + 1] *= beta;
        }
    }
}
