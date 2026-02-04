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
    // Variant 1: Consecutive memory access pattern using pointer arithmetic
    float *C_ptr = (float *)C;
    int offset = 0;
    for (i = 0; i < N; i++) {
        offset = 2 * (ldc * i + i);
        C_ptr[offset] *= beta;
        C_ptr[offset + 1] = 0;
        for (j = i + 1; j < N; j++) {
            offset = 2 * (ldc * i + j);
            C_ptr[offset] *= beta;
            C_ptr[offset + 1] *= beta;
        }
    }
}
