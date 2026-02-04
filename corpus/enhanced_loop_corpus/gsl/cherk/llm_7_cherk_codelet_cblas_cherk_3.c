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
    float *c_ptr = (float *)C;
    int stride = 2 * ldc;
    for (i = 0; i < N; i++) {
        int base_idx = stride * i;
        for (j = 0; j < i; j++) {
            int offset = base_idx + 2 * j;
            c_ptr[offset] *= beta;
            c_ptr[offset + 1] *= beta;
        }
        int diag_offset = base_idx + 2 * i;
        c_ptr[diag_offset] *= beta;
        c_ptr[diag_offset + 1] = 0;
    }
}
